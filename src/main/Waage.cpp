//@(#) Waage.cpp


#include "Waage.h"

void Waage::changeWeight(int value) {
    weight += value;
    if (weight < 0)
        weight = 0;
    deltaWeight += value;
    notify();
}

int Waage::resetDeltaWeight() {
    return deltaWeight = 0;
}

int Waage::getWeight() {
    return weight;
}

int Waage::getDeltaWeight() {
    return deltaWeight;
}

Waage::Waage(int waageWeight, int waageDeltaWeight): weight(waageWeight), deltaWeight(waageDeltaWeight){

}
