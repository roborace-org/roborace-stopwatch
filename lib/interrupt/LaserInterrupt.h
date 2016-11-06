#ifndef ROBORACE_STOPWATCH_LASER_INTERRUPT_H
#define ROBORACE_STOPWATCH_LASER_INTERRUPT_H

#include "Interrupt.h"
#include "Button.h"

/**
 * Тестовый вариант прерываний на основе кнопки
 */
class LaserInterrupt : public Interrupt {
public:

    LaserInterrupt(byte pin) {
        button = new Button(pin);
    }

    bool interrupt() override final {
        return !button->read();
    }

private:
    Button *button;

};

#endif
