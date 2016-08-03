#ifndef ROBORACE_STOPWATCH_H
#define ROBORACE_STOPWATCH_H

#include "MedianFilter.h"

enum State {
    READY, RACE, FINISH
};


class RoboraceStopwatch {
public:
    static const int DISTANCE_THRESHOLD = 5;

    RoboraceStopwatch(const byte);

    void process();

private:

    State state = READY;

    DistanceSensor *distanceSensor;

    short freeDistance;

    bool intersection = false;

    unsigned long startTime = 0;

    unsigned long lapTime = 0;

    bool isIntersect() const {
        return distanceSensor->getDistance() < freeDistance;
    }

    void processIntersection();

    void displayTime();

    void displayTime(unsigned long time);

    void display(unsigned long first, unsigned long second);
};

#endif
