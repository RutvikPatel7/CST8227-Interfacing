/*
 * Demo: Shift Register
 * 
 * Component: SN74HC595N by Texas Instruments (TI)
 * 
 * References:
 *  << (bitwise operator): https://www.arduino.cc/reference/en/language/structure/bitwise-operators/bitshiftleft/
 *  shiftOut(): https://www.arduino.cc/reference/en/language/functions/advanced-io/shiftout/
 *
 * @author: Gerald.Hurdle@AlgonquinCollege.com
 */
int SER = 14; //data
int LATCH = 15; //RCLK
int CLOCK = 16; //SRCLK

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  digitalWrite(SER, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);

  delay(1000);
}

void loop() {
  // BLINK :: MSBFIRST
//  digitalWrite(LATCH, LOW);
//  //shiftOut(dataPin, clockPin, bitOrder, value)
//  shiftOut(SER, CLOCK, MSBFIRST, 1);
//  digitalWrite(LATCH, HIGH);
//  delay(500);
//
//  digitalWrite(LATCH, LOW);
//  shiftOut(SER, CLOCK, MSBFIRST, 0);
//  digitalWrite(LATCH, HIGH);
//  delay(500);

  // BLINK :: LSBFIRST
 // digitalWrite(LATCH, LOW);
  //shiftOut(dataPin, clockPin, bitOrder, value)
//  shiftOut(SER, CLOCK, LSBFIRST, 1);
//  digitalWrite(LATCH, HIGH);
//  delay(500);
//
//  digitalWrite(LATCH, LOW);
//  shiftOut(SER, CLOCK, LSBFIRST, 0);
//  digitalWrite(LATCH, HIGH);
//  delay(500);

    // Travel Up
    byte theBits = 1;
    for(int i = 0; i < 8; i++) {
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLOCK, MSBFIRST, theBits);
      digitalWrite(LATCH, HIGH);
      delay(500);
      // bitshift left
      theBits <<= 1;
    }
}
