#ifndef ROBORACE_STOPWATCH_H
#define ROBORACE_STOPWATCH_H

#include "DistanceSensor.h"
#include "Display.h"

enum State {
    READY, RACE, FINISH
};


class RoboraceStopwatch {
public:
    static const int DISTANCE_THRESHOLD = 10;
    static const int BEST_TIME_DELAY = 2000;

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
    unsigned long bestTime = 0;

    void processIntersection();

    void displayTime() const;

    unsigned long calcLapTime() const;
};

#endif
