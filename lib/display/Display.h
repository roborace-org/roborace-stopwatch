#ifndef ROBORACE_STOPWATCH_DISPLAY_H
#define ROBORACE_STOPWATCH_DISPLAY_H

#include "Interval.h"

class Display {
public:
    Display(const unsigned short interval = 100) {
        this->interval = new Interval(interval);
    }

    virtual void displayTime(const unsigned long time) {
        if (interval->isReady()) {
            displaySegments(time);
        }
    }

protected:
    virtual void displaySegments(unsigned long first, unsigned long second) = 0;

private:
    Interval *interval;

    void displaySegments(unsigned long time) {
        unsigned long sec = time / 1000;
        if (sec < 60) {
            unsigned long ms = (time % 1000) / 10;
            displaySegments(sec, ms);
        } else {
            unsigned long min = sec / 60;
            if (min < 60) {
                sec %= 60;
                displaySegments(min, sec);
            } else {
                unsigned long hour = min / 60;
                min %= 60;
                displaySegments(hour, min);
            }
        }
    }
};

#endif
