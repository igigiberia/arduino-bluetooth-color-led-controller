#include <SoftwareSerial.h>
#include "RGBdriver.h"
RGBdriver Driver(2,3);
SoftwareSerial Bluetooth(10, 9); // RX, TX
void setup() {
  Bluetooth.begin(38400);
  Serial.begin(9600);
  printString("Strip management\0\n");
}
void printString(String printme){
    //Bluetooth.println(printme);
    Serial.println(printme);
}
void loop() {

  int redInt = Bluetooth.parseInt();
  int greenInt = Bluetooth.parseInt();
  int blueInt = Bluetooth.parseInt();
  redInt = constrain(redInt, 0, 255);
  greenInt = constrain(greenInt, 0, 255);
  blueInt = constrain(blueInt, 0, 255);
  if (Bluetooth.available() > 0)
  {
    SetLight(redInt, greenInt, blueInt);
    Bluetooth.flush();
  }
}
void SetLight(int red, int green, int blue)  
{ 
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(" Green: ");
  Serial.print(green);
  Serial.print(" Blue: ");
  Serial.print(blue);
  Serial.println();
  Driver.begin();
  Driver.SetColor(red, green, blue); 
  Driver.end();
}
