#!/usr/bin/env python3
import serial
import time
from random import randint

#serial init
serial_ = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2)

for ii in range(0,100):
    #input color
    red = bytes([randint(0, 255)])
    green = bytes([randint(0, 255)])
    blue = bytes([randint(0, 255)])

    #binary encode
    serial_out =  b'R' + red + b'G' + green + b'B' + blue

    #serial communication
    serial_.write(serial_out)
    time.sleep(5)

    #decode the same message returned by the arduino
    i = 0
    message_in = []
    while serial_.in_waiting:
        serial_in = serial_.read()
        if i == 1 :
            message_in.append(int.from_bytes(serial_in, byteorder='big', signed=False))
            i = 0
        elif i == 0 :
            message_in.append(serial_in.decode('utf8'))
            i = 1

    #print message
    print(message_in)

#close serial
serial_.close()
