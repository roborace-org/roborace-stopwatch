#ifndef ROBORACE_STOPWATCH_H
#define ROBORACE_STOPWATCH_H

#include "DistanceSensor.h"
#include "Display.h"
#include "Timer.h"
#include "Interrupt.h"

enum State {
    READY, RACE, FINISH
};


class RoboraceStopwatch {
public:

    static const int BEST_TIME_DELAY = 1000;

    RoboraceStopwatch(Interrupt *interrupt, Display *display) : interrupt(interrupt), display(display) {}

    void process();

private:

    State state = READY;

    Interrupt *interrupt;

    Display *display;

    bool intersection = false;

    Timer intersectionTimer;

    unsigned long startTime = 0;
    unsigned long lapTime = 0;
    unsigned long bestTime = 0;

    void checkIntersection();

    void processIntersection();

    void displayTime() const;

    unsigned long calcLapTime() const;
};

#endif
