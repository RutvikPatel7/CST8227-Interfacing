void setup() {
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("Touch Test");
}

void loop() {
  Serial.println(touchRead(16));  // return value of Touch 0 pin = GPIO 16
  delay(1000);
}
