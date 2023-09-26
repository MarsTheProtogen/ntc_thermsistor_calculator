/*///////////////////////////////////////////////////////////////////////////
//															//
//		ntc_thermsistor_calculator- libary for auto calculating		//
//		the temperature of a negitive coefficient thermo-				//
//		resistor. Created by Mars The Prorogen, July 1, 2023.			//
//		realeased under CC BY-NC-SA 4.0							//
//															//
///////////////////////////////////////////////////////////////////////////*/

#ifndef ntcThermsistorCalculator_h
#define ntcThermsistorCalculator_h

#include "Arduino.h"

class ntcThermsistorCalculator
{

public:
	ntcThermsistorCalculator();
	float calculate(int pin, float Vin, float To, long Ro, int B, long R1, int bit_depth);

private:
	int _pin;
	float _Vin;
	float _To;
	long _Ro;
	int _B;
	long _R1;
	int _bit_depth;
};

#endif // ntc_thermsensor_calculator