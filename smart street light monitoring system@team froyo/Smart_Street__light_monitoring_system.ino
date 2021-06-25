//Including library files
#include <ESP8266WiFi.h>  
#include <PubSubClient.h>

// CHANGE TO YOUR WIFI CREDENTIALS
const char* ssid = "Ash";
const char* password = "killer1234";


// CHANGE TO YOUR DEVICE CREDENTIALS AS PER IN IBM BLUMIX

#define ORG "gsapfg"
#define DEVICE_TYPE "smart_street_light_monitor"
#define DEVICE_ID "froyo1234"
#define TOKEN "zVSAwtuPl?A&4?yOT_"  //  Authentication Token OF THE DEVICE
String command;
char server[] = ORG ".messaging.internetofthings.ibmcloud.com";
char topic[] = "iot-2/cmd/home/fmt/String";
char topic1[] = "iot-2/evt/Data/fmt/json";
char authMethod[] = "use-token-auth";
char token[] = TOKEN;
char clientId[] = "d:" ORG ":" DEVICE_TYPE ":" DEVICE_ID;
//Serial.println(clientID);
void callback(char* topic, byte* payload, unsigned int payloadLength);
WiFiClient wifiClient;
PubSubClient client(server, 1883, callback, wifiClient);

void setup() {
  
  Serial.begin(115200);
  Serial.println();
  pinMode(D5,OUTPUT);
  wifiConnect();
  mqttConnect();
}

void loop() {
  float l = analogRead(A0);
  if (l>1023) l = 1023;
  if(l>40  || command=="lighton"){
  analogWrite(D5,l-40);
  delay(1000);
  }
  else if(l<20 && command=="lightoff") digitalWrite(D5,LOW);
 
 
Serial.print("light: ");
Serial.print(l);
Serial.print(" lumens\t");
delay(500);
PublishData(l);
delay(500);
if (!client.loop()) {
mqttConnect();
  }
delay(100);
}

void wifiConnect() {
  Serial.print("Connecting to "); Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("nWiFi connected, IP address: "); Serial.println(WiFi.localIP());
}

void mqttConnect() {
  if (!client.connected()) {
    Serial.print("Reconnecting MQTT client to "); Serial.println(server);
    while (!client.connect(clientId, authMethod, token)) {
      Serial.print(".");
      delay(500);
    }
    initManagedDevice();
    Serial.println();
  }
}
void initManagedDevice() {
  if (client.subscribe(topic)) {
    Serial.println("subscribe to cmd OK");
  } else {
    Serial.println("subscribe to cmd FAILED");
  }
}

void callback(char* topic, byte* payload, unsigned int payloadLength) {
  Serial.print("callback invoked for topic: "); Serial.println(topic);

  for (int i = 0; i < payloadLength; i++) {
    //Serial.println((char)payload[i]);
    command += (char)payload[i];
  }
Serial.println(command);
if(command == "lighton"){
  digitalWrite(D5,HIGH);
  Serial.println("Light is Switched ON");
}
else if(command == "lightoff"){
  digitalWrite(D5,LOW);
  Serial.println("Light is Switched OFF");
}
command ="";
}



void PublishData(float light){
 if (!!!client.connected()) {
 Serial.print("Reconnecting client to ");
 Serial.println(server);
 while (!!!client.connect(clientId, authMethod, token)) {
 Serial.print(".");
 delay(500);
 }
 Serial.println();
 }
  String payload = "{\"d\":{\"light\":";
  payload += light;
  payload += "}}";
 Serial.print("Sending payload: ");
 Serial.println(payload);
 delay(1000);
  
 if (client.publish(topic1, (char*) payload.c_str())) {
 Serial.println("Publish ok");
 delay(1000);
 } else {
 Serial.println("Publish failed");
 }
}
