# Super Ultra 1

Super Ultra 1 is an autonomous robot designed to navigate and avoid obstacles using ultrasonic distance measurement and motor control. The robot maneuvers around obstacles with a series of predefined turns when obstacles are detected in its path.

## Table of Contents
- [Overview](#overview)
- [Components](#components)
- [Pin Configuration and Connections](#pin-configuration-and-connections)
- [Circuit Diagram](#circuit-diagram)
- [Power Supply](#power-supply)
- [Software and Libraries](#software-and-libraries)
- [Algorithm](#algorithm)
- [Contributing](#contributing)
- [License](#license)

## Overview

Super Ultra 1 uses an ultrasonic sensor to detect obstacles and control motor movements through an Arduino microcontroller. It follows a simple algorithm to measure distances and avoid collisions.

## Components

- **Arduino Board**: Microcontroller for managing sensors and motors.
- **DC Motors**: Two motors for robot movement.
- **Ultrasonic Sensor**: Measures distance to detect obstacles.
- **Motor Driver**: Controls the direction and speed of the DC motors.
- **Power Supply**: Provides power to the robot and its components.

## Pin Configuration and Connections

### Arduino Pins

- **Motors**:
  - **Motor 1**:
    - Motor 1 Pin 1: `7`
    - Motor 1 Pin 2: `8`
  - **Motor 2**:
    - Motor 2 Pin 1: `9`
    - Motor 2 Pin 2: `10`

- **Ultrasonic Sensor**:
  - **Trigger Pin**: `3`
  - **Echo Pin**: `2`

### Pin Diagram

Below is the pin configuration for the Super Ultra 1 robot:

| Component          | Arduino Pin |
|--------------------|-------------|
| Motor 1 Pin 1      | 7           |
| Motor 1 Pin 2      | 8           |
| Motor 2 Pin 1      | 9           |
| Motor 2 Pin 2      | 10          |
| Ultrasonic Trigger | 3           |
| Ultrasonic Echo    | 2           |


## Power Supply

- **Arduino**: Powered via USB or an external battery pack (7-12V).
- **Motors**: Powered through the motor driver, which should be connected to an appropriate power source (check the motor driver specifications for recommended voltage).

## Software and Libraries

### Arduino IDE

- **Download and Install**: [Arduino IDE](https://www.arduino.cc/en/software)
- **Board**: Select your Arduino board (e.g., Arduino Uno) from the Tools menu.

### Libraries

- **NewPing**: Library for handling ultrasonic distance measurement.
  - **Installation**: In the Arduino IDE, go to `Sketch` > `Include Library` > `Manage Libraries`, search for "NewPing", and install it.
