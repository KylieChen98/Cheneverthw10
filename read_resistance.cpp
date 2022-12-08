#include<iostream>
#include<iomanip>
#include "analogIn.h"

using namespace std;

float getResistance(int adcVal)
{
  float cur_voltage = adcVal * (1.80f/4096.0f);
  float resistance = (cur_voltage * 10000.0f) / (1.80f - cur_voltage);
  return resistance;
}

int main()
{
  AnalogIn analogInput(0);
  cout << "Using analogInput " << analogInput.getNumber() << " to read ADC value." << endl;
  cout << "ADC Value is: " << analogInput.readAdcSample() << endl;

  float resistance = getResistance(analogInput.readAdcSample());
  cout << "Resistance is: ";
  if(resistance > 999)
  {
    cout << resistance/1000.0f << " K Ohms." << endl;
  }
  else
  {
    cout << resistance << " Ohms." << endl;
  }
  cout << endl << "Program Complete." << endl;
}
