#ifndef ROBORACE_STOPWATCH_DISPLAY_SSD1306_H
#define ROBORACE_STOPWATCH_DISPLAY_SSD1306_H

#include <Adafruit_SSD1306.h>
#include "Display.h"

/**
 * Display data to SSD1306 display.
 * @link https://github.com/adafruit/Adafruit_SSD1306
 * @link https://github.com/adafruit/Adafruit-GFX-Library
 */
class DisplaySSD1306 : public Display {
public:
    DisplaySSD1306(const unsigned short interval = 50) : Display(interval) {
        display = new Adafruit_SSD1306();
        display->begin(SSD1306_SWITCHCAPVCC, 0x3C);
        display->clearDisplay();
        display->setTextColor(WHITE);
        display->setTextSize(4);
        display->display();
    }

protected:
    void displayString(const char *string) override final {
        display->clearDisplay();
        display->setCursor(0, 0);
        display->print(string);
        display->display();
    };

private:
    Adafruit_SSD1306 *display;
};

#endif
