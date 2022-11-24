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

    /**
     * @brief Constructor that creates a Waage.
     *
     * @param waageWeight must not be null.
     * @param waageDeltaWeight must not be null.
     *
     * Creates a Waage object.
     * Initializes the private variables 'waageWeight' and 'waageDeltaweight'.
     */
    Waage(int waageWeight, int waageDeltaWeight);

    /** @brief Updates the value of weight and delta weight
    * @param [in] value The value that changes the initial weight and delta weight
    *
    * This method assigns the value 0 to weight if weight < 0.
    * And updates the observers.
    */
    void changeWeight(int value);

    /** @brief Resets the value of delta weight to zero
    * @return The value zero for delta weight
    */
    int resetDeltaWeight();

    /** @brief Gets the weight value
    * @return The value for weight
    */
    int getWeight();

    /** @brief Gets the delta weight value
    * @return The value for delta weight
    */
    int getDeltaWeight();
 private:
    int weight;
    int deltaWeight;
};

#endif
