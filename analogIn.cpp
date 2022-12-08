#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include "analogIn.h"

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

using namespace std;

AnalogIn::AnalogIn(){}

AnalogIn::AnalogIn(unsigned int n)
{
  number = n;
}

void AnalogIn::setNumber(unsigned int n)
{
  number = n;
}

int AnalogIn::readAdcSample()
{
  int adc_val;
  std::stringstream ss;
  ss << ADC_PATH << number << "_raw";
  std::fstream fs;
  fs.open(ss.str().c_str(), std::fstream::in);
  fs >> adc_val;
  fs.close();
  return adc_val;
}

AnalogIn::~AnalogIn()
{
 cout << "Deleting the AnalogIn object before exiting." << endl;
}
