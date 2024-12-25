# HCSR04 Class

This class implements the HCSR04 ultrasonic sensor.

## Constructor

```C++
HCSR04(int triggerPin, int echoPin);
```

### Parameters

- `triggerPin`: the trigger pin number
- `echoPin`: the echo pin number

## Methods

```C++
float getDistance();
```

### Returns

- the distance in meters