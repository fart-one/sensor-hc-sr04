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
    SensorHcSr04(unsigned int triggerPin, unsigned int echoPin);
    SensorHcSr04(unsigned int triggerPin, unsigned int echoPin, unsigned long timeout);
    SensorHcSr04 &setup(unsigned int triggerPin, unsigned int echoPin);
    SensorHcSr04 &setup(unsigned int triggerPin, unsigned int echoPin, unsigned long timeout);
    SensorHcSr04 &setTimeout(unsigned long timeout);
    unsigned long getTimeout();
    float measure();
  private:
    unsigned int _triggerPin;
    unsigned int _echoPin;
    unsigned long _timeout;
    void _sendTrigger();
    unsigned long _measurePulse();
    float _calculateDistance(unsigned long pulseWidth);
};

#endif