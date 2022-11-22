//@(#) Timer.h

#ifndef TIMER_H_H
#define TIMER_H_H

#include <chrono>
using namespace std::chrono;
#include <iostream>

/**
 * @class Timer
 *
 * @brief Timer manages sleeping duration
 *
 * You can accelerate the sleeping duration
 * And create an instance of Timer
 */
class Timer {
 public:

    /** @brief Sets the value to accelerate the time
    * @param [in] turbo the accelerating factor
    */
    void set_Turbo(int turbo);

    /** @brief Gets the instance
    * @return the instance
    *
    * This method creates an instance of Timer if it is not yet created
    * And return the instance.
    * Else it returns an existing instance.
    */
    static Timer * getInstance();

    /**
     * 	~Timer( )
     *     {
     *         instanceFlag = false;
     *     };
     */

    /** @brief Sets the time duration to sleep in intervals
    * @param [in] delayInMS the time to delay in milliseconds
    */
    void sleep_in_intervals(long delayInMS);

    /** @brief Sets the time duration to sleep
    * @param [in] delayInMS the time to sleep in milliseconds
    *
    * This method divides the input (delay_in_ms) with another input (booster)
    */
    void sleep(long delayInMS);


 private:
    static bool instanceFlag;

    /**
     * This is an instance of Timer
     */
    static Timer * theTimer;

    int booster;

    const int delayTime = 1000;

    /** @brief Constructor that creates a Timer object
    * @return the constructed object
    *
    * This method creates a Timer;
    * where the booster has a default value of 1.
    */
    Timer() : booster(1) {
    };

};

#endif
