#include "RoboraceStopwatch.h"
#include "MedianFilter.h"
//#include "SerialDisplay.h"
//#include "DisplaySSD1306.h"
#include "DisplayTM1637.h"

#define SHARP_PIN A0

RoboraceStopwatch *roboraceStopwatch;

void setup() {
    delay(500);
    DistanceSensor *distanceSensor = new MedianFilter(new Sharp(SHARP_PIN));
//    Display *display = new SerialDisplay(9600);
//    Display *display = new DisplaySSD1306();
    Display *display = new DisplayTM1637();
    roboraceStopwatch = new RoboraceStopwatch(distanceSensor, display);
}

void loop() {
    roboraceStopwatch->process();
}
