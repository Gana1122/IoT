#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(D4, D8); // CE, CSN

const byte address[7] = "Welcome to SIP 2019";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  for (int i = 1; 1<=10; i++) { 
  radio.write(&i, sizeof(i));
  delay(1000);
}
}
