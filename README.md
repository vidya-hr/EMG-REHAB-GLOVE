# EMG-REHAB-GLOVE
Arduino-based EMG controlled hand rehabilitation glove using 5 servo motors with 3 intensity levels for finger movement assistance
EMG-Controlled Hand Rehabilitation Glove
About the Project:
Hand rehabilitation is a critical yet often inaccessible process for patients recovering from strokes, nerve injuries, or conditions like cerebral palsy. Traditional physiotherapy requires constant supervision and repeated sessions, making it expensive and time-consuming. This project addresses that gap by building a low-cost, Arduino-based assistive glove that uses EMG (Electromyography) biosignals to assist and automate finger movement for rehabilitation purposes.

How It Works:
The glove captures muscle activity through EMG sensors placed on the forearm. These electrical signals are processed by an Arduino microcontroller, which interprets signal intensity and translates it into precise servo motor movements. Five servo motors are mounted on the glove — one for each finger — enabling both coordinated hand motion and individual finger exercises depending on the rehabilitation routine required.

Key Features:
5 servo motors providing independent finger-level control
3 movement intensity levels — low, medium, and high — implemented using adjustable angle thresholds
Push-button interface allowing patients or therapists to switch between intensity modes
LED indicators showing the currently selected intensity level at a glance
Supports full hand coordinated movement as well as isolated single-finger exercises

Technical Implementation:
The system is programmed in C++ using the Arduino IDE. EMG sensor output is read through analog input pins and mapped to servo angle ranges corresponding to each intensity level. The push-button cycles through modes while LEDs provide real-time visual feedback.

Results:
Successfully demonstrated real-time embedded control, actuator interfacing, and assistive device design

Tech Stack
Arduino · C++ · EMG Sensors · Servo Motors · Embedded Systems
