#include <Servo.h>

Servo myservo[5];

int pos = 0;
int min_val = 30;
int max_val = 150;

/*
  Note: Servo motor 0 and 1 have opposite orientation to servo 3, 4 and 5.
  For motor 0 and 1 finger closes at min angle, whereas motor 3,4,5 close at max angle.
*/

void setup() {
  myservo[0].attach(2); // pinky finger
  myservo[1].attach(3); // ring finger
  myservo[2].attach(4); // middle finger
  myservo[3].attach(5); // index finger
  myservo[4].attach(6); // thumb

  all_fingers_close();
  delay(1000);
  all_fingers_open();
  delay(1000);
}

void loop() {
  // Pattern 1: all fingers close and open 5 times
  for (int i = 0; i < 5; i++) {
    all_fingers_close();
    delay(1000);
    all_fingers_open();
    delay(1000);
  }

  // Pattern 2: each finger closes and opens separately
  for (int servo = 0; servo < 5; servo++) {
    if (servo >= 2) {
      for (pos = min_val; pos <= max_val; pos += 5) {
        myservo[servo].write(pos); delay(15);
      }
      for (pos = max_val; pos >= min_val; pos -= 5) {
        myservo[servo].write(pos); delay(15);
      }
    } else {
      for (pos = max_val; pos >= min_val; pos -= 5) {
        myservo[servo].write(pos); delay(15);
      }
      for (pos = min_val; pos <= max_val; pos += 5) {
        myservo[servo].write(pos); delay(15);
      }
    }
  }
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
