#ifndef ROBORACE_STOPWATCH_INTERVAL_H
#define ROBORACE_STOPWATCH_INTERVAL_H

class Interval {
public:

    Interval(const unsigned short interval) : interval(interval) {}

    bool isReady() {
        bool value = millis() >= msReady;
        if (value) {
            recalculate();
        }
        return value;
    }

    void recalculate() {
        msReady += interval;
    }

private:
    const unsigned short interval;
    unsigned long msReady = 0;
};

#endif
