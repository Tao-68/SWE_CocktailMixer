#include "Drainer.h"

Drainer::Drainer(float g, int ze, Waage * wg) : InternalDevice() {
    this->gramPerTime = g;
    this->zeiteinheit = ze;
    this->scale = wg;
    this->scale->attach(this);

    this->value = 0;
}

Drainer::~Drainer(){

    this->scale->detach(this);
    delete scale;
}

void Drainer::update() {

    if (!this->doinIt) return;
    if (static_cast<float>(scale->getWeight()) <= this->value)
        doinIt = false;
}

void Drainer::doIt(float drainValue) {
    std::cout << "Ihr Cocktail hat ein Gesamtgewicht von " << scale->getWeight() << "g" << std::endl;
    std::cout << "Entleervorgang wird begonnen..." << std::endl;
    this->value = drainValue;
    doinIt = true;

    while (doinIt) {
      myTimer->sleep_in_intervals(zeiteinheit);
        scale->changeWeight(-static_cast<int>(gramPerTime));
    }
    std::cout << std::endl;
    std::cout << "Entleervorgang wurde beendet, bitte entnehmen Sie ihren Cocktail!" << std::endl;
    std::cout << std::endl;
}
