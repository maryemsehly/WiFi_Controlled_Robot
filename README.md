# WiFi_Controlled_Robot
Project Overview
This project implements a Wi-Fi-controlled robot using the ESP32 microcontroller. The robot's movements are controlled through a simple web server hosted on the ESP32, allowing users to control the robot remotely from any device connected to the same network. The goal of this project is to demonstrate how embedded systems can be integrated with web technologies for remote control and automation.

--Components Used
ESP32: Microcontroller that serves as the brain of the robot and hosts the web server.
DC Motors: Drive the robot's movement.
Motor Driver (L298N): Controls the motors' speed and direction.
Power Supply: Battery pack to power the robot.
Wi-Fi Module: Built-in ESP32 module for communication.


--Features
Web Server Interface: A user-friendly interface to control the robot's movement (forward, backward, left, right, stop) via any device with a browser.
Real-Time Control: Users can send commands to the robot in real-time through the web interface.
Responsive Design: The web server is accessible from mobile devices, tablets, and desktops.


--How It Works
The ESP32 creates a Wi-Fi access point, which allows devices to connect to the web server hosted on the microcontroller. Once connected, the user can access the control panel in their browser and send commands to control the robot's movement. The ESP32 receives these commands and adjusts the motors accordingly.
