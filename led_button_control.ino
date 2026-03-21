int buttonPin = 7;
int greenLed = 8;
int yellowLed = 9;
int redLed = 10;

int mode = 0;
int lastButtonState = 1;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);

  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == 0 && lastButtonState == 1) {
    mode++;
    if (mode > 2) mode = 0;
    Serial.print("Mode changed to: ");
    Serial.println(mode);
    updateLEDs();
    delay(250);
  }
  lastButtonState = buttonState;
}

void updateLEDs() {
  if (mode == 0) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
  } else if (mode == 1) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
  } else if (mode == 2) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
  }
}
