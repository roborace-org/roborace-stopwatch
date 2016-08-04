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
    virtual void displayString(const char *string) = 0;

private:
    Interval *interval;

    void displaySegments(unsigned long time) {
        unsigned long sec = time / 1000;
        if (sec < 60) {
            byte ms = (byte) ((time % 1000) / 10);
            displaySegments((byte) sec, ms);
        } else {
            unsigned long min = sec / 60;
            if (min < 60) {
                sec %= 60;
                displaySegments((byte) min, (byte) sec);
            } else {
                unsigned long hour = min / 60;
                min %= 60;
                displaySegments((byte) hour, (byte) min);
            }
        }
    }

    void displaySegments(byte first, byte second) {
        char string[5];
        sprintf(string, "%02d:%02d", first, second);
        displayString(string);
    }
};

#endif
