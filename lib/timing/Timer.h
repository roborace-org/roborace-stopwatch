#ifndef ROBORACE_STOPWATCH_TIMER_H
#define ROBORACE_STOPWATCH_TIMER_H

class Timer {
public:

    bool isReady() const {
        return millis() >= msReady;
    }

    void start(unsigned int timeout) {
        msReady = millis() + timeout;
    }

protected:
    unsigned long msReady = 0;
};


#endif
