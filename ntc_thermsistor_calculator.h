/*///////////////////////////////////////////////////////////////////////////
//															//
//		ntc_thermsistor_calculator- libary for auto calculating		//
//		the temperature of a negitive coefficient thermo-				//
//		resistor. Created by Mars The Prorogen, July 1, 2023.			//
//		realeased under CC BY-NC-SA 4.0							//
//															//
///////////////////////////////////////////////////////////////////////////*/

#ifndef ntc_thermsensor_calculator
#define ntc_thermsensor_calculator

#include "Arduino.h"

class ntc_thermsistor_calculator
{
private:
	int _pin;
	float _Vin;
	float _To;
	long _Ro;
	int _B;
	long _R1;
	int _bit_depth = 10;

public:
	ntc_thermsistor_calculator();
	float calculate(int pin, float Vin, float To, long Ro, int B, long R1, int bit_depth);
};

#endif // ntc_thermsensor_calculator