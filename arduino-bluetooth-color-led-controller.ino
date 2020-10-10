#include <SoftwareSerial.h>

#include "FastLED.h"

#define NUM_LEDS 2
#define DATA_PIN 3
#define CLOCK_PIN 2

int Brightness;
int Red;
int Green;
int Blue;
int unknownVal;
int White;

  CHSV hsvs[NUM_LEDS];
  CRGB leds[NUM_LEDS];

SoftwareSerial Bluetooth(10, 9); // RX, TX

void setup() {
  Bluetooth.begin(38400);
  Serial.begin(9600);
  FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  FastLED.clear();
  Serial.println("Strip management");
}

void loop() {
  int control = Bluetooth.parseInt();
  if (control == 5){
    turnLed(Bluetooth.parseInt());
  }
  else if (control == 2){
    Brightness = Bluetooth.parseInt();
    Red = Bluetooth.parseInt();
    Green = Bluetooth.parseInt();
    Blue = Bluetooth.parseInt();
    unknownVal = Bluetooth.parseInt();
    White = Bluetooth.parseInt();
    if (Bluetooth.available() > 0)
    {
      SetLight();
    }
    Bluetooth.flush();
  }
  else if (control == 0){
    Serial.println("Standby");
  }
  else {
    Serial.print("Unknown command: ");
    Serial.print(control);
    Serial.println();
  }
}

void turnLed(int on){
  if (on == 0){
      Serial.println("Off");
      turnOff();    
    }
    else if (on = 1) {
        Serial.println("ON");
        SetLight();
    }
    else {
      Serial.print("Unknown parameter: ");
      Serial.print(on);
      Serial.println();
    }
}

void turnOff(){
  FastLED.clear();  // clear all pixel data
  FastLED.show();
}

void SetLight() { 
  printRGBStatus();
  
  FastLED.setBrightness(Brightness);
  FastLED.setTemperature(White);
  
  leds[0].setRGB(Red, Green, Blue);
  leds[1].setRGB(Red, Green, Blue);
  
  FastLED.show();
}

void printRGBStatus(){
  Serial.print("R: ");
  Serial.print(Red);
  
  Serial.print(", G: ");
  Serial.print(Green);
  
  Serial.print(", B: ");
  Serial.print(Blue);
  Serial.println();
    
  Serial.print("Overall Brightness: ");
  Serial.print(Brightness);
  Serial.println();

  Serial.print("Overall Temperature: ");
  Serial.print(White);
  Serial.println();
  
  Serial.print("Overall unknownVal: ");
  Serial.print(unknownVal);
  Serial.println();
}
