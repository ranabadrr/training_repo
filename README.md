# **Motor Speed Control Using PID and Exponential Smoothing Filter**
## **Overview**
This project is designed to control the speed of a motor using a PID (Proportional-Integral-Derivative) controller and an Exponential Smoothing Filter to process input data from an encoder. The encoder data is read from an analog pin and smoothed using the filter before feeding it into the PID controller. The PID controller then computes the necessary output to drive the motor at a desired speed, adjusting its response based on feedback from the encoder.

## **Features**
- PID Controller: Used to maintain the motor speed at a desired setpoint.
- Exponential Smoothing Filter: Smooths out the noise in the encoder readings before feeding them to the PID controller.
- Encoder Input: Reads analog input values from the encoder (simulated using analogRead).
- Motor Output: Uses PWM to control the motor's speed via the analogWrite function.

## **Components**
- Arduino: The code is written for an Arduino board (e.g., Arduino Uno).
- Motor: A motor connected to the PWM pin (pin 11 in this case).
- Encoder: An encoder connected to analog pin A0 to measure motor speed.
