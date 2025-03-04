# PluckPro - Arduino-Based Fruit Picking Robot

## Overview

PluckPro is an Arduino-powered fruit-picking robot designed to automate the process of detecting and collecting fruits using a combination of sensors, actuators, and control mechanisms. The system integrates an ultrasonic sensor, PIR sensors, servo motor, ESP8266 module, and a 1-DoF mechanical arm to detect, approach, and pluck fruits with precision. This project serves as a foundation for agricultural automation, reducing manual labor and enhancing efficiency in fruit harvesting.

## Features

-   **Autonomous fruit detection:** Uses PIR sensors to detect motion and simulate fruit presence.
-   **Distance measurement:** Utilizes an ultrasonic sensor (SR04) to determine the fruit's location.
-   **Mechanical arm control:** A servo motor operates the 1-DoF robotic arm to pluck fruits.
-   **Wireless communication:** The ESP8266 module facilitates connectivity for future IoT integration.
-   **Motorized movement:** The two-wheel chassis allows the robot to navigate towards detected fruits.
-   **Battery-powered operation:** Runs on three 18650 batteries for mobile functionality.

## Components Used

-   **Microcontroller:** Arduino Uno
-   **Sensors:**
    -   Ultrasonic Sensor (HC-SR04)
    -   Passive Infrared (PIR) Sensors (x2)
-   **Actuators:**
    -   Servo Motor (for fruit plucking)
    -   L293D Motor Driver Shield (for wheel control)
-   **Connectivity:** ESP8266 Wi-Fi Module
-   **Power:** Three 18650 Batteries
-   **Others:** Breadboard, Jumper Wires, Push Buttons (for manual simulation)

## Installation & Setup

1.  Clone this repository to your local machine:

    ```bash
    git clone [[https://github.com/yourusername/PluckPro.git]](https://github.com/Mumta-heena/PluckPro.git)
    ```

2.  Open the project in the Arduino IDE.
3.  Install necessary libraries if required:
    -   `Servo.h` (for servo motor control)
    -   `SoftwareSerial.h` (for ESP8266 communication)
4.  Connect the hardware components as per the circuit diagram.
5.  Upload the `PluckPro.ino` code to the Arduino Uno.
6.  Power the system and test its functionality.

## Code Explanation

-   `setup()`: Initializes sensors, motors, and serial communication.
-   `loop()`: Continuously monitors sensor inputs and actuates the robotic arm accordingly.
-   **Ultrasonic Sensor:** Measures distance to the fruit and determines whether the robot should proceed.
-   **PIR Sensors:** Detect motion indicating the presence of a fruit.
-   **Servo Motor:** Engages to pluck the fruit when in range.
-   **ESP8266:** Placeholder for future IoT features, enabling remote monitoring.

## Future Improvements

-   Integration of a color sensor for distinguishing ripe fruits.
-   Implementing a camera-based AI system for advanced fruit recognition.
-   Cloud connectivity for data logging and analytics.
-   Solar-powered operation for sustainable energy use.

## Contribution

Feel free to contribute by submitting pull requests, reporting issues, or suggesting enhancements.

If you find this project useful, consider giving it a ⭐ on GitHub!
