import numpy as np
import matplotlib.pyplot as plt

from adafruit_rplidar import RPLidar

# Setup the RPLidar
PORT_NAME = '/dev/ttyUSB0'
lidar = RPLidar(None, PORT_NAME, timeout=3)
lidar.set_pwm(300)

# Write your code down
