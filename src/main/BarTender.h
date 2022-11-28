#ifndef COCKTAILZUBEREITER_H_H
#define COCKTAILZUBEREITER_H_H

#include "Recipe.h"
#include "RecipeBook.h"
#include "DeviceManager.h"

/**
* @class BarTender
*
* @brief BarTender prepares a cocktail following the recipe steps.
*
*/
class BarTender {
public:
    /**
     * @brief Constructor that creates a BarTender.
     *
     * @param dv must not be null.
     *
     * Initializes a device manager (myDeviceVerwalter) variable.
     */
    explicit BarTender(DeviceManager * dv);


    /**
     * @brief Prepares a cocktail following the recipe steps.
     *
     * @param recipe must not be null.
     *
     * @return always true.
     */
    bool prepareCocktail(Recipe * recipe);

private:

    /**
    * This is the device manager that the BarTender uses for cocktail preparing.
    */
    DeviceManager * myDeviceVerwalter;

    /**
     * This cleaning all devices that are to clean up
     */
    void cleaningDevices();


};

#endif
