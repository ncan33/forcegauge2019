/*

 STIF strain gauge code
 By: Nejat Can
 Date: January 20th, 2020
 License: STIF by Nejat Can is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.

 This code uses "HX711.h" from the following HX711 library: https://github.com/bogde/HX711

 Circuit details for this device can be found at: https://github.com/ncan33/STIF-2019/tree/master/circuit

*/

#include "HX711.h"


//IMPORTANT: REFER TO README.md FOR CODE TO WORK PROPERLY. DEVICE NEEDS TO BE CALIBRATED.
//IMPORTANT: For research application, read the special section in README.md

float calibration_factor = 100000; //README.md describes how to calibrate

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(7, 8); // digital output pin at 7, clock pin at 8
  scale.set_scale(calibration_factor);
  scale.tare();

  Serial.println("Readings");
}

void loop() {
  Serial.print(scale.get_units(), 1);
  Serial.print(" lbs"); //units are user defined. redefining units requires calibration. edit variable calibration_factor with known loads.
  Serial.println();
 
//IMPORTANT: For research application, removing the unit as a string from the serial print is highly recommended to output only float data.
 
//Uncomment the next line if you wish to manipulate the sampling rate
//delay(1000)
}
