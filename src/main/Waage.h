//@(#) Waage.h

#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "Subject.h"

class Waage : public Subject {
 public:
    void changeWeight(int v);
    int tara();
    int getWeight();
    int getDelta();
 private:
    int weight;
    int deltaweight;
};

#endif
