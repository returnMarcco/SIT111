// Modules
#include "DHT.h"

/**
 * SIT111 3.5C | T2, 2024
 * Jason Mark Vellucci | SID: 221437402 
 */

// Sensors
#define DHTTYPE DHT22 // DHT 22 (AM2302)
#define DHTPIN 2 // Digital pin for DHT22
#define SOIL_MOISTURE_PIN A3 // Analog pin for Soil Moisture Sensor

// LEDs
#define GREEN_LED 5 // Green LED pin
#define RED_LED 6 // Red LED pin

// Question for tutor: Are global vars generally considered dangerous in Arduino land?
DHT dht(DHTPIN, DHTTYPE); // Object of type `DHT`.

// Thresholds
const float TEMP_THRESHOLD          = 30.00;
const float HUMIDITY_THRESHOLD      = 42.60;
const int SOIL_MOISTURE_THRESHOLD   = 70;

void setup() {
  Serial.begin(9600); // init. `serial comms`.
  dht.begin(); // Activate the `Humidity & Temp Sensor`
  
  // init. INPUT
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  pinMode(DHTPIN, INPUT);

  // init. OUTPUT
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  // Print Timestamp

  // Read temperature and humidity from the DHT22 sensor and print
  Serial.println("SENSOR READINGS");
  
  float temperature = dht.readTemperature(); // method calls on the `dht` object.
  Serial.print("Temperature: ");
  Serial.println(temperature);
  
  float humidity = dht.readHumidity(); // method calls on the `dht` object.
  Serial.print("Humidity: ");
  Serial.println(humidity);
  
  // Read `moisture level` from the `Soil Moisture Sensor` and print
  int sensor_value = analogRead(SOIL_MOISTURE_PIN); // Read the value from the sensor. This is the INPUT from the `Soil Moisture Sensor` > `Arduino`.
  int soil_moisture_level = map(sensor_value, 0, 1023, 100, 0); // Map it to a 0-100% range.
  Serial.print("Moisture Level: ");
  Serial.print(soil_moisture_level);
  Serial.println("%");

  Serial.println("----------------------------------------------------------------");

  // Implement logic to control the green and red LEDs
  // GREEN LED permanently HIGH
  digitalWrite(GREEN_LED, HIGH);

  if ( (temperature >= TEMP_THRESHOLD) || (humidity >= HUMIDITY_THRESHOLD) || (soil_moisture_level <= SOIL_MOISTURE_THRESHOLD) ) {
    digitalWrite(RED_LED, HIGH);
  } else {
    digitalWrite(RED_LED, LOW);
  }

  delay(2000); // Delay between readings
}
