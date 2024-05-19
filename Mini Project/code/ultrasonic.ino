#include <Arduino.h>

const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 11;
const int ledPin = 2;
// defines variables
long duration;
int distance;
int safetyDistance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {

// Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  safetyDistance = distance;
  if (safetyDistance <= 10) {
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    tone(buzzerPin, 4000); // Set a tone of 1000 Hz
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
  } else {
    noTone(buzzerPin); // Turn off the buzzer
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}