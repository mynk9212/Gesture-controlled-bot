# Gesture-controlled-bot

A gesture-controlled robotic car built with Arduino, an accelerometer, and NRF24L01 wireless transceivers. 
The system consists of a transmitter (the gesture controller) and a receiver (the robotic car).

## Components Used
- 2x Arduino Uno / Nano
- 2x NRF24L01 Wireless Transceiver Modules
- 1x Analog Accelerometer (e.g., ADXL335)
- 1x L298N Motor Driver
- DC Motors and Chassis
- Power supplies

## How It Works

### Transmitter (Gesture Controller)
The transmitter reads the X and Y axis analog values from the accelerometer to determine the tilt of the hand. Based on the tilt direction, it sends a specific character command wirelessly to the receiver:
- `F` - Forward
- `B` - Backward
- `L` - Left
- `R` - Right
- `S` - Stop

### Receiver (Robotic Car)
The receiver continuously listens for commands from the transmitter. When a command is received, it triggers the appropriate pins on the L298N motor driver to move the motors accordingly.

## Hardware Setup
- **Transmitter**: NRF24L01 CE and CSN connected to pins 7 and 8. Accelerometer X and Y connected to A0 and A1.
- **Receiver**: NRF24L01 CE and CSN connected to pins 7 and 8. L298N motor driver pins IN1, IN2, IN3, and IN4 connected to digital pins 2, 3, 4, and 5 respectively.