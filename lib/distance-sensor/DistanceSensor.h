#ifndef ROBORACE_STOPWATCH_DISTANCE_SENSOR_H
#define ROBORACE_STOPWATCH_DISTANCE_SENSOR_H

#include <Arduino.h>

class DistanceSensor {
public:
    virtual short getDistance() = 0;
};


class AnalogSensor : public DistanceSensor {
public:
    static constexpr float ADC_FACTOR = 5.0 / 1024;

    AnalogSensor(const byte pin) : pin(pin) {
        pinMode(pin, INPUT);
    }

protected:
    float getVoltage() const {
        return analogRead(pin) * ADC_FACTOR;
    }

private:
    const byte pin;
};


class Sharp : public AnalogSensor {

public:
    static const int MIN_DISTANCE = 18;
    static const int MAX_DISTANCE = 150;

    Sharp(const byte pin) : AnalogSensor(pin) {}

    short getDistance() override final {
        float voltage = AnalogSensor::getVoltage();
        short distance = (short) (60.668 * pow(voltage, -1.167));
        return constrain(distance, MIN_DISTANCE, MAX_DISTANCE);
    }
};

#endif
