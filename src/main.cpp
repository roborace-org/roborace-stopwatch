#include "RoboraceStopwatch.h"
//#include "SerialDisplay.h"
//#include "DisplaySSD1306.h"
#include "DisplayTM1637.h"

#include "ButtonInterrupt.h"
#include "DistanceSensorInterrupt.h"

RoboraceStopwatch *roboraceStopwatch;

/**
 * Если в момент запуска нажата кнопка то прерывания будут фиксироваться по кнопке.
 * При рестарте необходимо держать кнопку, отпустить когда загорится светодиод на 13 ноге.
 * Без удержания кнопки будет использоваться датчик расстояния
 */
Interrupt *createInterrupt() {
    ButtonPullUp button(5);
    if (button.read()) {
        pinMode(13, OUTPUT);
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        delay(300);
        return new ButtonInterrupt(5);
    }
    return new DistanceSensorInterrupt(new Sharp(A0));
}

void setup() {
    delay(100);

//    Display *display = new SerialDisplay(9600);
//    Display *display = new DisplaySSD1306();
    Display *display = new DisplayTM1637();

    roboraceStopwatch = new RoboraceStopwatch(createInterrupt(), display);
}

void loop() {
    roboraceStopwatch->process();
}
