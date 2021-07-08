import serial
import simpleaudio as sa

wave_obj1 = sa.WaveObject.from_wave_file("MaleeSoundboard/sounds/sfx1.wav")
wave_obj2 = sa.WaveObject.from_wave_file("MaleeSoundboard/sounds/sfx2.wav")
wave_obj3 = sa.WaveObject.from_wave_file("MaleeSoundboard/sounds/sfx3.wav")
wave_obj4 = sa.WaveObject.from_wave_file("MaleeSoundboard/sounds/sfx4.wav")
wave_obj5 = sa.WaveObject.from_wave_file("MaleeSoundboard/sounds/sfx5.wav")


# matching sketch at
# https://create.arduino.cc/editor/piti118/d62e2b1e-f304-48b8-99cd-0d57f0375e1c/preview
def main():
    address = "/dev/ttyACM0"  # change this to yours!!!
    baudrate = 9600  # make sure the baud rate matches
    with serial.Serial(address, baudrate) as ser:
        while(1):
            command = ser.read_until(b"\n", 255)
            # print(command)
            if(command == b'Testing1!\n'):
                play_obj = wave_obj1.play()
                play_obj.wait_done()
            if(command == b'Testing2!\n'):
                play_obj = wave_obj2.play()
                play_obj.wait_done()
            if(command == b'Testing3!\n'):
                play_obj = wave_obj3.play()
                play_obj.wait_done()
            if(command == b'Testing4!\n'):
                play_obj = wave_obj4.play()
                play_obj.wait_done()
            if(command == b'Testing5!\n'):
                play_obj = wave_obj5.play()
                play_obj.wait_done()



if __name__ == "__main__":
    main()