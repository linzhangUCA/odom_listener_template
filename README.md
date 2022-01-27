# Assignment 2 - Monitor Robot Velocity
Still remember what [odometry](https://navigation.ros.org/setup_guides/odom/setup_odom.html) is? In this assignment, connect encoders to your Arduino Nano Every and monitor the motor speed. You need to compute and display your robot odometry (velocity) in real time. **Note: controlling your motor speed is not required, you can use a fixed or random PWM duty cycle to start your robot.**

## Requirement
1. (10%) Use RPi to read motor speed from Arduino.
3. (15%) Use correct equations to calculate wheel speed.
4. (20%) Use correct equations to calculate linear wheel speed.
5. (45%) Use correct equations to calculate robot odometry/velocity.
6. (10%) Display/Print odometry in real time.

## Helpful Resources
- [Communication between RPi and Arduino Tutorial](https://roboticsbackend.com/raspberry-pi-arduino-serial-communication/)
- Arduino code for monitoring motor speed can be found in `sketch_twoMotorSpeed.ino`.
