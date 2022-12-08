#include "derek_LED.h"
#include "analogIn.h"
#include "GPIO.h"

#define HIGH 1
#define LOW 0

using namespace exploringBB;
using namespace std;

int main(int argc, char* argv[])
{
  cout << "Beginning GPIO Application." << endl;

  LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
  
  leds[1].turnOn();
  leds[3].turnOn();
  leds[2].flash("50");

  AnalogIn analogInput(0);

  cout << "Using AnalogInput " << analogInput.getNumber() << " to read ADC Value." << endl; 
  cout << "ADC Value is: " << analogInput.readAdcSample() << endl;

  GPIO outGPIO(60), inGPIO(46);
  inGPIO.setDirection("INPUT");
  outGPIO.setDirection("OUTPUT");
  int button_val = inGPIO.getValue();
  if(button_val=="LOW")
  {
    outGPIO.setValue("HIGH");
    cout << "Push Button is pressed." << endl;
  }
  else
  {
    outGPIO.setValue("LOW");
    cout << "Push Button is not pressed." << endl;
  }
  cout << "GPIO Application is complete." << endl;
  return 0;
}
