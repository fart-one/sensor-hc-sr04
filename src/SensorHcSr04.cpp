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

float SensorHcSr04::measure()
{
  _sendTrigger();
  return _calculateDistance(_measurePulse());
}


void SensorHcSr04::_sendTrigger()
{
  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_triggerPin, LOW);
}

unsigned long SensorHcSr04::_measurePulse()
{
  unsigned long pulse;

  if (_timeout) {
    pulse = pulseIn(_echoPin, HIGH, _timeout);
  } else {
    pulse = pulseIn(_echoPin, HIGH);
  }

  return pulse;
}

float SensorHcSr04::_calculateDistance(unsigned long pulseWidth)
{
  return pulseWidth / 5800.0;
}