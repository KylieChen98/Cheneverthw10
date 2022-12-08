#include<iostream>
#include<iomanip>
#include "analogIn.h"

using namespace std;

int main()
{
  AnalogIn analogInput(0);
  cout << "Using analogInput " << analogInput.getNumber() << " to read analog value." << endl;
  cout << endl;
  cout << "ADC Value is: " << analogInput.readAdcSample() << endl;
  cout << endl;
  cout << "Application completed." << endl;
}
