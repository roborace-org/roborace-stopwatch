#ifndef ROBORACE_STOPWATCH_MEDIAN_FILTER_H
#define ROBORACE_STOPWATCH_MEDIAN_FILTER_H

#include "DistanceSensor.h"

class MedianFilter : public DistanceSensor {
public:

    static const int READ_COUNT = 3;
    static const int MEDIAN_INDEX = READ_COUNT >> 1;
    static const int DELAY_BEFORE_READ_MCS = 200;

    MedianFilter(DistanceSensor *sensor) : sensor(sensor) {}

    short getDistance() override final {
        readValues();
        sortValues();
        return getMedian();
    }

private:

    DistanceSensor *sensor;

    short values[READ_COUNT];

    void readValues();

    void sortValues();

    short getMedian() const {
        return values[MEDIAN_INDEX];
    }
};

#endif
