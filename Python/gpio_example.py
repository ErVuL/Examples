import RPi.GPIO as GPIO
import time




GPIO.setmode(GPIO.BOARD)

GPIO.setup(3, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(5, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(7, GPIO.OUT, initial=GPIO.LOW)

for ii in range(3):
	GPIO.output(3,GPIO.HIGH)
	time.sleep(0.5)
	GPIO.output(3,GPIO.LOW)
	GPIO.output(5,GPIO.HIGH)
	time.sleep(0.5)
	GPIO.output(5,GPIO.LOW)
	GPIO.output(7,GPIO.HIGH)
	time.sleep(0.5)
	GPIO.output(7,GPIO.LOW)

GPIO.output(3,GPIO.LOW)
GPIO.output(5,GPIO.LOW)

GPIO.cleanup()
