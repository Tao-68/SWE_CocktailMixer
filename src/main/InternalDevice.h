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
    virtual void doIt(float valueParameter) = 0;

    /* Macht im Moment auch nichts
     * Sollte eventuell das Putzen simulieren
     */
    void putzen();

private:
    //Macht nichts
    void setTimer();


public:
    //Erzeugt einen Timer
    InternalDevice();
protected:
    int zeiteinheit;

    bool doinIt;

    Timer * myTimer;

};

#endif
