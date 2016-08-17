#ifndef ROBORACE_STOPWATCH_DISPLAY_TM1637_H
#define ROBORACE_STOPWATCH_DISPLAY_TM1637_H

#include <TM1637Display.h>
#include "Display.h"

/**
 * Display data to TM11637 display.
 * @link https://github.com/avishorp/TM1637
 */
class DisplayTM1637 : public Display {
public:
    DisplayTM1637(const unsigned short interval = 50) : Display(interval) {
        display = new TM1637Display(2, 3);
        display->setBrightness(0x0f);
    }

protected:
    void displayString(const char *string) override final {

        byte segments[] = {0, 0, 0, 0};

        segments[0] = display->encodeDigit((byte) string[0] - '0');
        segments[1] = display->encodeDigit((byte) string[1] - '0');
        segments[2] = display->encodeDigit((byte) string[3] - '0');
        segments[3] = display->encodeDigit((byte) string[4] - '0');

        display->setSegments(segments);
    };

private:
    TM1637Display *display;
};

#endif
