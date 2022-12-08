#!/bin/bash

echo Building the test_analog application.

g++ test_analog.cpp analogIn.cpp -o test_analog

chmod u+x test_analog

echo test_analog application built successfully

echo Building the GPIO Application.

g++ gpioApp.cpp derek_LED.cpp analogIn.cpp GPIO.cpp -o gpioApp -pthread >> /dev/null
chmod u+x gpioApp

echo GPIO Application built successfully.

echo Configuring GPIO Pins.

config-pin p9.12 gpio
config-pin p8.16 gpio.pu

echo Pins Configured

echo Building Resistance Calculator Application.

g++ read_resistance.cpp analogIn.cpp -o read_resistance
chmod u+x read_resistance

echo Resistance Calculator Built Successfully..

chmod u+x computeFunction.py
chmod u+x square.py
chmod u+x cube.py
