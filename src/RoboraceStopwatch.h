#ifndef ROBORACE_STOPWATCH_H
#define ROBORACE_STOPWATCH_H

#include "DistanceSensor.h"
#include "Display.h"

enum State {
    READY, RACE, FINISH
};


class RoboraceStopwatch {
public:
    static const int DISTANCE_THRESHOLD = 5;

    RoboraceStopwatch(DistanceSensor *distanceSensor, Display *display);

    void process();

private:

    State state = READY;

    Display *display;

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

};

#endif
