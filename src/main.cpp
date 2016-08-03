#include "RoboraceStopwatch.h"

#define SHARP_PIN A0

RoboraceStopwatch *roboraceStopwatch;

void setup() {
    roboraceStopwatch = new RoboraceStopwatch(SHARP_PIN);
}

void loop() {
    roboraceStopwatch->process();
}
