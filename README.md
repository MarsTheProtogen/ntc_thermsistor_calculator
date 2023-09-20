[//]: <> (note, needs to be fixed from html to md)

<!DOCTYPE html>


<HTML>

<head>

  
</head>




<body>





<h1>Aurduino NTC Thermistor Reader</h1>



<p1>

<span class = "sub-header" >
  
Code and library for reading temperature of a Negative Thermal Coefficent (NTC) thermsistor 
<br>Function returns: <i>float <b>temperature</b></i></span><br><br>
<span class = "paragraph"  >
This program is designed to be very simple, so it does not calculate the range of
temperature<br> (based on tolerence of the part), or the self heating effect, 
as I find it to be neglitable for <br> a majority of use cases.
</span>

Utilises a voltage divider circut to mesure the temperature (shown below)
<br><br>

<p1>
<br>

  
<h2> Inputs (in order) and function syntax</h2>
A majority of these inputs can be found in the datasheet of your NTC thermsistor


<p>

<br>
<span class ="paragraph" >
  
pin# <b>V</b><sub>out</sub>- connected to aurduino A<sub>n</sub><br>

<b>V</b><sub>s</sub>- input voltage to the circut<br>

<b>T</b><sub>o</sub>- temperature normal resistance(<b>R</b><sub>o</sub>) is taken at (in kelvin[°C +273.15]), typicaly 25°c (298.15°k) <br>

<b>R</b><sub>o</sub>- resistance at <b>T</b><sub>o</sub> (in ohms)

<b>B</b> <sub>(<b>β</b>, beta) </sub>- coefficient the themsistor curve follows between resistance and temperature <br>

<b>R</b><sub>1</sub>- resistance of <b>R</b><sub>1</sub> in series with the NTC

bit depth  ( optional, 10 bits on Aurduino uno ) <br><br> </span>

<span class = "NTC_diagram" >
  
<img src="https://github.com/MarsTheProtogen/NTC-Thermistor-Reader/assets/99446685/e1dd8bfc-d568-43d6-aba8-65da9808127d)https://github.com/MarsTheProtogen/NTC-Thermistor-Reader/assets/99446685/e1dd8bfc-d568-43d6-aba8-65da9808127d" width="200" >
</span>

<br>
<h3><b>syntax</b></h3>  
<p>Under setup(): ntc_thermsistor_calculator instance_name()</p>
<p>To use the calculator: instance_name.calculate(int pin, float Vin, float To, long Ro, int B, long R1, int bit_depth)</p><br>

<br>
</p>


<h3>NOTES: </h3>

<p>
<!--sorry for getting sloppy here it was midnight when i was finishing this, I don't plan on fixing it-->
<b>V</b><sub>ss</sub> is the same as: <b>V</b><sub>s</sub>, <b>V</b><sub>in</sub>, <b>V</b>+
<br>

<b>V</b><sub>dd</sub> is the same as: <b>V</b><sub>d</sub>, <b>V</b><sub>0</sub>, <b>V</b>-
<br>

It is also important to know that thermsistors have a range of temperatures that they can be used in, you can check this with your datasheet.
<br>
If you'd like to learn more about NTCs, you may want to start <a href= "https://www.electronics-tutorials.ws/io/thermistors.html">here</a>.
</p>

<br><br><br><br><br><br><br>

</body>
</HTML>
