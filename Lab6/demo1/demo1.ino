int redPin =  22;
int greenPin =  20;
int bluePin =  21;

void setup()   {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

int redIntensity = 0;

void loop()                     
{
  // read the pot position
  redIntensity = analogRead(0) / 4;
  
  // set all 3 pins to the desired intensity
  analogWrite(redPin, redIntensity);
  analogWrite(greenPin, 255 - redIntensity);
  analogWrite(bluePin, 0);

  // remain at this color, but not for very long
  delay(10);
}
