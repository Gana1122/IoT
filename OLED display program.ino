#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET D5
/* Object named display, of the class Adafruit_SSD1306 */
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int Switch = D3;
int Led = D6;
int Switch1;

void setup()   {
  pinMode(Led,OUTPUT);
  pinMode(Switch,INPUT_PULLUP);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); /* Initialize display with address 0x3C */
  display.clearDisplay();
  display.setTextSize(1);  /* Select font size of text. Increases with size of argument. */
  display.setTextColor(WHITE);
}

void loop() {
 Switch1 = digitalRead(Switch);
 if (Switch1 == LOW){
  digitalWrite(Led,HIGH);
  display.clearDisplay(); /* Clear display */
  display.setCursor(20,50);  /* Set x,y coordinates */
  display.println("LED ON");
  display.display();
 }
 else if (Switch1 == HIGH){
  display.clearDisplay();
  display.setCursor(20,50);  /* Set x,y coordinates */
  display.println("LED OFF");
  digitalWrite(Led,LOW);
  display.display();
}
}
