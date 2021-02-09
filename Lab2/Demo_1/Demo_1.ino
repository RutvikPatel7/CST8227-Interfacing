/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Name:       Rutvik Patel
  Student No: 040915445
  Demo:       #1
 */

// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// give it a name:
const int ledPin = 13;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);               // wait for a second
  //digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);               // wait for a second

  digitalWrite( ledPin, ! digitalRead(ledPin));
  delay(1000);               // wait for a second
}
