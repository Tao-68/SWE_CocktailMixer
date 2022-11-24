#include "Dispenser.h"

Dispenser::Dispenser(float gram, int timeUnit, std::string content, Waage * scale) : InternalDevice() {
    this->gramPerTime = gram;
    this->zeiteinheit = timeUnit;
    this->content = std::move(content);
    this->scale = scale;
    this->scale->attach(this);
}

Dispenser::~Dispenser(){
    this->scale->detach(this);
    delete scale;
}

void Dispenser::update() {
    if (!this->doinIt) return;

    if (static_cast<float>(scale->getDeltaWeight()) >= weight)
        doinIt = false;

}

void Dispenser::doIt(float gramm) {
    this->weight = gramm;
    scale->resetDeltaWeight();

    doinIt = true;
    std::cout << content << " Ventil wurde geoeffnet" << std::endl;
    while (doinIt) {
      myTimer->sleep_in_intervals(zeiteinheit);
      scale->changeWeight(static_cast<int>(gramPerTime));
    }
    std::cout << std::endl << content << " Ventil wurde geschlossen" << std::endl;
    std::cout << "Es wurden " << scale->getDeltaWeight() << "g " << content << " abgefuellt" << std::endl;
    std::cout << std::endl;
}

float Dispenser::getPiecePerTime() const {
    return this->gramPerTime;
}
