//@(#) Shaker.h

#ifndef SCHUETTLER_H_H
#define SCHUETTLER_H_H

#include "InternalDevice.h"

/**
 * @class Shaker
 *
 * @brief Shaker is a type of internal device.
 *
 */
class Shaker : public InternalDevice {
public:

    Shaker();

    /** @brief Simulates shaking the ingredients
    * @param [in] time the time taken in seconds
    *
    * This method makes the timer sleep for a given time
    */
    void doIt(float time);

private:
};

#endif
