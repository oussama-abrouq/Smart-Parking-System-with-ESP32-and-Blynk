# Smart Parking System with ESP32 and Blynk
This project is a Smart Parking System developed using an ESP32 microcontroller to manage the availability of parking slots in real time. It uses infrared (IR) sensors to detect the presence of cars and controls barriers with servo motors to manage entry and exit. The system is also integrated with Blynk, enabling remote monitoring of the parking status via a mobile application.

## Features
-IR Sensors: Monitors each parking slot and entry/exit points to detect the presence of vehicles. <br/>
-Servo-Controlled Barriers: Automatically raises or lowers barriers at entry and exit points based on slot availability.<br/>
-LCD Display: Provides real-time feedback on slot availability directly on-site.<br/>
-Blynk Integration: Syncs data with the Blynk app, allowing users to view parking availability remotely.<br/>
-Automatic Slot Management: The system tracks available slots, updates them as cars enter or exit, and displays "Parking Full" when no slots are left.<br/>
## Components Used
-ESP32 Microcontroller: Acts as the brain of the system, controlling sensors, servos, and communication with Blynk.<br/>
-IR Sensors: Placed at entry/exit points and each parking slot to detect vehicles.<br/>
-Servo Motors: Controls barriers for entering and exiting vehicles.<br/>
-LCD Display: Shows available slots and other notifications.<br/>
-Blynk: IoT platform used for remote monitoring.<br/>
## How It Works
Detecting Vehicles: IR sensors detect vehicles entering and exiting the parking area.<br/>
Controlling Barriers: Based on sensor input, the system raises or lowers the barriers, allowing vehicles to enter if space is available or restricting access if the lot is full.<br/>
Updating Slot Status: The number of available slots is updated continuously and displayed on the LCD and the Blynk app.<br/>
Remote Monitoring: Users can check the parking status through the Blynk app, seeing in real time whether spaces are available.<br/>
## Installation
Set up the ESP32 microcontroller with the code in this repository.<br/>
Configure the Wi-Fi credentials and Blynk authentication token in the code.<br/>
Connect the IR sensors, servos, and LCD as specified in the wiring diagram.<br/>
Upload the code to the ESP32 and monitor parking status via the LCD or the Blynk app.<br/>
## Dependencies
-BlynkSimpleEsp32.h<br/>
-WiFi.h<br/>
-ESP32Servo.h<br/>
-LiquidCrystal_I2C.h<br/>
## Usage
This smart parking system can be used in small parking facilities to automate entry/exit control, display real-time slot availability, and enable remote monitoring. It’s an ideal solution for garages, small commercial spaces, or residential complexes.
