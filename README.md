# This is Arduino Uno R3 Code for "Color LED Controller" App, on which I've tested
I am still adding some features, like turning off and turning on of the strip.</br>
I am still figuring out how to achive brightness control from that app, or I may switch to different

# Devices I used:
Arduino Uno R3</br>
Full Color RGB LED Strip Driver Module Shield for Arduino UNO R3 STM32 AVR 12VDC V1.0 For MCU System (same as Full Color RGB LED Strip Driver Module Shield for Arduino STM32 AVR V1.0 CF)</br>
HC05 Bluetooth RF module

# Anyways
In future I want to adapt it to "Full Color RGB LED Strip Driver Module Shield for Arduino STM32 AVR 3.3V-5V" as my bluetooth device needs 5v pin from Arduino Uno R3 and I now have them connected on the same 5v pin which is not good, but it works without any issues. I have free 3.3v pin which I can use exactly for RGB strip controller, or another solution might be to change bluetooth on 3.3v version, but let's see. I may leave it as it is.</br>
I am also waiting for potentiometer and relay to control power from Vin, provided by some external power source (12v, I'll put Amperewise information later, but I had another one with 2A and it had some weird sound, not sure where from but it sounded like transformer was receiving huge load, so I put the one with less)</br>
I had to configure HC-05 board, like bluetooth name and baud rate for getting and displaying messages correclty over the bluetooth terminal.
