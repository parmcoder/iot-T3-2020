import warnings
import serial
import serial.tools.list_ports
import time
import tkinter as tk

# matching sketch at
# https://create.arduino.cc/editor/piti118/d62e2b1e-f304-48b8-99cd-0d57f0375e1c/preview


def connect_arduino(baudrate=9600):  # a more civilized way to connect to arduino
    def is_arduino(p):
        # need more comprehensive test
        return p.manufacturer is not None and 'arduino' in p.manufacturer.lower()

    ports = serial.tools.list_ports.comports()
    arduino_ports = [p for p in ports if is_arduino(p)]

    def port2str(p):
        return "%s - %s (%s)" % (p.device, p.description, p.manufacturer)

    if not arduino_ports:
        portlist = "\n".join([port2str(p) for p in ports])
        raise IOError("No Arduino found\n" + portlist)

    if len(arduino_ports) > 1:
        portlist = "\n".join([port2str(p) for p in ports])
        warnings.warn('Multiple Arduinos found - using the first\n' + portlist)

    selected_port = arduino_ports[0]
    print("Using %s" % port2str(selected_port))
    ser = serial.Serial(selected_port.device, baudrate)
    time.sleep(2)  # this is important it takes time to handshake
    return ser


class LightSwitch:
    def __init__(self, parent, ser):
        self.ser = ser
        self.redValue = '0'
        self.greenValue = '0'
        self.blueValue = '0'
        self.colorValue = 'unknown'
        self.red = tk.StringVar(parent, 'R: '+self.redValue)
        self.green = tk.StringVar(parent, 'G: '+self.redValue)
        self.blue = tk.StringVar(parent, 'B: '+self.redValue)
        self.color = tk.StringVar(parent, 'Resulting Color: '+self.colorValue)

    def get_red(self):
        return self.red

    def get_green(self):
        return self.green

    def get_blue(self):
        return self.blue

    def get_color(self):
        return self.color

    def send_rec(self, msg):
        self.ser.write((msg + "\n").encode())
        return self.ser.read_until(b"\n", 255)

    def turn_on_red(self):
        print(self.send_rec('red'))

    def turn_on_green(self):
        print(self.send_rec('green'))

    def turn_on_blue(self):
        print(self.send_rec('blue'))

    def measure_color(self):
        self.turn_on_red()
        time.sleep(2)
        self.redValue = self.send_rec('ldr').decode("utf-8")
        self.red.set('R: '+self.redValue)
        time.sleep(1)
        self.turn_on_green()
        time.sleep(2)
        self.greenValue = self.send_rec('ldr').decode("utf-8")
        self.green.set('G: '+self.greenValue)
        time.sleep(1)
        self.turn_on_blue()
        time.sleep(2)
        self.blueValue = self.send_rec('ldr').decode("utf-8")
        self.blue.set('B: '+self.blueValue)
        redInt = int(self.redValue)
        greenInt = int(self.greenValue)
        blueInt = int(self.blueValue)
        if(redInt == max(redInt, greenInt, blueInt)):
            self.colorValue = 'red'
        if(greenInt == max(redInt, greenInt, blueInt)):
            self.colorValue = 'green'
        if(blueInt == max(redInt, greenInt, blueInt)):
            self.colorValue = 'blue'
        self.color.set('Resulting Color: '+self.colorValue)





class DetectorUI:
    def __init__(self, parent, switch):
        self.switch = switch
        self.frame = tk.Frame(parent, width=500, height=500,
                              background="bisque")
        self.frame.pack()
        self.frame.propagate(0)
        self.on_button = tk.Button(self.frame,
                                   text="Detect color",
                                   command=lambda: switch.measure_color()).pack()
        self.datalabel = tk.Label(self.frame,
                                  text='Raw Values').pack()
        self.redlabel = tk.Label(self.frame,
                                 textvariable=switch.get_red(),
                                 bg='red',
                                 fg='white').pack()
        self.greenlabel = tk.Label(self.frame,
                                   textvariable=switch.get_green(),
                                   bg='green',
                                   fg='white').pack()
        self.bluelabel = tk.Label(self.frame,
                                  textvariable=switch.get_blue(),
                                  bg='blue',
                                  fg='white').pack()
        self.resultlabel = tk.Label(self.frame,
                                    textvariable=switch.get_color(),
                                    bg='white').pack()
        # self.frame


def main():
    with connect_arduino() as ser:
        root = tk.Tk()
        ls = LightSwitch(root, ser)

        root.geometry('400x400')
        root.resizable(0, 0)
        ui = DetectorUI(root, ls)
        root.mainloop()


if __name__ == '__main__':
    main()
