#ifndef ROBORACE_STOPWATCH_SERIAL_DISPLAY_H
#define ROBORACE_STOPWATCH_SERIAL_DISPLAY_H

#include <HardwareSerial.h>
#include "Display.h"

/**
 * Display data to serial port.
 */
class SerialDisplay : public Display {
public:
    SerialDisplay(const unsigned long baud = 9600, const unsigned short interval = 200) : Display(interval) {
        Serial.begin(baud);
    }

protected:
    virtual void displayString(const char *string) {
        Serial.println(string);
    }
};

#endif
