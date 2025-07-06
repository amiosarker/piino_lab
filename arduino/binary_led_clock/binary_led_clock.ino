// Arduino IDE version: 1.8.13

#include <Arduino.h>

// Number of LEDs connected to digital pins 0–5
const int NUM_LEDS = 6;

// Delay between updates (in milliseconds)
const int DELAY_LED = 1000;

// Time counter (increments every loop)
int time = 0;

// Time value normalized to 0–59 (for seconds display)
int normalized_time = 0;

/**
 * @brief Lights up LEDs to represent the binary value of input.
 * 
 * Recursively sets each LED (connected to pins 0–5) according to the bits of 'input'.
 * 
 * @param input The value to display in binary.
 * @param base  The current bit position (and pin number).
 */
void lights(int input, int base) {
  if (base < 0) return;  // Base case: stop recursion

  int bit = (input >> base) & 1;  // Extract bit at 'base' position
  digitalWrite(base, bit ? HIGH : LOW);  // Set corresponding LED

  lights(input, base - 1);  // Recurse for next lower bit
}

void setup() {
  // Initialize LED pins as outputs
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // Increment time and wrap around every 60 counts (simulate seconds)
  time++;
  normalized_time = time % 60;

  // Display the current time value in binary using LEDs
  lights(normalized_time, NUM_LEDS - 1);

  // Wait before updating again
  delay(DELAY_LED);
}