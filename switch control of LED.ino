
int S = D3;
int L = D6;
int S1;
void setup() {
  pinMode(L,OUTPUT);
  pinMode(S,INPUT_PULLUP);
}
 void loop() {
  S1 = digitalRead(S);
  if ( S1 == LOW) {
    digitalWrite(L,HIGH);
  }
  else {
    digitalWrite(L,LOW);
  }
 }
