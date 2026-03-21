int buttonPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int state = digitalRead(buttonPin);
  Serial.println(state); // 1 = not pressed, 0 = pressed
  delay(200);
}
