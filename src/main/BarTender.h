#ifndef COCKTAILZUBEREITER_H_H
#define COCKTAILZUBEREITER_H_H

#include "Recipe.h"
#include "RecipeBook.h"
#include "DeviceVerwalter.h"

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
    BarTender(DeviceVerwalter * dv);

    /**
     * @brief Prepares a cocktail following the recipe steps.
     *
     * @param rzpt must not be null.
     *
     * @return always true.
     */
    bool cocktailZubereiten(Recipe * rzpt);

private:

    /**
    * This is the device manager that the BarTender uses for cocktail preparing.
    */
    DeviceVerwalter * myDeviceVerwalter;


};

#endif
