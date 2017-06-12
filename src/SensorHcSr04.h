/*
 * SensorHcSr04, library for taking HC-SR04 measurements
 * Created by nouc <nouc23@gmail.com>
 */
 
#ifndef SensorHcSr04_h
#define SensorHcSr04_h

#include "Arduino.h"

class SensorHcSr04
{
  public:
    SensorHcSr04();
  private:
    int _triggerPin;
    int _echoPin;
};

#endif