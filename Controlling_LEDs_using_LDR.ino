int L1=D0;
int L2=D2;
int L3=D4

void setup() {
  Serial.begin(9600);
  pinMode(L1,OUTPUT);
  pinMode(L3,OUTPUT);  
  pinMode(L2,OUTPUT);

}

void loop() {

  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if (sesorValue < 500){
    digitalWrite(L1,HIGH);
    digitalWrite(L2,LOW);
    digitalWrite(L3,LOW);
  }
  else if (sesorValue < 700 ){
    digitalWrite(L1,HIGH);
    digitalWrite(L2,LOW);
    digitalWrite(L3,LOW);
  }
  else if (sesorValue < 500){
    digitalWrite(L1,HIGH);
    digitalWrite(L2,LOW);
    digitalWrite(L3,LOW);
  }
}
