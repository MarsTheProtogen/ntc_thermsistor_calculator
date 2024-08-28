#include <Arduino.h>

// note all values are in metric
/*
/             reflow oven controls
/
/       Code created by Mars the Protogen
/
/⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠀⠀⠀⠀⠐⠁⠱⡀⠀⠀⠀⡠⢪⣬⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠀⠀⠀⢠⠃⢀⢰⢡⣀⡠⠎⢱⡋⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠀⠀⢠⡌⡐⠁⠜⡪⠊⠁⢠⡟⠁⣸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠀⠀⢸⠈⠁⠀⠈⠀⢀⠔⢱⣅⣰⡽⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠀⡠⠊⠉⠉⠉⠐⣲⡥⠚⠉⠀⡄⠹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⡸⠊⠉⣩⡍⢱⠪⠂⢺⠆⢀⠜⠀⠑⢢⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⡰⠁⢠⣞⡡⠃⠸⡔⠄⢰⠕⡡⠆⠀⠈⠁⡰⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠰⠁⡀⠀⠀⢀⡼⠂⢈⣷⠿⠛⡇⠀⠀⠀⢈⣰⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠢⢅⣠⡟⣘⢥⢶⠁⠀⠀⠀⠇⠀⠀⠀⠆⢏⠉⠚⢗⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠀⢀⣥⣴⡥⡘⠀⠀⠀⠀⠘⢄⠀⣦⡜⠢⡑⠢⠤⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠰⣫⢿⠇⢰⠃⣰⠀⠀⣰⠀⢸⠑⢇⠀⠀⠀⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⢸⠁⠈⠀⠸⣰⠹⡄⠰⠁⢣⠃⠀⠀⢱⢄⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠀⣇⢰⡀⠀⠀⠀⠐⠃⠀⠀⠀⠀⠀⠀⠇⠀⠀⠀⠀⢡⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠰⠁⠀⠱⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠶⣄⡠⠤⢄⠀⡏⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⢀⠆⠀⠀⠀⠸⢦⠤⠤⠤⠤⢤⠀⠒⠈⠸⠊⠀⠀⠀⠈⠁⠀⢻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⡠⠊⠀⠓⠢⣀⠆⢨⠀⠀⠀⠀⢸⠀⢀⡜⠁⠀⠀⠀⠀⣠⢞⠤⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠘⢀⠀⠀⠀⠈⠦⢊⡄⠀⢄⠀⢸⡠⠋⠀⠀⠀⢀⠤⢞⡉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠐⢹⢇⠀⠀⠀⠸⡀⢧⣤⣀⡠⠊⠀⠀⢀⡠⠚⠁⢠⠔⡳⢦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⢀⢴⠧⡀⠀⠀⢃⠈⢦⠜⠀⠀⢀⡔⠁⠀⠀⠀⡄⢰⠁⠈⢻⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⢠⡲⠁⠀⠘⡄⠀⠘⣄⣆⠀⠀⠀⡾⠀⠀⠀⠀⠀⡇⠸⡀⠀⠘⣧⠑⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⢸⠁⠀⠀⠀⡇⠀⠀⠸⣿⡄⡆⣸⡇⠀⠀⠀⠀⠀⢠⠀⠇⠀⠀⢻⠀⠀⠀⠤⠭⠿⠋⠀⠀⠀⠀⢤⡀⠀⠀⠀⠀
/⠀⠀⠀⠀⠀⣇⣀⠀⣄⢽⠈⠛⠻⡇⠀⠀⠀⠀⠀⠀⢃⠘⢄⢀⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠑⣆⠀⠀
/⠠⡀⠀⠀⠀⠘⢌⡯⣸⡾⠀⢀⠆⠰⡀⠀⠀⠀⠀⠀⠀⠑⠤⠴⣇⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢤⡈⢂⡀
/⠀⠘⢦⣀⠀⢀⣀⡀⠤⠄⠒⢧⡀⠀⠱⡀⠀⠀⠀⠀⠀⠀⢀⠆⠀⠙⠶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡈⠿⠃
/⠀⠀⠀⠙⠦⡀⠀⠀⠀⠀⠀⠉⠒⠂⠤⡘⢄⡀⠀⠀⣀⢴⡋⠱⣐⣦⡀⠀⠉⠛⠲⢤⣄⠀⠀⢀⡠⠐⠊⠀⠀⠀
/⠀⠀⠀⠀⠀⠈⠒⢄⠀⠀⠀⠀⠀⠀⢈⡇⠈⡇⠉⠉⠀⠃⡘⡄⠸⠃⠈⠂⠤⢀⣀⡀⠈⣙⣢⡀⠀⠀⠀⠀⠀⠀
/⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⢰⠞⠁⠀⡇⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⠀⢠⠃⠀⠀⠀⡇⠀⠀⠀⠀⠹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠀⠀⠀⠀⢀⡜⠀⠀⠀⢀⠆⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⢀⡔⠀⢠⠒⠉⡀⠀⠀⢀⠎⠀⠀⠀⢀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⢮⡀⠠⡆⠀⠘⢄⣀⠴⠊⠀⠀⠀⡰⠚⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠈⠉⠁⠀⠈⠁⠀⠀⠀⠀⠀⠀⢧⠗⢲⠁⠀⠈⠉⠀⠱⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨⣀⢈⡇⠀⠀⢀⡀⡰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠚⠣⠠⣿⠼⠌⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
/////////////////////////////////////////////////////*/

