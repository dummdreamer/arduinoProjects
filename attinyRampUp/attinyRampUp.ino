/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
#include <SoftwareSerial.h>;

#define RX    3   
#define TX    4 

//SoftwareSerial Serial(RX, TX);

  float frequency_kHz = 30.0;
  float rampUp_s = 5.0;
  float duty_pct = 0.1;
  
  float delayON_us = 1000*(duty_pct)/frequency_kHz;
  float delayOFF_us = 1000*((1-duty_pct))/frequency_kHz;
  float incStep_us = (delayOFF_us*delayOFF_us)/(rampUp_s*1000000.0);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH); 
  delayMicroseconds(delayON_us);
  //Serial.println(delayON_us);
  }

// the loop function runs over and over again forever
void loop() {
  if (delayOFF_us > 0) {
    digitalWrite(0, LOW); 
    delayMicroseconds(delayOFF_us);   
    digitalWrite(0, HIGH);
    delayMicroseconds(delayON_us);
    delayOFF_us = delayOFF_us - incStep_us;
    delayON_us = delayON_us + incStep_us;
    //Serial.print(delayON_us);
  }
}
