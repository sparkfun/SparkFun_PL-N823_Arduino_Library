/*
  By: Brandon Williams
  SparkFun Electronics
  Date: September 18th, 2019
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example samples background readings for calibration 
  and uses that to trigger 'found' events..

  <product URL>
 */

#include <SparkFun_ADS1015_Arduino_Library.h>
#include <Wire.h>

ADS1015 irsensor;                   //Initialize using ADS1015 library

int cal_value;

void calibration(int cal_size){
    int cal_sum;
    Serial.println("Gathering Calibration Value");
    for(int i = 0; i < cal_size; i++){
      cal_sum+=irsensor.getAnalogData(0);
      delay(500);                   //Sample every half second
    }
    cal_value = cal_sum / cal_size;
    Serial.print("Calibration value: ");
    Serial.println(cal_value);
  }

void setup() {
  Wire.begin();
  Serial.begin(9600);

  if(irsensor.begin(Wire,100000,ADS1015_ADDRESS_GND) == false){
    Serial.println("Device not found. Check wiring, then restart.");
    while(1);
  }
}

void loop() {
  int data;

  calibration(20);
  int tolerance = cal_value + 500;    //minimum value to indicate an 'event'
  while(0){
    data = irsensor.getAnalogData(0);   //Retrieve raw data value from sensor
    if(data > tolerance){
      Serial.println("Event Triggered! Great Scott, it works!");
    }
    delay(500);                         //Sample data reading every half second
  }
}
