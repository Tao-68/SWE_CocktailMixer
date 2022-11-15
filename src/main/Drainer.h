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
    * @brief Destructor that deletes the RecipeBook.
    */
    ~Drainer();


    /**
     * @brief sets doinIt to false, if the drainer finished the action.
     *
     * Implements the method of Observer.
     *
     */
    void update();

    /**
     * @brief Starts the drainer action.
     * @param value  must not be null.
     */
    void doIt(float drainValue);

private:


    /**
     * This is the number of gram per time,
     * that the drainer uses in constructor and doIt method.
     */
    float grammProZeit;

    /**
     * This is the scale (Waage), that the Drainer uses in constructor, doIt method and update method.
     */
    Waage * myWaage;

    /**
     * This is the value, that the Drainer uses in doIt method and update method.
     */
    float value;

};

#endif
