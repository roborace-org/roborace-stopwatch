#include "RoboraceStopwatch.h"

RoboraceStopwatch::RoboraceStopwatch(const byte sharpPin) {
    distanceSensor = new MedianFilter(new Sharp(sharpPin));
    freeDistance = distanceSensor->getDistance() - DISTANCE_THRESHOLD;
}

void RoboraceStopwatch::process() {
    if (isIntersect() && !intersection) {
        intersection = true;
        processIntersection();
    } else {
        intersection = false;
    }
}

void RoboraceStopwatch::processIntersection() {
    switch (state) {
        case READY:
            startTime = millis();
            state = RACE;
            break;
        case RACE:
            lapTime = millis() - startTime;
            state = FINISH;
            break;
        case FINISH:
            state = READY;
            break;
    }
}
