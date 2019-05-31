int sensorPin = A0; 
int sensorValue;  
int limit = 900; 

void setup() {
Serial.begin(9600);
pinMode(D5, OUTPUT);
}

void loop() {  
sensorValue = analogRead(sensorPin); 

Serial.println("Analog Value : ");
Serial.println(sensorValue);

if (sensorValue>limit) {
digitalWrite(D5, HIGH); 
}
else {
digitalWrite(D5, LOW);
 }
delay(1000); 
}
