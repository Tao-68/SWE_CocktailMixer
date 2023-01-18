#ifndef ENTLEERER_H_H
#define ENTLEERER_H_H

#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

/**
 * @class Drainer
 *
 * @brief starts drainer (Abtropffläche) action, invokes update.
 *
 * Drainer extends InternalDevice and Observer.
 */
class Drainer : public InternalDevice, public Observer {
public:

    /**
     * @brief Constructor that creates Drainer object.
     *
     * Invokes constructor of InternalDevice.
     * initializes the number of gram per time and the scale (Waage).
     *
     * @param g must not be null.
     * @param ze must not be null.
     * @param wg must not be null pointer.
     */
    Drainer(float g, int ze, Waage * wg);

    /**
    * @brief Destructor that deletes the Drainer.
    */
    ~Drainer();


    /**
     * @brief sets doinIt to false, if the drainer finished the action.
     *
     * Implements the method of Observer.
     *
     */
    void update() override;

    /**
     * @brief Starts the drainer action.
     * @param drainValue  must not be null.
     */
    bool doIt(float drainValue) override;

private:


    /**
     * This is the number of gram per time,
     * that the drainer uses in constructor and doIt method.
     */
    float gramPerTime;

    /**
     * This is the scale (Waage), that the Drainer uses in constructor, doIt method and update method.
     */
    Waage * scale;

    /**
     * This is the value, that the Drainer uses in doIt method and update method.
     */
    float value = 0;

    /**
     * Undrinkable Cocktail if a recipe step is failed
     * because we do not have enough an amount of ingredient or ingredient is missing.
     */
    bool isUndrinkableCocktail = false;

};

#endif
