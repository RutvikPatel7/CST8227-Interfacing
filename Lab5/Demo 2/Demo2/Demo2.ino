/*
 * @author:         Rutvik Patel
 * Student Number:  040915445
 * 
 * Lab:  5
 * Demo: #2
 * 
 * Components:* LED x16 
              * SN74HC595N by Texas Instruments (TI) x2
              * Jumper Wires
              * Teensy 3.2
 */

int SER = 14; //data
int LATCH = 15; //RCLK
int CLOCK = 16; //SRCLK

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  digitalWrite(SER, 0);
  digitalWrite(CLOCK, 0);
  digitalWrite(LATCH, 0);

 // delay(1000);
}

void loop() {


    int bitArray[] = {1, 3, 7, 15, 31, 63, 127, 255};
   
    //count up first 8-bits
    for(int i = 0; i < 8; i++) {
      digitalWrite(LATCH, HIGH);
      //shift first 8 bits; ends up in the second SR
      shiftOut(SER, CLOCK, MSBFIRST, 0);
      //shift second 8-bits; ends up in the first SR
      shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]);
      digitalWrite(LATCH, LOW);
      delay(20);
    }
    
    //count up second 8-bits
    for(int i = 0; i < 8; i++) {
      digitalWrite(LATCH, HIGH);
      //shift first 8 bits; ends up in the second SR
      shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]);
     //shift second 8-bits; ends up in the first SR
      shiftOut(SER, CLOCK, MSBFIRST, 255);
      digitalWrite(LATCH, LOW);
      delay(20);
     }
    
    //count down second 8-bits
     for(int i = 7; i > 0; i--) {
      digitalWrite(LATCH, HIGH);
      //shift first 8 bits; ends up in the second SR
      shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]);
      //shift second 8-bits; ends up in the first SR
      shiftOut(SER, CLOCK, MSBFIRST, 255);
      digitalWrite(LATCH, LOW);
      delay(20);
    }

     //count down first 8-bits
     for(int i = 7; i > 0; i--) {
      digitalWrite(LATCH, HIGH);
      //shift second 8-bits; ends up in the second SR
      shiftOut(SER, CLOCK, MSBFIRST, 0);
      //shift first 8 bits; ends up in the first SR
      shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]);
      digitalWrite(LATCH, LOW);
      delay(20);
    }
}
