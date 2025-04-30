
// Basic Fall detection system
// pin definitions
const int pinPot = A0;
const int ledPin = 12;
const int buzzerpin = 11;

//Thershold
const int fallthreshold = 600;
bool falldetected = false;
unsigned long falltime = 0;
const unsigned long cooldown = 4500;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(pinPot);
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);

  if (falldetected && millis() - falltime >= cooldown){
    falldetected = false;
    Serial.println("System Normal.");
    digitalWrite(ledPin, LOW);
    noTone(buzzerpin);;
  }

  if (sensorValue > fallthreshold && !falldetected){
    falldetected = true;
    falltime = millis();
    Serial.println("Fall Detected!");
    digitalWrite(ledPin, HIGH);
   tone(buzzerpin, 1000);
  }


  delay(200);


}
