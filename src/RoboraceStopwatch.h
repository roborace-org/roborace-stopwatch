#ifndef ROBORACE_STOPWATCH_H
#define ROBORACE_STOPWATCH_H

#include "MedianFilter.h"

class RoboraceStopwatch {
public:
    static const int DISTANCE_THRESHOLD = 5;

    RoboraceStopwatch(const byte sharp_pin) {
        distanceSensor = new MedianFilter(new Sharp(sharp_pin));
        freeDistance = distanceSensor->getDistance() - DISTANCE_THRESHOLD;
    }

    void process() {
        if (isIntersect() && !intersection) {
            intersection = true;
            processIntersection();
        } else {
            intersection = false;
        }
    }

private:

    DistanceSensor *distanceSensor;

    short freeDistance;

    bool intersection = false;

    bool isIntersect() const {
        return distanceSensor->getDistance() < freeDistance;
    }

    void processIntersection() {

    }
};

#endif
