void setup() {
  DDRD |= 0b11111100;
  DDRB |= 0b00000011;
}

void loop() {
  for (int i = 2; i <= 9; i++) {
    setLED(i, 1);
    delay(150);
  }

  for (int i = 2; i <= 9; i++) {
    setLED(i, 0);
    delay(150);
  }

  delay(500);

  for (int i = 2; i <= 5; i++) setLED(i, 1);
  for (int i = 6; i <= 9; i++) setLED(i, 0);
  delay(1000);

  for (int i = 2; i <= 5; i++) setLED(i, 0);
  for (int i = 6; i <= 9; i++) setLED(i, 1);
  delay(1000);
}

void setLED(int pin, bool state) {
  if (pin >= 2 && pin <= 7) {
    if (state)
      PORTD |= (1 << pin);
    else
      PORTD &= ~(1 << pin);
  }
  else if (pin == 8 || pin == 9) {
    int bit = pin - 8;
    if (state)
      PORTB |= (1 << bit);
    else
      PORTB &= ~(1 << bit);
  }
}