/*
 * Night Light Project - Photoresistor and LED
 * Clayton Walker
 */

int photoresistorPin = A0;
int ledPin = 9;

int analogValue; //store values read from photoresistor
int threshold = 400; //Found through experimentation

void setup() {
  //Set up serial communication
  Serial.begin(9600);

  pinMode(photoresistorPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read value from photoresistorPin
  analogValue = analogRead(photoresistorPin);

  //Write value out serially
  Serial.println(analogValue);

  if(analogValue < threshold){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}
