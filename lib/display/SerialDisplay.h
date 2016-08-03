#ifndef ROBORACE_STOPWATCH_SERIAL_DISPLAY_H
#define ROBORACE_STOPWATCH_SERIAL_DISPLAY_H

#include <HardwareSerial.h>
#include "Display.h"

class SerialDisplay : public Display {
public:
    SerialDisplay(const unsigned long baud = 9600, const unsigned short interval = 200) : Display(interval) {
        Serial.begin(baud);
    }

protected:
    void displaySegments(unsigned long first, unsigned long second) override final {
        Serial.print(first);
        Serial.print(':');
        Serial.println(second);
    };
};

#endif
