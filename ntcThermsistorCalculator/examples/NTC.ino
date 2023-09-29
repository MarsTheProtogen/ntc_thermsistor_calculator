#include <ntcThermsistorCalculator.h>ntc

//pin the ntc is connected to
int  pin=  A1;

//tmperature Ro is taken at
float To = 25.0 + 273.15;

//Resistance of NTC at To
long Ro = 100000;

//
int B = 4014;

//resistance of the resistor in series with the NTC
long R1 = 100100;

ntcThermsistorCalculator ntcThermsistorCalculator;
void setup(){
  Serial.begin(9600);

}
void loop(){Serial.println(ntcThermsistorCalculator.calculate( pin,  To,  Ro,  B,  R1));}