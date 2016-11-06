#include "RoboraceStopwatch.h"
//#include "SerialDisplay.h"
//#include "DisplaySSD1306.h"
#include "DisplayTM1637.h"

#include "ButtonInterrupt.h"
#include "LaserInterrupt.h"
#include "Led.h"

#define LASER_PIN 2
#define BUTTON_PIN 5
#define LED_PIN 13

RoboraceStopwatch *roboraceStopwatch;

/**
 * Если в момент запуска нажата кнопка то прерывания будут фиксироваться по кнопке.
 * При рестарте необходимо держать кнопку, отпустить когда загорится встроенный светодиод.
 * Без удержания кнопки будет использоваться датчик расстояния
 */
Interrupt *createInterrupt() {
    ButtonPullUp button(BUTTON_PIN);
    if (button.read()) {
        Led led(LED_PIN);
        led.high();
        delay(1000);
        led.low();
        delay(500);
        return new ButtonInterrupt(BUTTON_PIN);
    }
    return new LaserInterrupt(LASER_PIN);
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
