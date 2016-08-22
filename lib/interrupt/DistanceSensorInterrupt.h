#ifndef ROBORACE_STOPWATCH_DISTANCE_SENSOR_INTERRUPT_H
#define ROBORACE_STOPWATCH_DISTANCE_SENSOR_INTERRUPT_H

#include "Interrupt.h"

/**
 * Прерывания на основе датчиков расстояния
 */
class DistanceSensorInterrupt : public Interrupt {
public:

    static const int DISTANCE_THRESHOLD = 10;

    DistanceSensorInterrupt(DistanceSensor *distanceSensor) : distanceSensor(distanceSensor) {
        freeDistance = distanceSensor->getDistance();
    }

    bool interrupt() override final {
        short distance = distanceSensor->getDistance();

        if (distance + DISTANCE_THRESHOLD < freeDistance) {
            intersection = true;
        } else if (distance + DISTANCE_THRESHOLD / 2 > freeDistance) {
            intersection = false;
        }

        return intersection;
    }

private:
    DistanceSensor *distanceSensor;

    short freeDistance;

    bool intersection;

};

#endif
