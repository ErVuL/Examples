import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600)

while 1 :
    message = input('commande ?')
    ser.write(message.encode())
#    print(ser.readline())
#    time.sleep(0.5)
