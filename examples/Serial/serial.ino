#include <SensorHcSr04.h>

#define TRIGGER_PIN 5
#define ECHO_PIN 4

SensorHcSr04 sensor;

// initialize configuration in constructor
SensorHcSr04 sensor1(TRIGGER_PIN, ECHO_PIN);
SensorHcSr04 sensor2(TRIGGER_PIN, ECHO_PIN, 30000);

void setup() {
  Serial.begin(9600);

  // setup pins
  sensor.setup(TRIGGER_PIN, ECHO_PIN);

  // set sensor timeout (max_measure_distance_in_meters * 5800)
  sensor.setup(TRIGGER_PIN, ECHO_PIN, 30000);

  // or set after setup
  sensor
    .setup(TRIGGER_PIN, ECHO_PIN)
    .setTimeout(30000);
}

void loop() {

  // take measure
  Serial.println(sensor.measure());
  
  delay(100);

}