# EMG-Controlled Hand Rehabilitation Glove

## About the Project
Hand rehabilitation is a critical yet often inaccessible process for 
patients recovering from strokes, nerve injuries, or conditions like 
cerebral palsy. Traditional physiotherapy requires constant supervision 
and repeated sessions, making it expensive and time-consuming. This 
project addresses that gap by building a low-cost, Arduino-based 
assistive glove that uses EMG biosignals to assist and automate finger 
movement for rehabilitation purposes.

## How It Works
The glove captures muscle activity through EMG sensors placed on the 
forearm. These electrical signals are processed by an Arduino 
microcontroller, which interprets signal intensity and translates it 
into precise servo motor movements. Five servo motors are mounted on 
the glove — one for each finger — enabling both coordinated hand motion 
and individual finger exercises.

## Key Features
- 5 servo motors providing independent finger-level control
- 3 movement intensity levels — low, medium, and high
- Push-button interface to switch between intensity modes
- LED indicators showing currently selected intensity level
- Supports coordinated and isolated single-finger exercises

## Tech Stack
Arduino · C++ · EMG Sensors · Servo Motors · Embedded Systems

## Results
-Successfully demonstrated real-time embedded control, actuator interfacing, and assistive device design

