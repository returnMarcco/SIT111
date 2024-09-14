/** SIT111 - 3.1P: Arduino Blinky
 * Jason Mark Vellucci | studentID: 221437402
 *
 */

const int ledPin = 13;

void setup() { // Initializer function.
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // Turn the LED on.
  digitalWrite(ledPin, HIGH);
  delay(1000);

  // Turn the LED off.
  digitalWrite(ledPin, LOW);
  delay(1000);
}