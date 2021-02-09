/*
Name:           Rutvik Patel
Student Number:   040915445
Lab:              5

*/

#include <Shifty.h>

// Declare the shift register
Shifty shift; 

void setup() {
  // Set the number of bits you have (multiples of 8)
  shift.setBitCount(32);

  // Set the clock, data, and latch pins you are using
  // This also sets the pinMode for these pins
  shift.setPins(13, 11, 8); 
  pinMode(21, OUTPUT);
}

void loop() {
  // writeBit works just like digitalWrite
  shift.writeBit(1, HIGH);
  digitalWrite(21, HIGH);
  delay(500);
  shift.writeBit(3, HIGH);
  delay(500);
  shift.writeBit(1, LOW);
  digitalWrite(21, LOW);
  delay(500);
  shift.writeBit(3, LOW);
 
  delay(500);
}
