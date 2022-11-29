//@(#) Timer.cpp


#include "Timer.h"

void Timer::set_Turbo(int turbo) {
    this->booster = turbo;
}

Timer *Timer::getInstance() {
    if (theTimer == nullptr) {
        theTimer = new Timer();
        return theTimer;
    } else {
        return theTimer;
    }
}

void Timer::sleep_in_intervals(long delayInMS) {
    // to improve compatibility between Linux and Windows this implementation
    // is using busy wait (and avoids threads)! On purpose...
    long delay = 0;

    while (delayInMS > 0) {
        if (delayInMS >= delayTime) {
            std::cout << "*" << std::flush;
            delay = delayTime;
            delayInMS -= delay;
        } else {
            std::cout << "." << std::flush;
            delay = delayInMS;
            delayInMS = 0;
        }
        sleep(delay);
    }
}

void Timer::sleep(long delayInMS) {
    // if netbeans does not recognize system_clock you have to set the project properties to C++11:
    // Project-Properties->Code Assistance -> C++ (and C). Set it to C++!
    long now_millis = time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count();
    long limit = now_millis + (delayInMS / booster);

    while (limit > now_millis) {

        now_millis = time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count();;
    }
}

bool Timer::instanceFlag = false;

Timer *Timer::theTimer = nullptr;