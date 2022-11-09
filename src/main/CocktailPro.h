#ifndef COCKTAILPRO_H_H
#define COCKTAILPRO_H_H

#include "DeviceVerwalter.h"
#include "AvailableIngredients.h"
#include "MixableRecipeBook.h"
#include "BarTender.h"

/**
* @class CocktailPro
*
* @brief CocktailPro manages entire program.
*
* Initializes an objects, that we need for preparing a cocktail.
* you can select a recipe number, starts a cocktail preparing or
* starts a demo version of cocktail preparing.
*/
class CocktailPro {

protected:

    /**
    * This is the bar tender that the CocktailPro uses in constructor, start method and demo method.
    */
    BarTender *theCocktailZubereiter;

    /**
     * This is the device manager that the CocktailPro uses only in constructor.
     */
    DeviceVerwalter *theDeviceVerwalter;

    /**
    * This is the book of mixable recipe that the CocktailPro uses in constructor,
    * start method, demo method and waehle method.
    */
    MixableRecipeBook *theMischbaresRezeptbuch;

    /**
    * This is the available ingredients manager that the CocktailPro uses only in constructor.
    */
    AvailableIngredients *theZutatenVerwalter;

    /**
     * Enum modes that the CocktailPro uses in constructor and start method.
     */
    enum OpMode {
        NORMAL, DEMO, STOP
    };

    /**
     * Operating mode that the CocktailPro uses in constructor and start method.
     */
    OpMode OperatingMode = NORMAL;

protected:

    /**
    * @brief Selects the recipe number.
    * @return the selected recipe number or -1 to exit.
    *
    * print a text to the terminal.
    */
    int waehle();

    /**
    * @brief starts a cocktail preparing for test purposes.
    *
    */
    void demo();

public:

    /**
    * @brief Constructor that creates a CocktailPro object.
    * @param argc is the number of command line options.
    * @param turbo are individual command line options.
    *
    * Initializes the bar tender, the device manager, the book of mixable recipe and
    * the available ingredient's manager.
    * Sets time.
    */
    CocktailPro(int argc, char **turbo);

    /**
    * @brief Starts a cocktail preparing
    *
    * This method prompts the user for a recipe number,
    * which he should select to continue the process
    * and checks the dialed number, whether it is selected meaningfully or not.
    *
    */
    void start();


};

#endif
