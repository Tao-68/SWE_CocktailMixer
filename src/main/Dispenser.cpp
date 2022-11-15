#include "Dispenser.h"

Dispenser::Dispenser(float g, int ze, std::string inhaltParameter, Waage * wg) : InternalDevice() {
    this->grammProZeit = g;
    this->zeiteinheit = ze;
    this->inhalt = inhaltParameter;
    this->myWaage = wg;
    this->myWaage->attach(this);
}

Dispenser::~Dispenser(){
    this->myWaage->detach(this);
}

void Dispenser::update() {
    if (!this->doinIt) return;
    if (myWaage->getDelta() >= gwicht) {
        doinIt = false;
    }

}

void Dispenser::doIt(float gramm) {
    this->gwicht = gramm;
    myWaage->tara();
    doinIt = true;
    std::cout << inhalt << " Ventil wurde geoeffnet" << std::endl;
    while (doinIt) {
      myTimer->sleep_in_intervals(zeiteinheit);
        myWaage->changeWeight(grammProZeit);
    }
    std::cout << std::endl << inhalt << " Ventil wurde geschlossen" << std::endl;
    std::cout << "Es wurden " << myWaage->getDelta() << "g " << inhalt << " abgefuellt" << std::endl;
    std::cout << std::endl;
}

int Dispenser::getStueckProZeit() {
    return this->grammProZeit;
}
