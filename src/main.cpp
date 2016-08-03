#include "RoboraceStopwatch.h"
#include "SerialDisplay.h"

#define SHARP_PIN A0

RoboraceStopwatch *roboraceStopwatch;

void setup() {
    delay(1000);
    roboraceStopwatch = new RoboraceStopwatch(SHARP_PIN, new SerialDisplay());
}

void loop() {
    roboraceStopwatch->process();
}
