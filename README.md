Smart-Parking-Embedded-System

🚗 Smart Parking System – Embedded Systems Project

An ESP32-based embedded system for managing a smart parking lot, including vehicle detection, parking-slot monitoring, gas sensing, barrier control, web server, indicator LEDs, camera streaming, MP3 alerts, and more.

📘 Project Description

This project implements a complete smart-parking solution that detects incoming vehicles using an ultrasonic sensor, manages parking-slot availability, identifies smoke/gas hazards, controls a servo-barrier gate, activates visual indicators, streams live video from an ESP32-CAM, plays audio alerts, and displays real-time parking status through an HTTP dashboard.

The code is modular and divided into multiple .ino files according to system components.

🎯 System Objectives

Detect vehicle entry automatically

Control entrance barrier using a servo motor

Monitor available and occupied parking spots

Detect smoke/gas using an MQ-2 sensor

Capture and stream live video using ESP32-CAM

Trigger alerts with LEDs and LED strip

Play audio messages using a Serial MP3 Player

Host a real-time web dashboard via an HTTP server

Run fully on an embedded ESP32 controller

🗂 Project Structure (Code Files)
File	Description
01_main.ino	System initialization and main loop
03_entry.ino	Vehicle detection, servo gate control, entry counter
04_gas.ino	MQ-2 smoke/gas sensor reading and alert handling
06_parking.ino	Parking-slot calculations and state management
07_http_server.ino	HTTP server providing real-time dashboard
05_utils.ino	Utility functions
smart_parking.ino	Integration/manager file
🧰 Hardware Used

Below are all the components integrated into the system:

🧠 Controller

ESP32

🚗 Vehicle Detection

HC-SR04 Ultrasonic Distance Sensor

🔥 Safety

MQ-2 Smoke / Gas Sensor

🎥 Video Monitoring

ESP32-CAM Camera Module

🎵 Audio Alerts

Serial MP3 Player
Plays audio messages such as “Parking full”, “Smoke detected”, “Welcome”, etc.

🔧 Barrier Control

Servo Motor

💡 Indicators

Red LED (parking full / danger)

Green LED (entry allowed / parking available)

LED Strip (visual alerts / design)

🔌 How the System Works

The HC-SR04 detects an approaching vehicle.

If parking is available → the servo opens the gate.

The system updates the parking-slot counter.

MQ-2 monitors smoke/gas levels and triggers alerts if needed.

ESP32-CAM provides live video streaming.

LEDs and LED strip display status (available/full/danger).

The MP3 Player plays voice notifications based on events.

The HTTP server displays a live dashboard accessible to all devices on the network.

🖥️ Dashboard Features

The HTTP dashboard provides:

Parking availability

Gas/smoke alerts

Live ESP32-CAM video feed

Vehicle entry logs

Barrier status

Real-time system updates

▶️ How to Run the Project

Place all .ino files in the same folder.

Open the project in Arduino IDE.

Select board: ESP32 Dev Module.

Update WiFi credentials in the HTTP server file.

Upload the code to the ESP32.

Open Serial Monitor to get the IP address.

Open the IP in your browser → dashboard appears.
