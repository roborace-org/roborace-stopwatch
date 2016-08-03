#include "RoboraceStopwatch.h"

RoboraceStopwatch::RoboraceStopwatch(DistanceSensor *distanceSensor, Display *display) : distanceSensor(distanceSensor),
                                                                                         display(display) {
    freeDistance = distanceSensor->getDistance() - DISTANCE_THRESHOLD;
}

void RoboraceStopwatch::process() {
    if (isIntersect() && !intersection) {
        intersection = true;
        processIntersection();
    } else {
        intersection = false;
    }

    displayTime();
}

void RoboraceStopwatch::processIntersection() {
    switch (state) {
        case READY:
            startTime = millis();
            state = RACE;
            break;
        case RACE: {
            unsigned long lapTime = calcLapTime();
            startTime = millis();
            if (lapTime < bestTime || bestTime == 0) {
                bestTime = lapTime;
            }
            break;
        }
        case FINISH:
            state = READY;
            break;
    }
}

void RoboraceStopwatch::displayTime() const {
    switch (state) {
        case READY:
            display->displayTime(0);
            break;
        case RACE: {
            unsigned long time = calcLapTime();
            if (bestTime > 0 && time < BEST_TIME_SHOW_TIME) {
                display->displayTime(bestTime);
            } else {
                display->displayTime(time);
            }
            break;
        }
        case FINISH:
            display->displayTime(bestTime);
            break;
    }
}

unsigned long RoboraceStopwatch::calcLapTime() const {
    return millis() - startTime;
}
