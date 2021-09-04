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

    def turn_cw(self):
        print(self.send_rec('CW'))

    def turn_ccw(self):
        print(self.send_rec('CCW'))


class StepperUI:
    def __init__(self, parent, switch):
        self.switch = switch
        self.frame = tk.Frame(parent, width=500, height=500,
                              background="bisque")
        self.frame.pack()
        self.frame.propagate(0)
        self.on_button = tk.Button(self.frame,
                                   text="Turn 90 degrees CW",
                                   command=lambda: switch.turn_cw()).pack()
        self.on_button = tk.Button(self.frame,
                                   text="Turn 90 degrees CCW ",
                                   command=lambda: switch.turn_ccw()).pack()
        # self.frame


def main():
    with connect_arduino() as ser:
        root = tk.Tk()
        ls = LightSwitch(root, ser)

        root.geometry('400x400')
        root.resizable(0, 0)
        ui = StepperUI(root, ls)
        root.mainloop()


if __name__ == '__main__':
    main()
