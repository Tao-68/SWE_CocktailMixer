//@(#) Waage.h

#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "Subject.h"
/**
 * @class Waage
 *
 * @brief Waage manages the weight
 *
 * A Waage manages the weights
 * You can ask for the weight, delta weight
 * or modify the weight value
 */
class Waage : public Subject {
 public:
    void changeWeight(int v);

    /** @brief Resets the value of deltaweight to zero
    * @return The value zero for delta weight
    */
    int tara();

    /** @brief Fetches the weight value
    * @return The value for weight
    */
    int getWeight();

    /** @brief Fetches the delta weight value
    * @return The value for delta weight
    */
    int getDelta();
 private:
    int weight;
    int deltaweight;
};

#endif
