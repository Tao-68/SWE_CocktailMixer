#ifndef DOSIERER_H_H
#define DOSIERER_H_H

#include <string>
#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

/**
* @class Dispenser
*
* @brief starts Dispenser (Spender), invokes update.
*
* Dispenser extends InternalDevice and Observer.
*/
class Dispenser : public InternalDevice, public Observer {
public:

    /**
     * @brief Constructor that creates a Dispenser object.
     *
     * Invokes Constructor of InternalDevice.
     * Initializes the number of gram per time, the scale (Waage) and the content (content).
     *
     * @param gram must not be null.
     * @param timeUnit must not be null.
     * @param dispenserContent must be a valid string.
     * @param dispenserScale must be not null pointer.
     * @param type must not be null
     */
    Dispenser(float gram, int timeUnit, const std::string &dispenserContent, Waage * dispenserScale, const std::string &type);

    /**
     * @brief Destructor for Dispenser object.
     */
    ~Dispenser();

    /**
     * @brief sets doinIt to false, if the dispenser finished the action.
     *
     * Implements the method of Observer.
     *
     */
    virtual void update();

    /**
     * @brief starts the dispenser action.
     *
     * @param gramm must not be null.
     */
    bool doIt(float gramm);

    /**
     * @brief Returns the number of gram per time.
     *
     * @return the number of gram per time.
     */
    float getPiecePerTime() const;

    /**
     * @brief Decrease the Capacity with weight
     * @param amount
     */
    void decreaseCapacity(int amount);

    /**
     * @brief We use this method in CocktailPro for checking, if we have enough dispenser capacity for cocktail preparation.
     * @return dispenser capacity value
     */
    int getCapacity() const;

private:

    /**
     * This is the number of gram per time,
     * that Dispenser uses in constructor, doIt method and getPiecePerTime method.
     */
    float gramPerTime;

    /**
     * This is the scale (Waage), that Dispenser uses in constructor, doIt method and update method.
     */
    Waage * scale;

    /**
     * This is the weight, that Dispenser uses in doIt method and update method.
     */
    float weight;

    /**
     * This is the content, that Dispenser uses in constructor and doIt method.
     */
    std::string content;

    /**
     * This is the capacity, that Dispenser know how many uses it can take
     */
    int capacity;

    /**
     * This is the weightTyp, that Dispenser calculates the right capacity
     */
     std::string weightTyp;

    void maxAvailableOutput(float gramm);
};

#endif
