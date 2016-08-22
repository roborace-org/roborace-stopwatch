#ifndef ROBORACE_STOPWATCH_INTERRUPT_H
#define ROBORACE_STOPWATCH_INTERRUPT_H

class Interrupt {
public:
    virtual bool interrupt() = 0;
};

#endif
