#include "RoboraceStopwatch.h"

RoboraceStopwatch::RoboraceStopwatch(DistanceSensor *distanceSensor, Display *display) : distanceSensor(distanceSensor),
                                                                                         display(display) {
    freeDistance = distanceSensor->getDistance();
}

void RoboraceStopwatch::process() {
    if (intersectionTimer.isReady()) {
        checkIntersection();
    }

    displayTime();
}

void RoboraceStopwatch::checkIntersection() {
    short distance = distanceSensor->getDistance();
    if (distance + DISTANCE_THRESHOLD < freeDistance) {
        if (!intersection) {
            intersection = true;
            processIntersection();
            intersectionTimer.start(100);
        }
    } else if (distance + DISTANCE_THRESHOLD / 2 > freeDistance) {
        if (intersection) {
            intersection = false;
            intersectionTimer.start(2000);
        }
    }
}

void RoboraceStopwatch::processIntersection() {
    switch (state) {
        case READY:
            startTime = millis();
            state = RACE;
            break;
        case RACE: {
            lapTime = calcLapTime();
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
            if (lapTime > 0 && time < BEST_TIME_DELAY) {
                display->displayTime(lapTime);
            } else if (bestTime > 0 && time < 2 * BEST_TIME_DELAY) {
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
