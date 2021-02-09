/*  
  Name:           Rutvik Patel
  Student No.:    040915445
  Date:           02-11-2020  
  
  MidTerm Practical Exam

*/
#include <Bounce2.h>

const int dataPin = 14;  //data
const int latchPin = 15; // RCLK
const int clockPin = 16; //SRCLK

int button = 10;

// Instantiate a Bounce object
Bounce debouncerMode = Bounce();

int mode =0;

void setup() {                

  Serial.begin(38400);
  pinMode(button, INPUT);
  
  debouncerMode.attach(button,INPUT);
  debouncerMode.interval(25);
  
  // initialize I/O pins
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  digitalWrite(dataPin,LOW);
  digitalWrite(latchPin,LOW);
  digitalWrite(clockPin,LOW);
}

void loop()                     
{
   byte myfnNumToBits[] = {B11111111,B01111111,B10111111,B11011111,B11101111,B11110111,B11111011,B11111101,B11111110,B00000000};
    debouncerMode.update(); // Update the Bounce instance

    if (debouncerMode.fell()){
    mode++; // add values to change modes 
    if(mode == 1){
      Serial.println("PBS press # 1 => Segment A");}
    if(mode == 2){
      Serial.println("PBS press # 2 => Segment B");}
    if(mode == 3){
      Serial.println("PBS press # 3 => Segment C");}
    if(mode == 4){
      Serial.println("PBS press # 4 => Segment D");}
    if(mode == 5){
      Serial.println("PBS press # 5 => Segment E");}
    if(mode == 6){
      Serial.println("PBS press # 6 => Segment F");}
    if(mode == 7){
      Serial.println("PBS press # 7 => Segment G");}
    if(mode == 8){
      Serial.println("PBS press # 8 => Segment Decimal Point");}
    if(mode == 9){
      Serial.println("PBS press # 9 => 8.");}
    if(mode == 10){
      Serial.println("PBS press # 10 => all segment OFF");}
    }   
    resetDisplay();
    byte bit1 = myfnNumToBits[mode];
    myfnUpdateDisplay(bit1);
}

// Update the display
void myfnUpdateDisplay(byte eightBits) {
  digitalWrite(latchPin, LOW );  // prepare shift register for data
  shiftOut(dataPin, clockPin, LSBFIRST, eightBits); // send data
  digitalWrite(latchPin, HIGH); // update display
}

// Method to Reset the Display
void resetDisplay(){
   if(mode > 9){
      mode = 0;}
}
