int LED1 = 8;  // Low threshold indicator
int LED2 = 9;  // Medium threshold indicator
int LED3 = 10; // High threshold indicator

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // Test 1: Turn LEDs ON one by one
  digitalWrite(LED1, HIGH); delay(500); digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH); delay(500); digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH); delay(500); digitalWrite(LED3, LOW);

  // Test 2: Blink all LEDs together
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(800);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(800);
}
