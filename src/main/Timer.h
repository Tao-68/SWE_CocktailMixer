//@(#) Timer.h

#ifndef TIMER_H_H
#define TIMER_H_H

#include <chrono>
using namespace std::chrono;
#include <iostream>

class Timer {
 public:
    void set_Turbo(int turbo);

    static Timer * getInstance();

    /**
     * 	~Timer( )
     *     {
     *         instanceFlag = false;
     *     };
     */
    void sleep_in_intervals(long milliseconds);
    void sleep(long delay_in_ms);


 private:
    static bool instanceFlag;

    static Timer * theTimer;

    int booster;

    Timer() : booster(1) {
    };

};

#endif
