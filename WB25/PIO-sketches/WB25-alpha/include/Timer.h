#include <Arduino.h>

class Timer
{
private:
    unsigned long interval = 0;
    unsigned long stamp = 0;
    bool isStopped = true;
public:
    Timer(unsigned long Interval);
    void start();
    void reset();
    bool isReached();
};

Timer::Timer(unsigned long Interval) {
    interval = Interval;
}

void Timer::start() {
    Timer::reset();
}

void Timer::reset() {
    stamp = millis();
    isStopped = false;
}

bool Timer::isReached() {
    if((millis() - stamp) > interval && !isStopped) return true;
    return false;
}
