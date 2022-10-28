//@(#) Dispenser.h

#ifndef DOSIERER_H_H
#define DOSIERER_H_H

#include <string>
#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

class Dispenser : public InternalDevice, public Observer {
public:
    Dispenser(float g, int ze, std::string inhalt, Waage * wg);
    virtual void update();

    void doIt(float gramm);

    int getStueckProZeit();

private:
    float grammProZeit;

    Waage * myWaage;

    float gwicht;

    std::string inhalt;
};

#endif
