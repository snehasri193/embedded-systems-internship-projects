int ledPin = 13;
int switchPin = 8;
int ledState = LOW;        // LED initially OFF
int lastSwitchState = LOW; // To detect switch change

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  Serial.println("Enter 1 to turn ON LED, 2 to turn OFF LED");
}

void loop() {
  // 1. Serial Control
  if (Serial.available() > 0) {
    char a = Serial.read();

    if (a == '1') {
      ledState = HIGH;
      Serial.println("LED turned ON via Serial");
    } 
    else if (a == '2') {
      ledState = LOW;
      Serial.println("LED turned OFF via Serial");
    }
  }

  //  2. Switch Control (Toggle)
  int switchState = digitalRead(switchPin);

  // Detect switch change (edge detection)
  if (switchState == HIGH && lastSwitchState == LOW) {
    ledState = !ledState;  // toggle LED
    delay(300);            // debounce delay
  }

  lastSwitchState = switchState; // store state for next loop

  // 3. Apply the LED state 
  digitalWrite(ledPin, ledState);
}