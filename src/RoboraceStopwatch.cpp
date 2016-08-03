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
    state = getNewState();
}

State RoboraceStopwatch::getNewState() const {
    switch (state) {
        case READY:
            return RACE;
        case RACE:
            return FINISH;
        case FINISH:
            return READY;
        default:
            return READY;
    }
}
