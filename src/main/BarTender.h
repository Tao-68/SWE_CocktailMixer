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

    /**
     * @brief  undrinkableCocktailDetected starts the drainer action and clean devices method.
     */
    void undrinkableCocktailDetected();

private:

    /**
     * This is number of steps done. We set this value, if we invoke the method prepareCocktail,
     * and we have undrinkable cocktail.
     *
     */
    int numberOfStepsDone = 0;

    /**
    * This is the device manager that the BarTender uses for cocktail preparing.
    */
    DeviceManager * myDeviceVerwalter;

    /**
     * This cleaning all devices that are to clean up
     */
    void cleaningDevices();

    /**
     *
     * @param s must be a valid string like "Eis" or "Mischen".
     * @return "Dosierer" or "Device" depend on input string s.
     */
    std::string getRightNameOfDevices(std::string s);

    /**
     *
     * @param s must be a valid string like "Eis", "Zucker" and so on.
     * @return "g" or "ml" depend on input string s.
     */
    std::string getIngridientType(std::string s);
};

#endif
