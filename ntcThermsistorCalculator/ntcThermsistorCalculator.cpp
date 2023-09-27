#include "Arduino.h"

#include "ntcThermsistorCalculator.h"

/*////////////////////////////////////////////////////////////////////////
//                                                                      //
//      when mesuring resistors, or calibrating, make sure              //
//      no conductive/hareted objects (like your hands)are touching,    //
//      this will cause improper mesurement                             //
//                                                                      //
////////////////////////////////////////////////////////////////////////*/



float ntcThermsistorCalculator::calculate(int pin, float To, long Ro, int B, long R1, float Vin = 5, int bit_depth = 10)
{

  _pin = pin;
  _Vin = Vin;
  _To = To;
  _Ro = Ro;
  _B = B;
  _R1 = R1;
  _bit_depth = bit_depth;

  // function use ex:
  // temperature = rt(probe, 5.0,  To,  Ro,  B,  R1, 10);

  /*////////////////////////////////////////////////////////////////////////////////////////////////////
  //                                                                                                  //
  //                            Formulas used for temperature:                                        //
  //                                                                                                  //
  //    Vout= (Vin/max value) * (read(pin)+1), +1 is to account for offset(computers start at zero)   //
  //    R2= (Vout*R1)/(Vin-Vout)                                                                      //
  //    based off of the Seinhart equasion for ntc semiconductors:                                    //
  //    1/(log(R2/Ro)*(1.0/B)+(1.0/To[k])) -273.15                                                    //
  //                                                                                                  //
  ////////////////////////////////////////////////////////////////////////////////////////////////////*/

  // set Analog pin to input
  pinMode(_pin, INPUT);

  // convert analog read into voltage
  // pow(2, bit_depth) converts bit depth to max value
  float Vout = ((_Vin / (pow(2, _bit_depth))) * (analogRead(_pin) + 1.0));

  // claculate resistance of NTC
  float R2 = ((Vout * _R1) / (_Vin - Vout));

  // calculate temperature using the Steinheart equasion
  float temp = log((R2 / _Ro));
  temp *= (1.0 / _B);
  temp += (1.0 / _To);
  temp = 1.0 / temp;

  // convert kelvin to C (k-273.15=c), surprisingly easy if you've never used it before
  temp -= 273.15;

  // return temperature as a value
  return (temp);
}
