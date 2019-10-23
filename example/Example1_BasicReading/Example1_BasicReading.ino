/*
  By: Brandon Williams
  SparkFun Electronics
  Date: September 18th, 2019
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example just reads a raw data value from the sensor and prints to serial.

  <product URL>
 */

#include <SparkFun_ADS1015_Arduino_Library.h>
#include <Wire.h>

ADS1015 irsensor;                   //Initialize using ADS1015 library
float multiplier;

void setup() {
  Serial.begin(9600);
  Wire.begin();   //Join I2C bus

  if(irsensor.begin() == false){
    Serial.println("Device not found. Check wiring, then restart.");
    while(1);
  }
  multiplier = irsensor.getMultiplier();
}

void loop() {
  int data;
  data = irsensor.getAnalogData(0);   //Retrieve raw data value from sensor
//  Serial.print("ADC input voltage: ");
//  Serial.print(data * multiplier);
//  Serial.println("mV");
  Serial.println(data * multiplier);
  delay(50);                         //Sample data reading every half second
}
