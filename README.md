# Air Quality Monitor for the Kaiser Innovation Program


As part of the Kaiser Innovation Program, my team of fellows and I developed an air quality monitor using an Arduino and a dust sensor. This project was developed during the 2020 Californian wildfire season after my colleagues and I were mandated to wear masks to school from dangerous levels of air quality. Understanding the gravity of the situation, we developed this monitor as a cost-effective alternative to be used in homes. The monitor measures the concentration of particles in the air and displays the air quality level on an LCD screen. The dust sensor detects the amount of particulate matter (PM) in the air, specifically PM10, which refers to particles with a diameter of 10 micrometers or smaller.

## Components Required

  - Arduino board
  - Dust sensor (capable of measuring PM10)
  - LCD display (compatible with the LiquidCrystal library)
  - Jumper wires

## Setup

  - Connect the dust sensor to the Arduino board as follows:
      - Sensor VCC to Arduino 5V pin
      - Sensor GND to Arduino GND pin
      - Sensor pin to Arduino digital pin 8

  - Connect the LCD display to the Arduino board as follows:
      - LCD RS pin to Arduino digital pin 12
      - LCD Enable pin to Arduino digital pin 11
      - LCD D4, D5, D6, and D7 pins to Arduino digital pins 5, 4, 3, and 2 respectively

  - Upload the code to the Arduino board.

## Operation

The code initializes the necessary variables and sets up the Arduino board and LCD display in the setup() function. The loop() function continuously reads the dust sensor data and updates the LCD display with the air quality information.

The main steps in the code are as follows:

  - Reading the duration of the low pulse from the dust sensor using pulseIn() function.
  - Accumulating the total time spent in the low state of the pulse using lowpulseoccupancy variable.
  - Checking if the sample time (30 seconds) has elapsed.
  - Calculating the ratio of time spent in the low state to the total sample time as a percentage.
  - Using the ratio to calculate the concentration of PM10 particles in the air using a mathematical formula.
  - Displaying the PM10 concentration on the LCD display.
  - Determining the air quality level based on the concentration and displaying a corresponding message on the LCD display.

The LCD display shows the PM10 concentration and an air quality descriptor based on the concentration. The air quality descriptors include "CLEAN," "GOOD," "ACCEPTABLE," "HEAVY," and "HAZARD." The threshold values for these descriptors may vary depending on the specific requirements and standards of air quality measurement.
Calibration

It's important to note that the mathematical formula used in the code to calculate the concentration of PM10 particles may require calibration. The coefficients in the formula might need adjustment based on the characteristics and calibration data of the specific dust sensor being used. Refer to the documentation or datasheet of the dust sensor for calibration instructions, if applicable.

## Additional Considerations

  - Ensure that the connections between the Arduino board, dust sensor, and LCD display are correct and secure.
  - Adjust the pin assignments in the code if different pins are used for the connections.
  - If using a different LCD display library or a different LCD display model, modify the code accordingly.
  - Take into account any specific requirements or specifications provided by the manufacturer of the dust sensor or LCD display.

## Disclaimer

This code provides a basic implementation of an air quality monitor. 

The provided code and README are for informational purposes only. They are intended to serve as a starting point or reference for creating an air quality monitor using an Arduino and a dust sensor.

It's important to note that working with electronics, including Arduino boards and sensors, involves inherent risks. Mishandling or incorrect usage of the components or the code provided may result in damage to the equipment or other unforeseen consequences. Before attempting to build or modify any electronic device, it is crucial to have a solid understanding of electronics and programming concepts, as well as proper safety precautions. It is recommended to consult official documentation, datasheets, and manufacturer guidelines for the specific components being used. 

The code provided may need modifications or adjustments to suit the specific hardware setup and requirements. Calibration of the dust sensor or other sensors used for accurate measurements is essential to ensure reliable results. By using the provided code and information, you acknowledge and accept these terms and release the creator of the code from any liability.
