// Define LED pins
const int LED_PINS[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int LED_PIN_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]); // The number of elements representing `LED_PINS`.

void setup() {
  // Initialize each pin as an output
  // Keep the code DRY - loop through the array of `LED_PINS` and set the output for each.
  for (int led = 0; led < LED_PIN_COUNT; led++) {
    pinMode(LED_PINS[led], OUTPUT);
  }
}

void loop() {
  for (int led = 0; led < LED_PIN_COUNT; led++) {
    digitalWrite(led, HIGH); // Turn LED on.
    delay(1000); // ms.
    digitalWrite(led, LOW); // Turn LED off.
  }
}
