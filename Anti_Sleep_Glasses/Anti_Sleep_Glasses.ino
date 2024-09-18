// Include necessary libraries
#include <IRremote.h>

// Define IR sensor pin
const int irSensorPin = 7;  // Connect the IR sensor output pin to digital pin 2

// Define buzzer pin
const int buzzerPin = 8;    // Connect the buzzer to digital pin 3

// Define variables
unsigned long lastEyeOpenTime = 0; // Time when eyes were last open
const unsigned long eyeOpenThreshold = 2000; // Adjust this value as needed (in milliseconds)

void setup() {
  // Initialize IR sensor
  pinMode(irSensorPin, INPUT);

  // Initialize buzzer
  pinMode(buzzerPin, OUTPUT);
  noTone(buzzerPin); // Turn off the buzzer initially
}

void loop() {
  // Read the state of the IR sensor (LOW means eyes closed, HIGH means eyes open)
  int eyeState = digitalRead(irSensorPin);

  // Check if the eyes are open
  if (eyeState == LOW) {
    // Eyes are open, reset the timer
    lastEyeOpenTime = millis();
  } else {
    // Eyes are closed
    unsigned long currentTime = millis();
    // Check if eyes have been closed for a certain duration
    if (currentTime - lastEyeOpenTime >= eyeOpenThreshold) {
      // Eyes have been closed for too long, activate the buzzer
      tone(buzzerPin, 1000); // You can adjust the frequency as needed
    } else {
      // Eyes have been closed, but not for too long, keep the buzzer off
      noTone(buzzerPin);
    }
  }
}
