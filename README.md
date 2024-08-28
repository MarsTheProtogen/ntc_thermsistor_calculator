[//]: <> (note, needs to uplod image for the ntc diagram)

# Aurduino NTC Thermistor Reader

Code and library for reading temperature of a Negative Thermal Coefficent (NTC) thermsistor
Function returns: <i>float <b>temperature</b></i>

This program is very simple, so it does not calculate the range of temperature
(based on tolerence of the part), or the self heating effect,
as I find it to be neglitable for majority of use cases.
<br><br>

### [Download link for the zip Library](https://github.com/MarsTheProtogen/ntcThermsistorCalculator/blob/3f9f5748b12179a5a9c11175c609fd50e9f29678/ntcThermsistorCalculator.zip)

[https://github.com/MarsTheProtogen/ntcThermsistorCalculator/blob/3f9f5748b12179a5a9c11175c609fd50e9f29678/ntcThermsistorCalculator.zip](https://github.com/MarsTheProtogen/ntcThermsistorCalculator/blob/3f9f5748b12179a5a9c11175c609fd50e9f29678/ntcThermsistorCalculator.zip)

<br><br>

### Inputs (in order) and function syntax

A majority of these inputs can be found in the datasheet of your NTC thermsistor

pin# <b>V</b><sub>out</sub>- connected to aurduino A<sub>n</sub><br>

<b>V</b><sub>s</sub>- input voltage to the circut<br>

<b>T</b><sub>o</sub>- temperature normal resistance(<b>R</b><sub>o</sub>) is taken at (in kelvin[°C +273.15]), typicaly 25°c (298.15°k) <br>

<b>R</b><sub>o</sub>- resistance at <b>T</b><sub>o</sub> (in ohms)

<b>B</b> <sub>(<b>β</b>, beta) </sub>- coefficient the themsistor curve follows between resistance and temperature <br>

<b>R</b><sub>1</sub>- resistance of <b>R</b><sub>1</sub> in series with the NTC

bit depth ( optional, 10 bits on Aurduino uno )

<br><br>

### Voltage divider circut to mesure the temperature

<img src=/imgs/NTC%20diagam-01.png width = 60%>

<br><br>

### usage example for a basic reflow oven

<b>the timings are divided by 100 (t / 100), this prevents issues with the size of numbers</b>

temperatures are in Celsius... what else would they be in? Fahrenheit?! _ppfhhh!_

note that the examples does not use the library itself, but the original function as "rt"

reflow profile can be adjusted with the arrays "times" and "temps"

<br><br>

### <b>syntax</b>

ntcThermsistorCalculator.calculate(int pin, float Vin, float To, long Ro, int B, long R1, int bit_depth)

<br><br>

## NOTES:

<!--sorry for getting sloppy here it was midnight when i was finishing this, I don't plan on fixing it-->

<b>V</b><sub>ss</sub> is the same as: <b>V</b><sub>s</sub>, <b>V</b><sub>in</sub>, <b>V</b>+

<b>V</b><sub>dd</sub> is the same as: <b>V</b><sub>d</sub>, <b>V</b><sub>0</sub>, <b>V</b>-

It is also important to know that thermsistors have a range of temperatures that they can be used in, you can check this with your datasheet.

There is example of using the library in the examples folder as most other libraries

If you'd like to learn more about NTCs, you may want to start [here](https://www.electronics-tutorials.ws/io/thermistors.html).

<br><br>
