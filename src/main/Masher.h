//@(#) Masher.h

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

#include "InternalDevice.h"
/**
 * @class Masher
 * @brief This class inherits by InternalDevice
 *
 */
class Masher : public InternalDevice {
public:
    /** @brief The Constructor is not declared.
     */
    Masher();

    /**
     * @brief This methode set the myTimer to sleep in intervals with the time in milliseconds.
     *
     * @param time
     */
    void doIt(float time);

private:
};

#endif
