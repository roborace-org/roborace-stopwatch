#include "RoboraceStopwatch.h"
#include "MedianFilter.h"
#include "SerialDisplay.h"

#define SHARP_PIN A0

RoboraceStopwatch *roboraceStopwatch;

void setup() {
    delay(1000);
    DistanceSensor *distanceSensor = new MedianFilter(new Sharp(SHARP_PIN));
    roboraceStopwatch = new RoboraceStopwatch(distanceSensor, new SerialDisplay());
}

void loop() {
    roboraceStopwatch->process();
}