/*
////////////////////////////////
//                            //
//      initial variables     //
//                            //
////////////////////////////////
*/

// inputs

// temperature probe input
int tp = A1;

// button input
int button = 2;

// states

// previous button state
bool prev = false;

// check if button has been reset to LOW
bool an = true;

// wether or not to heat up
bool heat = true;

// weather or not the oven passes the goal temperature
bool pass = false;

// start time
int s_t = 0;

// how long  since start in ms
unsigned int t = 0;

// temperature of the probe
float temp = 0.0;

// goal temperature to the nearest degree
float gt = 25.0;

// constant derived from the exponential formula
const float m = 28.2;

// resistance of NTC
float R2 = 100000;


/*
//////////////////////////////////////////////////////////////
//                                                          //
//      NOTICE: relays draw ~70ma, transistor is needed     //
//                                                          //
//////////////////////////////////////////////////////////////
*/

// pin for relay, normaly off

int relay = 4;

// formulas

// tempurature formula

float b = 0.0;
float p = 0.0;

// time for goal tempurature calculation
// start time is under sense variables

// rate for calculating gt

float curve = 0.0;

float To = 25.0 + 273.15;

long Rot = 100000;

int B = 4014;

long R1 = 100100;

// set up variables for temperatre over time, the first time is the initial temperatre (should be at 0ms)

// time for each goal temperature points in ms/100
int times[] = {0, 900, 1800, 2400};

// temperature @ time
float temps[] = {25.0, 150.0, 175.0, 217.0};

void setup()
{

  // start serial protocal, debugging only

  Serial.begin(9600);

  // check the times and temps mach
  if (sizeof(times) != sizeof(temps))
  {
   Serial.println("times and temps do not mach up");
  };

  Serial.println("starting, times and temps match");

  // set pins to input/outputs

  pinMode(temp, INPUT);
  pinMode(button, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(tp, INPUT);
}

// temperature curve calc for gt@t [goal temperature @ t] input is time
int n = 0;

void goalTemp(int t, float temp)
{
  Serial.println("gting");
  // note: the time is /100, this prevents issues in the code
  for (int i = 0; i < sizeof(times); i++)
  {
    if (t > 0 && t < times[n])
    {
      gt = (temps[n - 1] + (((temps[n] - temps[n - 1]) / (float(times[n] - times[n - 1]))) * t));
      n = 0;
      break;
    }
    else if (t > times[sizeof(times)])
    {
      gt = temps[0];
      n = 0;
      break;
    }

    else
    {
      n = 0;
      break;
    }
  }
  n++;

  Serial.print("gt=");
  Serial.println(gt);
  Serial.print("t=");
  Serial.println(t);
  Serial.println(n);
}

// read temperature based off of v (voltage), max bit depth of 10 from analog, 12 in pi pico

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

  // check probe temp

  // run equsion based of of value from analog read
  temp = rt(tp, 5.0, To, Rot, B, R1, 10);

  Serial.println(temp);

  // check if temp is below or above gt, turn relay on accordingly
  if (heat == false)
  {

    gt = temps[0];

    if (temp < gt)
    {
      // turn on heating if goal temp is not met @ tome

      Serial.println("high");
      digitalWrite(relay, HIGH);
    }

    else if (temp > gt)
    {
      // turn heating off if the pemperatre is above goal temperature
      digitalWrite(relay, LOW);

      Serial.println("low");
    }

    Serial.println("idle");
  }

  if (heat == true)
  {
    Serial.println("checking heating 2");
    // calculate time in ms (based on syst clk)
    // the /100 forms unsigned into a int, shrinks by 2 decimals
    // will also cut of everything past the decimal point (modulus not required/needed)
    t = (millis() / 100);

    // Serial.print("mil= ");
    // Serial.println(t);
    t -= s_t;

    // goal temperature controll based off of time in ms
    //  run goal temp calculator
    goalTemp(t, temp);
    if (temp < gt)
    {
      // turn on heating if goal temp is not met @ tome

      // Serial.println("high");
      digitalWrite(relay, HIGH);
    }

    else if (temp > gt)
    {
      // turn heating off if the pemperatre is above goal temperature
      digitalWrite(relay, LOW);

      // Serial.println("low");
    }
    // Serial.print("st=");
    // Serial.println(s_t);

    // Serial.print("t=");
    // Serial.println(t);
  }

  if (an == false)
  {
    if (digitalRead(button) == LOW)
    {
      an = true;

      Serial.println("an = true");
      return;
    }
  }

  // check button press, changes what runs
  if (an == true)
  {
    if (prev == false)
    {
      if (digitalRead(button) == HIGH)
      {
        s_t = (millis() / 100);
        heat = true;
        prev = true;
        an = false;

        Serial.println("an = false, heating");

        return;
      }
    }

    if (prev == true)
    {
      if (digitalRead(button) == HIGH)
      {

        // reset functions, this should be fixed to have a reset function
        prev = false;
        heat = false;
        an = false;
        pass = false;

        Serial.println("an = false, !heating");

        return;
      }
    }
  }
}
