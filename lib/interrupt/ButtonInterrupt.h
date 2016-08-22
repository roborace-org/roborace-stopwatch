#ifndef ROBORACE_STOPWATCH_BUTTON_INTERRUPT_H
#define ROBORACE_STOPWATCH_BUTTON_INTERRUPT_H

#include "Interrupt.h"
#include "ButtonSafe.h"

/**
 * Тестовый вариант прерываний на основе кнопки
 * @link https://github.com/vakhrymchuk/roborace
 */
class ButtonInterrupt : public Interrupt {
public:

    ButtonInterrupt(byte pin) {
        buttonSafe = new ButtonSafe(new ButtonPullUp(pin));
    }

    bool interrupt() override final {
        return buttonSafe->read();
    }

private:
    ButtonSafe *buttonSafe;

};

#endif
