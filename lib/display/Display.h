#ifndef ROBORACE_STOPWATCH_DISPLAY_H
#define ROBORACE_STOPWATCH_DISPLAY_H

#include "Timing.h"

class Display {
public:
    Display(const unsigned short interval = 100) {
        this->interval = new Interval(interval);
    }

    void displayTime(const unsigned long time) {
        if (interval->isReady()) {
            displaySegments(time);
        }
    }

protected:
    virtual void displayString(const char *string) = 0;

private:
    Interval *interval;

    void displaySegments(const unsigned long time) {
        unsigned long sec = time / 1000;
        if (sec < 60) {
            byte ms = (byte) (time / 10 % 100);
            displayMillis((byte) sec, ms);
        } else {
            unsigned long min = sec / 60;
            if (min < 60) {
                sec %= 60;
                displaySeconds((byte) min, (byte) sec);
            } else {
                unsigned long hour = min / 60;
                min %= 60;
                displaySeconds((byte) hour, (byte) min);
            }
        }
    }

    void displayMillis(const byte first, const byte second) {
        char string[5];
        sprintf(string, "%02d.%02d", first, second);
        displayString(string);
    }

    void displaySeconds(const byte first, const byte second) {
        char string[5];
        sprintf(string, "%02d:%02d", first, second);
        displayString(string);
    }
};

#endif
