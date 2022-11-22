#include "Dispenser.h"

#include <utility>

Dispenser::Dispenser(float g, int ze, std::string inhaltParameter, Waage * wg) : InternalDevice() {
    this->gramPerTime = g;
    this->zeiteinheit = ze;
    this->content = std::move(inhaltParameter);
    this->scale = wg;
    this->scale->attach(this);
}

void Dispenser::update() {
    if (!this->doinIt) return;
    if (static_cast<float>(scale->getDelta()) >= weight)
        doinIt = false;

}

void Dispenser::doIt(float gramm) {
    this->weight = gramm;
    scale->tara();
    doinIt = true;
    std::cout << content << " Ventil wurde geoeffnet" << std::endl;
    while (doinIt) {
      myTimer->sleep_in_intervals(zeiteinheit);
      scale->changeWeight(static_cast<int>(gramPerTime));
    }
    std::cout << std::endl << content << " Ventil wurde geschlossen" << std::endl;
    std::cout << "Es wurden " << scale->getDelta() << "g " << content << " abgefuellt" << std::endl;
    std::cout << std::endl;
}

float Dispenser::getPiecePerTime() const {
    return this->gramPerTime;
}
