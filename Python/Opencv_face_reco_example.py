
import numpy as np
import cv2
from picamera.array import PiRGBArray
from picamera import PiCamera
import time

# Camera init:
camera = PiCamera()
camera.resolution = (480, 320)
camera.framerate = 32
camera.vflip = True
rawCapture = PiRGBArray(camera, size=(480, 320))
time.sleep(0.1) # allow the camera to warmup

# Cascade classifier file:
face_cascade = cv2.CascadeClassifier('/home/pi/opencv-3.2.0/data/haarcascades/haarcascade_frontalface_default.xml')

# capture frames from the camera:
for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
    frame_array = frame.array # Format to numpy array
    gray = cv2.cvtColor(frame_array, cv2.COLOR_BGR2GRAY) # Only gray color extraction
    faces = face_cascade.detectMultiScale(gray, 1.3, 5) # ??
    # Plot rectangles:
    for (x,y,w,h) in faces:
        cv2.rectangle(frame_array,(x,y),(x+w,y+h),(255,0,0),2)
    # Display the resulting frame:
    cv2.imshow('Video', frame_array)
    rawCapture.truncate(0) # clean for next frame
    if cv2.waitKey(1) & 0xFF == ord('q'): # exit typing 'q'
        break
# Release the capture:
cv2.destroyAllWindows()
