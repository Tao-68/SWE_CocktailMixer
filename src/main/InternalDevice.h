#ifndef INTERNALDEVICE_H_H
#define INTERNALDEVICE_H_H

#include "Timer.h"

/**
 * @class InternalDevice
 * @brief This class is a mother class.
 * It has to simulate a machine device.
 */
class InternalDevice {
public:
    /**
     * @brief This virtual methode is not declared.
     * @param value
     */
    virtual bool doIt(float value) = 0;


    /** @brief Can be used to clean the Devices.
     * This method does nothing
     */
    void putzen();

private:
    /** @brief Can be used to clean the Devices.
     * This method have no code.
     */
    void setTimer();


public:

    /** @brief The Constructor initial the Device.
     * This method generate a timer with variable myTimer.
     * Set the variable doinIt to 0.
     */
    InternalDevice();
protected:
    /**
     * This is not used.
     */
    int zeiteinheit;

    /**
     * This have not a useful use.
     */
    bool doinIt;

    /**
     * This is a pointer of a class from the bib <timer.h>
     * Used for a timer instance.
     */
    Timer * myTimer;

};

#endif
