#include <Servo.h>

Servo myservo[5]; // create servo objects to control servo

// Button + LED pins
int buttonPin = 7;
int greenLED = 8;
int yellowLED = 9;
int redLED = 10;

int level = 0; // 0 = LOW, 1 = MED, 2 = HIGH
int lastState = HIGH;
unsigned long debounce = 200;

// Threshold angle values
int low_min = 30;
int low_max = 90;
int med_min = 40;
int med_max = 120;
int high_min = 30;
int high_max = 150;

int min_val, max_val;
int pos = 0;

void setup() {
  // Attach servos
  myservo[0].attach(2); // pinky
  myservo[1].attach(3); // ring
  myservo[2].attach(4); // middle
  myservo[3].attach(5); // index
  myservo[4].attach(6); // thumb

  // Button + LEDs
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  update_threshold();
  update_leds();

  // Startup movement
  all_fingers_close();
  delay(800);
  all_fingers_open();
  delay(800);
}

void loop() {
  // Read button for threshold change
  int reading = digitalRead(buttonPin);
  if (reading == LOW && lastState == HIGH) {
    delay(debounce);
    level = (level + 1) % 3; // cycle Low → Med → High → repeat
    update_threshold();
    update_leds();
  }
  lastState = reading;

  // PATTERN 1: close/open 5 times
  for (int i = 0; i < 5; i++) {
    all_fingers_close();
    delay(1000);
    all_fingers_open();
    delay(1000);
  }

  // PATTERN 2: each finger one by one
  for (int servo = 0; servo < 5; servo++) {
    if (servo >= 2) {
      for (pos = min_val; pos <= max_val; pos += 5) {
        myservo[servo].write(pos);
        delay(15);
      }
      for (pos = max_val; pos >= min_val; pos -= 5) {
        myservo[servo].write(pos);
        delay(15);
      }
    } else {
      for (pos = max_val; pos >= min_val; pos -= 5) {
        myservo[servo].write(pos);
        delay(15);
      }
      for (pos = min_val; pos <= max_val; pos += 5) {
        myservo[servo].write(pos);
        delay(15);
      }
    }
  }
}

void update_threshold() {
  if (level == 0) {
    min_val = low_min;
    max_val = low_max;
  } else if (level == 1) {
    min_val = med_min;
    max_val = med_max;
  } else {
    min_val = high_min;
    max_val = high_max;
  }
}

void update_leds() {
  digitalWrite(greenLED,  level == 0);
  digitalWrite(yellowLED, level == 1);
  digitalWrite(redLED,    level == 2);
}

void all_fingers_close() {
  myservo[0].write(min_val);
  myservo[1].write(min_val);
  myservo[2].write(max_val);
  myservo[3].write(max_val);
  myservo[4].write(max_val);
  delay(50);
}

void all_fingers_open() {
  myservo[0].write(max_val);
  myservo[1].write(max_val);
  myservo[2].write(min_val);
  myservo[3].write(min_val);
  myservo[4].write(min_val);
  delay(50);
}
