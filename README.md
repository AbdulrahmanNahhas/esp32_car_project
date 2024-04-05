## ESP32 Car Controller with Mobile App (Bluetooth)   

This is my first project using `ESP-IDF` and `ESP32`, the project aims to develop a simple control system for a car using an ESP32 microcontroller. The car will be controlled remotely via Bluetooth using the mobile application.

## Hardware Components:

1. ESP32 Board
2. L298N Motor Driver
3. **4** DC Motors
4. **3** Lithium ion batteries (3.7v 1200mah)
5. Ultrasonic Sensor
6. GPS Module (*I used NEO-6MV2*)
8. Mobile Device

## Software:

-   ESP-IDF (development framework for ESP32)
-   Mobile App (developed using ~~react-native~~ **Thunkable**)

## Project Structure:

The `components` directory houses the project's core functionalities:

-   `controller`: Contains logic for controlling the car's movement.
-   `DSP`: Digital Sensor Process (DSP) Handles motor driver control and data sending/reading.
-   `Nimble`: Manages Bluetooth Low Energy communication with the mobile app.
-   `ultrasonic`: Handles communication with the ultrasonic sensor for obstacle detection.
-   `GPS`: Coming Soon...

