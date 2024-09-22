/**
* SIT111 - 3.4P | T2, 2024
* Jason Mark Vellucci | SID: 221437402
*/

// Reads `soil moisture` levels from the physical environment via a physical sensor.

const int SENSOR_PIN = A0; // Analog input pin connected to the soil moisture sensor.

void setup() {
	Serial.begin(9600); // Initialize serial communication.
}

void loop() {
  int sensor_value = analogRead(SENSOR_PIN); // Read the value from the sensor. This is the INPUT from the `Soil Moisture Sensor` > `Arduino`.
  int moisture_level = map(sensor_value, 0, 1023, 100, 0); // Map it to a 0-100% range.
  Serial.print("Moisture Level: ");
  Serial.print(moisture_level);
  Serial.println("%");
  delay(1000); // `ms` delay between readings.
}
