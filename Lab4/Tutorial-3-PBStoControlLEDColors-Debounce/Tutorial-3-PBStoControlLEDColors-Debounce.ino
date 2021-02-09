/*
Name:           Rutvik Patel
Student Number:   040915445
Lab:              4

*/
#include <Bounce2.h>

int red =   22;     
int green = 20;     
int blue =  21;     

int pbsMode0 = 9;
int pbsMode1 = 10;

Bounce debouncerMode0 = Bounce(); // Instantiate a Bounce object
Bounce debouncerMode1 = Bounce();

void setup()   {
  Serial.begin(38400);
  pinMode(pbsMode0, INPUT);
  pinMode(pbsMode1, INPUT_PULLUP);

  debouncerMode0.attach(pbsMode0,INPUT);
  debouncerMode0.interval(25);

  debouncerMode1.attach(pbsMode1,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncerMode1.interval(25); // Use a debounce interval of 25 milliseconds

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

int redIntensity = 0;
int mode = 0;

void loop()                     
{
  // set all 3 pins to the desired intensity
  analogWrite(red, redIntensity);
  if (mode == 0) {
    // in mode zero, fade from red to green
    analogWrite(green, 255 - redIntensity);
    analogWrite(blue, 0);
  } else {
    // in mode one, fade from red to blue
    analogWrite(green, 0);
    analogWrite(blue, 255 - redIntensity);
  }

   debouncerMode0.update(); // Update the Bounce instance

   if ( debouncerMode0.fell() ) {  // Call code if button transitions from HIGH to LOW
    // use mode zero when the first button is pressed
    mode = 0;
    Serial.println("mode 0");
   }

   debouncerMode1.update();

   if ( debouncerMode1.fell() ) {
    // use mode one when the second button is pressed
    mode = 1;
    Serial.println("mode 1");
  }
  
  // remain at this color, but not for very long
  delay(10);
  
  // increase the red
  redIntensity = redIntensity + 1;
  
  // since 255 is the maximum, set it back to 0
  // when it increments beyond 255
  if (redIntensity > 255) {
    redIntensity = 0;
  }
}
