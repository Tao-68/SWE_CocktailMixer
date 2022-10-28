//@(#) Drainer.h

#ifndef ENTLEERER_H_H
#define ENTLEERER_H_H

#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

class Drainer : public InternalDevice, public Observer {
public:
    Drainer(float g, int ze, Waage * wg);
    ~Drainer();
    void update();

    void doIt(float value);

private:
    float grammProZeit;

    Waage * myWaage;

    float value;

};

#endif
