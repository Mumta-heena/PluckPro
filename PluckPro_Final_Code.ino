#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>  // Include the Servo library

// Pin definitions
#define TRIG_PIN A0 // Ultrasonic sensor trigger pin
#define ECHO_PIN A1 // Ultrasonic sensor echo pin
#define MAX_DISTANCE 200 // Maximum distance to measure (in cm)

// FOR COLOR DETECTION MECHANISM
// #define S0 A2
// #define S1 A3
// #define S2 A5
// #define S3 A5
// #define OUT 9
// #define LED 5
// int redFrequency, greenFrequency, blueFrequency;


// Motor definitions
AF_DCMotor motorRight(1, MOTOR12_1KHZ);  // Right motor connected to pin 1 on L293D
AF_DCMotor motorLeft(4, MOTOR34_1KHZ);   // Left motor connected to pin 4 on L293D

// Servo motor definition
Servo baseServo;  // for base
Servo grabServo;  // for grabbing

// Create NewPing object
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  
  baseServo.attach(10);  // Attaching base servo to pin 10
  grabServo.attach(9);  // Attaching Grabbing servo to pin 9
  // Optionally, you can start the servo at a specific position
  baseServo.write(0);  // Start at 0 degrees
  grabServo.write(0);

  //COLOR PART
  // pinMode(S0, OUTPUT);
  // pinMode(S1, OUTPUT);
  // pinMode(S2, OUTPUT);
  // pinMode(S3, OUTPUT);
  // pinMode(LED, OUTPUT);
  // digitalWrite(LED, HIGH);
  // pinMode(OUT, INPUT);
  
  // // Set frequency scaling to 100%
  // digitalWrite(S0, HIGH);
  // digitalWrite(S1, LOW);
}

void loop() {
  // Measure distance using NewPing
  float distance = sonar.ping_cm(); // Get distance in centimeters

  if (distance == 0) {
    // Handle no echo (out of range)
    Serial.println("No object detected!");
    moveForward();
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Perform actions based on distance
    if (distance < 5) {
      Serial.println("Too close! Moving backward...");
      moveBackward();
    } else if (distance >= 5 && distance <= 15) {
      Serial.println("Within range! Stopping...");
      moveStop(); // Stop immediately
      //checkRipe();
      grabFruit();
      storeFruit();

    } else if (distance > 15) {
      Serial.println("Moving forward...");
      moveForward();
    }
  }

  delay(100); // Short delay to check distance more frequently
}

// Gradual decrease in motor speed
void moveForward() {
  motorRight.setSpeed(80); // Fixed forward speed
  motorRight.run(FORWARD);

  motorLeft.setSpeed(80);
  motorLeft.run(FORWARD);
}

// Move backward
void moveBackward() {
  motorRight.setSpeed(100);
  motorRight.run(BACKWARD);

  motorLeft.setSpeed(100);
  motorLeft.run(BACKWARD);
}

// Stop the motors
void moveStop() {
  motorRight.run(RELEASE);
  motorLeft.run(RELEASE);
}

void grabFruit()
{
  for (int pos = 0; pos <= 45; pos++) {  // Sweep from 0 to 45 degrees to grab fruit
    grabServo.write(pos);             // Move servo to position
    delay(15);                      // Wait for the servo to reach the position
  }
  delay(500);

  for (int pos2 = 0; pos2 <= 180; pos2++) {  // Sweep from 0 to 180 degrees
    baseServo.write(pos2);             // Move base servo to store
    delay(15);                      // Wait for the servo to reach the storage box
  }
  delay(500);
}

// void checkRipe()
// {
//   redFrequency = readColor("Red", LOW, LOW);
//   greenFrequency = readColor("Green", HIGH, HIGH);
//   blueFrequency = readColor("Blue", LOW, HIGH);

//   identifyFruitRipeness();

// }

// int readColor(const char* colorName, bool s2State, bool s3State) {
//   // Configure color filter
//   digitalWrite(S2, s2State);
//   digitalWrite(S3, s3State);
  
//   // Measure frequency
//   int frequency = pulseIn(OUT, LOW);
  
//   return frequency;
// }

// void identifyFruitRipeness() {
//   // Determine if the fruit is ripe or not
//   if (redFrequency < greenFrequency && redFrequency < blueFrequency) {
//     Serial.println("The fruit is Ripe!");
//     grabFruit();
//   } else {
//     Serial.println("Not ready to pick.");
//     moveStop();
//   }
// }

void storeFruit()
{
  for (int pos = 45; pos >= 0; pos--) {  // Sweep back from 45 to 0 degrees
    grabServo.write(pos);             // Move servo to release fruit
    delay(15);                      // Wait for the servo to reach the position
  }
  delay(500);

  for (int pos2 = 180; pos2 >= 0; pos2--) {  // Sweep back from 180 to 0 degrees
    baseServo.write(pos2);             // Move base servo to front

    delay(15);                      // Wait for the servo to reach the position
  }
  delay(500);
}
