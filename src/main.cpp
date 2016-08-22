#include "RoboraceStopwatch.h"
#include "MedianFilter.h"
//#include "SerialDisplay.h"
//#include "DisplaySSD1306.h"
#include "DisplayTM1637.h"

//#include "ButtonInterrupt.h"
#include "DistanceSensorInterrupt.h"

RoboraceStopwatch *roboraceStopwatch;

void setup() {
    delay(100);

    DistanceSensor *distanceSensor = new MedianFilter(new Sharp(A0));
    Interrupt *interrupt = new DistanceSensorInterrupt(distanceSensor);

//    Interrupt *interrupt = new ButtonInterrupt(2);

//    Display *display = new SerialDisplay(9600);
//    Display *display = new DisplaySSD1306();
    Display *display = new DisplayTM1637();

    roboraceStopwatch = new RoboraceStopwatch(interrupt, display);
}

void loop() {
    roboraceStopwatch->process();
}
