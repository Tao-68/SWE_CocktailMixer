//@(#) Masher.h

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

#include "InternalDevice.h"

class Masher : public InternalDevice {
public:
    Masher();

    void doIt(float time);

private:
};

#endif
