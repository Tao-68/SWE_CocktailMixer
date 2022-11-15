//@(#) Mixer.h

#ifndef MIXER_H_H
#define MIXER_H_H

#include <iostream>

#include "InternalDevice.h"

/**
 * @class Mixer
 * @brief This class inherits from InternalDevice
 * It has to simulate a machine mixer.
 */
class Mixer : public InternalDevice {
public:
    /** @brief The Constructor.
     * This method have no code.
     */
    Mixer();

    /**
     * @brief This methode set the myTimer to sleep in intervals with the time in milliseconds.
     * @param time
     */
    void doIt(float time);

private:

};

#endif
