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
            displayTime(0);
            break;
        case RACE:
            displayTime(millis() - startTime);
            break;
        case FINISH:
            displayTime(lapTime);
            break;
    }
}

void RoboraceStopwatch::displayTime(unsigned long time) {
    unsigned long sec = time / 1000;
    if (sec < 60) {
        unsigned long ms = (time % 1000) / 10;
        display(sec, ms);
    } else {
        unsigned long min = sec / 60;
        if (min < 60) {
            sec %= 60;
            display(min, sec);
        } else {
            unsigned long hour = min / 60;
            min %= 60;
            display(hour, min);
        }
    }
}

void RoboraceStopwatch::display(unsigned long first, unsigned long second) {

}
