import serial
import time

USB_serial = serial.Serial('/dev/ttyACM0', 9600)

while 1 :
    # message = time.strftime("%a, %d %b %Y %H:%M:%S +0000", time.gmtime())
    message = input("Saisissez une valeur entre 0 et 180 :")
    message_bytes = bytes(message,'utf-8')
    USB_serial.write(message_bytes)
    # print(ser.readline())
    #time.sleep(0.5)
