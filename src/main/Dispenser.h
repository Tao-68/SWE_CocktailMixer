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
     * Initializes the number of gram per time, the scale (Waage) and the content (inhalt).
     *
     * @param g must not be null.
     * @param ze must not be null.
     * @param inhalt must be a valid string.
     * @param wg must be not null pointer.
     */
    Dispenser(float g, int ze, const std::string &inhalt, Waage * wg);

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
    int getStueckProZeit();

private:

    /**
     * This is the number of gram per time,
     * that Dispenser uses in constructor, doIt method and getStueckProZeit method.
     */
    float grammProZeit;

    /**
     * This is the scale (Waage), that Dispenser uses in constructor, doIt method and update method.
     */
    Waage * myWaage;

    /**
     * This is the weight, that Dispenser uses in doIt method and update method.
     */
    float gwicht;

    /**
     * This is the content, that Dispenser uses in constructor and doIt method.
     */
    std::string inhalt;
};

#endif
