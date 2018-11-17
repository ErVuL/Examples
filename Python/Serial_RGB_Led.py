#!/usr/bin/env python3
import serial

#serial init
#serial_ = serial.Serial('/dev/ttyACM0', 9600)

#input color
red = bytes([int(input("RED = "))])
green = bytes([int(input("GREEN = "))])
blue = bytes([int(input("BLUE = "))])

#encode
ser_message = b'R' + red + b'G' + green + b'B' + blue

#serial communication
#serial_.write(message.encode())
#print(serial_.readline())

#decode for example
L1 = bytes([ser_message[0]]).decode('utf8')
V1 = ser_message[1]
L2 = bytes([ser_message[2]]).decode('utf8')
V2 = ser_message[3]
L3 = bytes([ser_message[4]]).decode('utf8')
V3 = ser_message[5]
print(L1,V1,L2,V2,L3,V3)

#serial close
#serial.close()

