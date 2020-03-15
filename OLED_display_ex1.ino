#include<SPI.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define SW1 7
#define SW2 8
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire,OLED_RESET);
void setup() {  
  pinMode(SW1,INPUT);
  pinMode(SW2,INPUT);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,3);
  display.println("SW1");
  display.drawCircle(25,6,4,WHITE);
  display.setCursor(0,15);
  display.println("SW2");
  display.drawCircle(25,18,4,WHITE);
  display.setCursor(5,25);
  display.println("sw1 and sw2 are not activate.");
  display.display();
}

void loop() {
  if(digitalRead(SW1)==0&&digitalRead(SW2)==1){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,3);
    display.println("SW1");
    display.setCursor(0,15);
    display.println("SW2");
    display.fillCircle(25,6,4,WHITE);
    display.drawCircle(25,18,4,WHITE);
    display.setCursor(5,25);
    display.println("sw1 is activate but sw2 isn't activate.");
    display.display();
  }
  
  if(digitalRead(SW1)==1&&digitalRead(SW2)==0){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,3);
    display.println("SW1");
    display.setCursor(0,15);
    display.println("SW2");
    display.drawCircle(25,6,4,WHITE);
    display.fillCircle(25,18,4,WHITE);
    display.setCursor(5,25);
    display.println("sw1 isn't activate but sw2 is activate.");
    display.display();
  }

  if(digitalRead(SW1)==1&&digitalRead(SW2)==1){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,3);
    display.println("SW1");
    display.drawCircle(25,6,4,WHITE);
    display.setCursor(0,15);
    display.println("SW2");
    display.drawCircle(25,18,4,WHITE);
    display.setCursor(5,25);
    display.println("sw1 and sw2 are not activate.");
    display.display();
  }
}
