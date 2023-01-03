#include "Drainer.h"

Drainer::Drainer(float g, int ze, Waage *wg) : InternalDevice() {
    this->gramPerTime = g;
    this->zeiteinheit = ze;
    this->scale = wg;
    this->scale->attach(this);
}

Drainer::~Drainer() {

    this->scale->detach(this);
    delete scale;
}

void Drainer::update() {
    if (static_cast<float>(scale->getWeight()) <= this->value)
        doinIt = false;
}

bool Drainer::doIt(float drainValue) {


    if (!isUndrinkableCocktail) {
        std::cout << "Ihr Cocktail hat ein Gesamtgewicht von " << scale->getWeight() << "g" << std::endl;
    }
    std::cout << "Entleervorgang wird begonnen..." << std::endl;
    this->value = drainValue;
    doinIt = true;

    while (doinIt) {
        myTimer->sleep_in_intervals(zeiteinheit);
        scale->changeWeight(-static_cast<int>(gramPerTime));
    }
    if (!isUndrinkableCocktail) {
        std::cout << "\nEntleervorgang wurde beendet, bitte entnehmen Sie ihren Cocktail!\n" << std::endl;
    } else {
        std::cout << "\nEntleervorgang wurde beendet, "
                  <<  "bitte entnehmen Sie ungeniessbaren Cocktail und schütteln diesen weg!\n" << std::endl;
    }
    return true;
}

bool Drainer::setIsUndrinkableCocktail(bool isUndrinkable) {
    isUndrinkableCocktail = isUndrinkable;
}
