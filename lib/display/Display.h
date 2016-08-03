#ifndef ROBORACE_STOPWATCH_DISPLAY_H
#define ROBORACE_STOPWATCH_DISPLAY_H

class Display {
public:
    virtual void displayTime(unsigned long time) {
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

    virtual void displaySegments(unsigned long first, unsigned long second) = 0;
};

#endif
