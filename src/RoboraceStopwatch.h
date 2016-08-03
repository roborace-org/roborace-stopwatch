#ifndef ROBORACE_STOPWATCH_H
#define ROBORACE_STOPWATCH_H

#include "MedianFilter.h"

class RoboraceStopwatch {
public:
    RoboraceStopwatch(const byte sharp_pin) {
        distanceSensor = new MedianFilter(new Sharp(sharp_pin));
    }

    void process() {
        short distance = distanceSensor->getDistance();
    }

private:

    DistanceSensor *distanceSensor;
};

#endif
