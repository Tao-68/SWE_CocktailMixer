//@(#) InternalDevice.h

#ifndef INTERNALDEVICE_H_H
#define INTERNALDEVICE_H_H

#include "Timer.h"

/**
 * Abstraktion von Dosierern und Verarbeitungseinheiten
 *  
 */
class InternalDevice {
public:
    virtual void doIt(float value) = 0;

    void putzen();

private:
    void setTimer();


public:
    InternalDevice();
protected:
    int zeiteinheit;

    bool doinIt;

    Timer * myTimer;

};

#endif
