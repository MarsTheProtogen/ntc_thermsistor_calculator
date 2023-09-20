#include <Arduino.h>

/*////////////////////////////////////////////////////////////////////////
//                                                                      //
//      when mesuring resistors, or calibrating, make sure              //
//      no conductive/hareted objects (like your hands)are touching,    //
//      this will cause improper mesurement                             //
//                                                                      //
////////////////////////////////////////////////////////////////////////*/

float temperature = 0.0;

int probe = A1;

void setup()
{

  // set probe pin (A1) to input
  pinMode(probe, INPUT);
}

// the listed resistance of ntc at To (typicaly 25c)
long Ro = 100000;

// the temperature Ro is listed at (typicaly 25c), found in the datasheet
//  NOTE: + 273.15 to convert c to k
float To = 25.0 + 273.15;

// resistance of resistor in series with NTC [ohms]
long R1 = 90600;

// beta, greek symbol for b(beta), found in the part datasheet,
//  sometimes also seen as a capital B
float B = 4014.0;

// resistance of the ntc, this is a float
// because it is being calculated, not stored
float R2 = 100000.0;

// NOTE: aurduino max bit depth of 10 from analogRead() vs 12 in pi pico

float rt(int pin, float Vin, float To, long Ro, int B, long R1, int bit_depth = 10)
{

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

  // convert analog read into voltage
  // pow(2, bit_depth) converts bit depth to max value
  float Vout = ((Vin / (pow(2, bit_depth))) * (analogRead(pin) + 1.0));

  // claculate resistance of NTC
  float R2 = ((Vout * R1) / (Vin - Vout));

  // calculate temperature using the Steinheart equasion
  float temp = log((R2 / Ro));
  temp *= (1.0 / B);
  temp += (1.0 / To);
  temp = 1.0 / temp;

  // convert kelvin to C (k-273.15=c), surprisingly easy if you've never used it before
  temp -= 273.15;

  // return temperature as a value
  return (temp);
}

void loop()
{

  // using the function to set external value tp the calculated temperatre
  temperature = rt(probe, 5.0, To, Ro, B, R1, 10);
}
