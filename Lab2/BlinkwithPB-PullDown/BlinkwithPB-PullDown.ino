int pbuttonPin = 9;         // connect output to push button
int relayPin = 20;       // connected to relay PIN (LED)

int val = 0;           // Push value from pin 2
int lightON = 0;       // Light Status
int pushed = 0;        // push Status

void setup()
{
  Serial.begin(9600);
  pinMode(pbuttonPin, INPUT);// INPUT_PULLUP (not using 2nd reg)
  pinMode(relayPin, OUTPUT);
}

void loop()
{
  val = digitalRead(pbuttonPin);

  if (val == HIGH && lightON == LOW ) {

    pushed = 1-pushed;
    delay(100);
    
   }

  lightON = val;

  if(pushed == HIGH){
    digitalWrite( relayPin, LOW);
  }
  else{
    digitalWrite( relayPin, HIGH);
  }
  delay(100);
}
