//@(#) Shaker.h

#ifndef SCHUETTLER_H_H
#define SCHUETTLER_H_H

#include "InternalDevice.h"

class Shaker : public InternalDevice {
public:
    Shaker();

    void doIt(float time);

private:
};

#endif
