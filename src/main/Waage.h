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
 * or modify both weight and delta weight
 */
class Waage : public Subject {
 public:

    /** @brief Updates the value of weight and delta weight
    * @param [in] v The value that changes the initial weight and delta weight
    *
    * This method assigns the value 0 to weight if weight < 0.
    * And updates the observers.
    */
    void changeWeight(int v);

    /** @brief Resets the value of delta weight to zero
    * @return The value zero for delta weight
    */
    int tara();

    /** @brief Gets the weight value
    * @return The value for weight
    */
    int getWeight();

    /** @brief Gets the delta weight value
    * @return The value for delta weight
    */
    int getDelta();
 private:
    int weight;
    int deltaweight;
};

#endif
