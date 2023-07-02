/* Released into the public domain */
//Adafruit Librairies @ https://learn.adafruit.com/adafruit-all-about-arduino-libraries-install-use/arduino-libraries
// © DevIoTCanada RFT Enr. Non Commercial usage liscense granted.
#include "Adafruit_SHT31.h"
#include <Wire.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_SH110X.h>
Adafruit_SHT31 sht31 = Adafruit_SHT31();
#define i2c_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define NUMFLAKES 6
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
void setup() {
      Serial.begin(9600);
      delay(10);
      Serial.println("SHT31 test");
      if (! sht31.begin(0x44)) {
      Serial.println("Couldn't find SHT31");
      while (1) delay(1);
      }
        if(!display.begin(i2c_Address, true)) {
    Serial.println(F("Display allocation failed"));
    for(;;);
  }
  delay(1000);
  display.clearDisplay();
}
void loop() {
  
    float t = sht31.readTemperature();
    float h = sht31.readHumidity();
    
    if (! isnan(t)) {Serial.print("Temp *C = "); Serial.println(t);}
    else {    
    t=0.0;
    Serial.println("Failed to read temperature");
    }
    if (! isnan(h)) {Serial.print("Hum. % = "); Serial.println(h);}
    else { 
    h=0.0;
    Serial.println("Failed to read humidity");    
    }
    Serial.println();
    delay(100);
    display.clearDisplay();
    
    // display temperature
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    delay(2000);
    display.setTextSize(1);
    display.setCursor(0,7);
    display.print("Temperature: ");
    display.setTextSize(2);
    display.setCursor(0,18);
    display.print(t);
    display.print(" ");
    display.setTextSize(1);
    display.cp437(true);
    display.write(167);
    display.setTextSize(2);
    display.print("C");
    
    // display humidity
    display.setTextSize(2);
    display.setCursor(0, 45);
    display.print(h);
    display.print("%");
    display.setTextSize(1);
    display.setCursor(74, 50);
    display.print(" ");
    display.print("Rel H");  
    display.display(); 
}
// 