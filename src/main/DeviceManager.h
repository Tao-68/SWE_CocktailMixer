#ifndef DEVICEVERWALTER_H_H
#define DEVICEVERWALTER_H_H

#include <string>
#include <map>

#include "InternalDevice.h"
#include "AvailableIngredients.h"
#include "Dispenser.h"
#include "Mixer.h"
#include "Masher.h"
#include "Shaker.h"
#include "Drainer.h"
#include "Waage.h"

/**
* @class DeviceManager
*
* @brief DeviceManager manages the hardware.
*
* You can initialize the devices, set ingredients manager,
* prepare the steps of recipe.
*
*/
class DeviceManager {
public:

    /**
     * @brief Constructor that creates a DeviceManager object.
     *
     * invokes setZutatenVerwalter method and createDevices method.
     *
     * @param ze must not be null pointer.
     */
    DeviceManager(AvailableIngredients *ze);

    /**
     * @brief prepares the steps of recipe.
     *
     * @param zutat must be a valid ingredient. Special case by the "Limettenstuecke" ingredient.
     *
     * @param menge must not be null.
     *
     */
    void rezeptSchrittZubereiten(std::string zutat, float menge);

    /**
     * This is the drainer, that the DeviceManager uses in createDevices method.
     */
    Drainer *myEntleerer;

    /**
     * This is the map, where strings are the keys and pointers of InternalDevice are value.
     * Apart from that, the DeviceManager uses this map in createDevices method
     * and rezeptSchrittZubereiten method.
     */
    std::map<std::string, InternalDevice *> *myDevices;

private:

    /**
     * @brief sets ingredients manager.
     *
     * @param ze must not be null pointer.
     */
    void setZutatenVerwalter(AvailableIngredients *ze);

    /**
     * This is the mixer, that the DeviceManager uses in createDevices method.
     */
    Mixer *myMixer;

    /**
     * This is the masher, that the DeviceManager uses in createDevices method.
     */
    Masher *myStampfer;

    /**
     * This is the shaker, that the DeviceManager uses in createDevices method.
     */
    Shaker *mySchuettler;

    /**
     * This is the available ingredients, that the DeviceManager uses in createDevices method
     * and setZutatenVerwalter method.
     */
    AvailableIngredients *myZutatenVerwalter;

    /**
     * This is Scale (Waage) that, the DeviceManager uses in createDevices method.
     */
    Waage *theWaage;

    /**
     * @brief initializes the devices and sets the dispenser.
     *
     * Initializes the scale, the drainer, the masher, the shaker, the mixer device.
     */
    void createDevices();

};

#endif
