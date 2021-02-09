/*  File name:      7segment.ino
 *  Date:           2020-10-14
 *  Name:           Rutvik Patel
 *  Lab:            5
 *  Demo:           4
 *  
 *  Double Digit Seven Segment LED Displays
*/
IntervalTimer myTimer;
int i = 0;
int j = 0;
const int dataPin = 14;  //data
const int latchPin = 15; // RCLK
const int clockPin = 16; //SRCLK

void setup() {
  // initialize I/O pins
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  digitalWrite(dataPin,LOW);
  digitalWrite(latchPin,LOW);
  digitalWrite(clockPin,LOW);

  myTimer.begin(resetCount, 8000000);
}

void loop() {
  for (;i <= 9; i++) {
    for(;j<=9; j++){
    byte bit1 = myfnNumToBits(j);
    byte bit2 = myfnNumToBits(i);
    
    myfnUpdateDisplay(bit1);    // Display 2
    myfnUpdateDisplay(bit2);    // display 1  

      delay(1000);                 // pause for 1/2 second
    }
  }
}
void resetCount(){
  i = 0;
  j = 0;
  myfnUpdateDisplay(myfnNumToBits(0));    // Reset Display 2
  myfnUpdateDisplay(myfnNumToBits(0));    // Reset Display 1  
  delay(1000); 
}

void myfnUpdateDisplay(byte eightBits) {
  
  digitalWrite(latchPin, LOW );  // prepare shift register for data
  shiftOut(dataPin, clockPin, LSBFIRST, eightBits); // send data
  digitalWrite(latchPin, HIGH); // update display
}

byte myfnNumToBits(int someNumber) {
  switch (someNumber) {
    case 0:
      return B00000011;
      break;
    case 1:
      return B10011111;
      break;
    case 2:
      return B00100101;
      break;
    case 3:
      return B00001101;
      break;
    case 4:
      return B10011001;
      break;
    case 5:
      return B01001001;
      break;
    case 6:
      return B01000001;
      break;
    case 7:
      return B00011111;
      break;
    case 8:
      return B00000001;
      break;
    case 9:
      return B00001001;
      break;
    
    default:
      return B01101101; // Error condition, displays three vertical bars
      break;    
  }
}
