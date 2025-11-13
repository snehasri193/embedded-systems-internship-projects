// Pin assignments for 7-segment display (common cathode)
const int digit1 = 2; // Units digit (ones)
const int digit2 = 3; // Tens digit (tens)

// Segment pins (a to g)
const int a = 4;
const int b = 5;
const int c = 6;
const int d = 7;
const int e = 8;
const int f = 9;
const int g = 10;

int x = 0; // Units digit
int y = 0; // Tens digit
boolean digit = HIGH; // Used to alternate between digits

unsigned long previousMillis = 0;
const long interval = 200;

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);

  Serial.begin(9600); // <-- This enables Serial Monitor!
}

void loop() {
  unsigned long currentMillis = millis();

  digit = !digit;

  if (digit == LOW) {
    digitalWrite(digit1, LOW);  // Turn on units digit
    digitalWrite(digit2, HIGH); // Turn off tens digit
    displayDigit(x);
  } else {
    digitalWrite(digit1, HIGH); // Turn off units digit
    digitalWrite(digit2, LOW);  // Turn on tens digit
    displayDigit(y);
  }
  delay(5);

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    x++;
    if (x > 9) {
      x = 0;
      y++;
      if (y > 9) {
        y = 0;
      }
    }
    // Add Serial output here
    Serial.print("Current value: ");
    Serial.print(y);
    Serial.print(x);
    Serial.println();
  }
}

void displayDigit(int num) {
  // reset all segments
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);

  switch (num) {
    case 0: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); break;
    case 1: digitalWrite(b, HIGH); digitalWrite(c, HIGH); break;
    case 2: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(g, HIGH); break;
    case 3: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(g, HIGH); break;
    case 4: digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 5: digitalWrite(a, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 6: digitalWrite(a, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 7: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); break;
    case 8: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 9: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
  }
}