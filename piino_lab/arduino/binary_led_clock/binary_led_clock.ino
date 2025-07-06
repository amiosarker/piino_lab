// Arduino IDE version: 1.8.13

const int NUM_LEDS = 6;
const int delay_led = 1000;

int time = 0;
int normalized_time = 0;

// Lights function: maps bits of input to digital pins 0–5
void lights(int input, int base) {
  if (base < 0) return;  // Stop recursion when base is out of bounds

  int bit = (input >> base) & 1;  // Get the bit at 'base' position
  digitalWrite(base, bit ? HIGH : LOW);

  lights(input, base - 1);  // Recursive call with lower bit
}

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(i, OUTPUT);  // Set pins 0 through 5 as outputs
  }
}

void loop() {
  time++;
  normalized_time = time % 60;  // Limit time to 0–59 range
  lights(normalized_time, NUM_LEDS - 1);
  delay(delay_led);
}