/*
Name          : Rutvik Patel
Lab           : 6
Studet Number : 040915445

*/

const int sensorPin = 16;    // pin that the sensor is attached to
const int ledPin = 9;        // pin that the LED is attached to
const int buzzPin = 10;      // pin that the buzzer is attached to

// variables:
int sensVal = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value


void setup() {
  // turn on LED & buzer to signal the start of the calibration period:
  pinMode(13, OUTPUT);   
  digitalWrite(13, HIGH);

  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensVal = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensVal > sensorMax) {
      sensorMax = sensVal;
    }

    // record the minimum sensor value
    if (sensVal < sensorMin) {
      sensorMin = sensVal;
    }
  }

  // signal the end of the calibration period
  digitalWrite(13, LOW);
}

void loop() {
  // read the sensor:
  sensVal = analogRead(sensorPin);

  // apply the calibration to the sensor reading
  sensVal = map(sensVal, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensVal = constrain(sensVal, 0, 255);

  // fade the LED using the calibrated value:
  analogWrite(ledPin, sensVal);

  //gives output for sensor
  Serial.println(touchRead(16));  // return value of Touch 0 pin = GPIO 16
   
  // Sound buzer
  tone(buzzPin, sensVal);
  
  delay(400);
}
