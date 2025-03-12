# Obstacle Detector Car with One Sensor

This repository provides the necessary instructions and code to build an Arduino-based obstacle detection car using a **single ultrasonic sensor** to avoid obstacles.

## Required Components
Here is the list of components you'll need for this project:

- **Arduino Uno**
- **Motor Driver**
- **4 DC Motors**
- **1 Ultrasonic Sensor (HC-SR04)**
- **Car Chassis and Tyres**
- **Power Supply/Battery**

## Circuit Connections
### Ultrasonic Sensor to Arduino:
- **Sensor** (Front):
  - Trig to pin 4
  - Echo to pin 7

### Motor Driver to Arduino:
- **Motor A (Front Left):**
  - IN1 to pin 5
  - IN2 to pin 6
- **Motor B (Back Left):**
  - IN3 to pin 9
  - IN4 to pin 10

### Power Supply:
- **12V** to the motor driver
- **Ground** to battery ground

## Code
The code for controlling the car based on obstacle distance detection from the ultrasonic sensor is provided in the `obstacle_detector_car.ino` file.
