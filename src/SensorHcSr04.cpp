/*
 * SensorHcSr04, library for taking HC-SR04 measurements
 * Created by nouc <nouc23@gmail.com>
 */

#include "Arduino.h"
#include "SensorHcSr04.h"

SensorHcSr04::SensorHcSr04()
{
}

SensorHcSr04::SensorHcSr04(unsigned int triggerPin, unsigned int echoPin)
{
	setup(triggerPin, echoPin);
}

SensorHcSr04::SensorHcSr04(unsigned int triggerPin, unsigned int echoPin, unsigned long timeout)
{
	setup(triggerPin, echoPin, timeout);
}

SensorHcSr04 &SensorHcSr04::setup(unsigned int triggerPin, unsigned int echoPin)
{
    _triggerPin = triggerPin;
    _echoPin    = echoPin;
    _timeout    = 0;

    pinMode(_triggerPin, OUTPUT);
    pinMode(_echoPin, INPUT);

    return *this;
}

SensorHcSr04 &SensorHcSr04::setup(unsigned int triggerPin, unsigned int echoPin, unsigned long timeout)
{
	setup(triggerPin, echoPin);
	_timeout = timeout;

	return *this;
}

SensorHcSr04 &SensorHcSr04::setTimeout(unsigned long timeout)
{
	_timeout = timeout;

	return *this;
}

unsigned long SensorHcSr04::getTimeout()
{
	return _timeout;
}

