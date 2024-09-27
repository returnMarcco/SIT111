// Include the servo library:
#include "Servo.h"

// Create a new servo object:
Servo myservo;

// Define the servo pin:
#define servoPin 9

// Global var
const int angle_array[5] = {90, 135, 0, 180, 0};
int angle_array_size     = sizeof(angle_array) / sizeof(angle_array[0]);

void setup() {
// Attach the Servo variable to a pin:
    Serial.begin(9600);
    myservo.attach(servoPin);
}

/**
* A helper function for moving the servo motor a variable number of ways.
* 1000ms delay between each. Used for both `Task 1`and `Task 2`.
*/
void moveServo(int degrees[], int array_length, Servo servo) {
  for (int i = 0; i < array_length; i++) {
    Serial.print(degrees[i]); // For monitoring/debugging.
    Serial.println(" degrees,");
    servo.write(degrees[i]);
    delay(1000); // Give the motor time to finish moving.
  }
}

void loop() {
  // Task 1: Tell the servo to go to a 90 degree angle,
  // 135 degrees, then 180 degrees before going back to
  // its original position (0 degrees).
  // Wait 1 second between each angle.

  // Task 2: Write a loop to tell the servo to slowly
  // sweep to 180 degrees, then back to 0 degrees
  // (use a delay to slow down the sweep)

  // This satisfies the requirements for both `Task 1 & Task 2`.
  moveServo(angle_array, angle_array_size ,myservo);
}
