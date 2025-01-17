#ifndef DEVICEVERWALTER_H_H
#define DEVICEVERWALTER_H_H

#include <string>
#include <map>
#include <list>
#include <algorithm>

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
     * invokes setIngredientsManager method and createDevices method.
     *
     * @param ze must not be null pointer.
     */
    explicit DeviceManager(AvailableIngredients *ze);

    /**
     * @brief prepares the steps of recipe.
     *
     * @param ingredient must be a valid ingredient. Special case by the "Limettenstuecke" ingredient.
     *
     * @param amount must not be null.
     *
     */
    bool prepareRecipeSteps(std::string ingredient, float amount);

    /**
     * This is the drainer, that the DeviceManager uses in createDevices method.
     */
    Drainer *drainer;

    /**
     * This is the map, where strings are the keys and pointers of InternalDevice are value.
     * Apart from that, the DeviceManager uses this map in createDevices method
     * and prepareRecipeSteps method.
     */
    std::map<std::string, InternalDevice *> *devices;

    /**
     * This is a list which store pointers of InternalDevice.
     * This allows duplicate in ingredients.
     */
    std::list<InternalDevice *> deviceList;

    /**
     * This is a vector with iterator on map from devices, where all used Devices from the BarTender that have to clean up
     */
    std::vector<std::map<std::string, InternalDevice *>::iterator> usedDevices;


private:

    /**
     * @brief sets ingredients manager.
     *
     * @param ze must not be null pointer.
     */
    void setIngredientsManager(AvailableIngredients *ze);

    /**
     * This is the mixer, that the DeviceManager uses in createDevices method.
     */
    Mixer *mixer;

    /**
     * This is the masher, that the DeviceManager uses in createDevices method.
     */
    Masher *masher;

    /**
     * This is the shaker, that the DeviceManager uses in createDevices method.
     */
    Shaker *shaker;

    /**
     * This is the available ingredients, that the DeviceManager uses in createDevices method
     * and setIngredientsManager method.
     */
    AvailableIngredients *availableIngredients;

    /**
     * This is Scale (Waage) that, the DeviceManager uses in createDevices method.
     */
    Waage *scale;

    /**
     * @brief initializes the devices and sets the dispenser.
     *
     * Initializes the scale, the drainer, the masher, the shaker, the mixer device.
     */
    void createDevices();

    /**
     * @brief initializes all devices in CocktailPro.
     */
    void initializeDevices();

    /**
     * @brief initializes all dispensers depend on an available ingredients in CocktailPro.
     * @param myZutat must be a valid ingredient.
     */
    void initializeDispenser(std::string myZutat);

    /**
     * @brief add a new device in CocktailPro
     * @param myZutat must be a valid ingredient
     * @param gram must be a right amount of gram
     * @param timeUnit must be a right time unit.
     * @param type must be a right type ("ml" or "g")
     */
    void addDevice(std::string &myZutat, float gram, int timeUnit, const std::string &type);
};

#endif
