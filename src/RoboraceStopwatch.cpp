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
        case RACE:
            lapTime = millis() - startTime;
            state = FINISH;
            break;
        case FINISH:
            state = READY;
            break;
    }
}

void RoboraceStopwatch::displayTime() {
    switch (state) {
        case READY:
            display->displayTime(0);
            break;
        case RACE:
            display->displayTime(millis() - startTime);
            break;
        case FINISH:
            display->displayTime(lapTime);
            break;
    }
}
