#include "Dispenser.h"

Dispenser::Dispenser(float gram, int timeUnit, const std::string &dispenserContent, Waage * dispenserScale, const std::string &type) : InternalDevice(),content{dispenserContent}, weightTyp{type} {
    this->gramPerTime = gram;
    this->zeiteinheit = timeUnit;
    this->scale = dispenserScale;
    this->scale->attach(this);
    this->capacity = 1000;
}

Dispenser::~Dispenser(){
    this->scale->detach(this);
    delete scale;
}

void Dispenser::update() {
    if (static_cast<float>(scale->getDeltaWeight()) >= weight)
        doinIt = false;
}

void Dispenser::doIt(float gramm) {
    this->maxAvailableOutput(gramm);
    scale->resetDeltaWeight();

    if(static_cast<int>(weight) != 0) doinIt = true;
    std::cout << content << " Ventil wurde geoeffnet" << std::endl;

    while (doinIt) {
        myTimer->sleep_in_intervals(zeiteinheit);
        scale->changeWeight(static_cast<int>(gramPerTime));
    }

    std::cout << std::endl << content << " Ventil wurde geschlossen" << std::endl;
    std::cout << "Es wurden " << scale->getDeltaWeight() << weightTyp << " " << content << " abgefuellt" << std::endl;
    this->decreaseCapacity(static_cast<int>(gramm) );
    std::cout << content << " Dosierer-Kapazitaet (" << capacity << weightTyp << ")" << std::endl;
    std::cout << std::endl;
}

void Dispenser::maxAvailableOutput(float gramm) {
    if(capacity >= static_cast<int>(gramm) ) {
        weight = gramm;
    }else{
        weight = static_cast<float>(capacity);
    }
}

float Dispenser::getPiecePerTime() const {
    return this->gramPerTime;
}

void Dispenser::decreaseCapacity(int amount) {
    capacity = capacity - amount;
    if(capacity < 0){
        capacity = 0;
    }
}
