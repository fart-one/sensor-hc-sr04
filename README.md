# Sensor HC-SR04 Library

Library for handle Measuremets from HC-SR04 sensor

## Getting Started

Clone this repository into %ARDUINO_HOME_DIR%/libraries, and restart Arduino IDE.
New library should appear in Sketch -> attach library.
 
### Usage
Declare globally:
```
SensorHcSr04 sensor;
setup() {
	sensor
		.setup(5, 4) // trigger pin, echo pin
		.setTimeout(30000) // optionaly set max sensor pulse time (distance_in_meters * 5800)

	// or set all parameters in setup method
	sensor.setup(5, 4, 30000)
}
```

Setup sensor library with construcor
```
SensorHcSr04 sensor(5, 4);
// or
SensorHcSr04 sensor(5, 4, 3000);
```

And now you can take measure:

```
sensor.measure() // take measure
```
