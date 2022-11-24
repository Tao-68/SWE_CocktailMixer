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
     * @param content must be a valid string.
     * @param scale must be not null pointer.
     */
    Dispenser(float gram, int timeUnit,  std::string content, Waage * scale);

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
    void doIt(float gramm);

    /**
     * @brief Returns the number of gram per time.
     *
     * @return the number of gram per time.
     */
    float getPiecePerTime() const;

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
};

#endif
