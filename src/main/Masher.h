//@(#) Masher.h

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

#include "InternalDevice.h"

class Masher : public InternalDevice {
public:
    Masher();

    // Übergabe einer Zeit (in Sekunden) um den Timer zu setzen
    void doIt(float time);

private:
};

#endif
