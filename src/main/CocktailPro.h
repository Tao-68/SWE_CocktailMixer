#ifndef COCKTAILPRO_H_H
#define COCKTAILPRO_H_H

#include "DeviceManager.h"
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
    BarTender *barTender;

    /**
     * This is the device manager that the CocktailPro uses only in constructor.
     */
    DeviceManager *theDeviceVerwalter;

    /**
    * This is the book of mixable recipe that the CocktailPro uses in constructor,
    * start method, demo method and selectCocktail method.
    */
    MixableRecipeBook *mixableRecipeBook;

    /**
    * This is the available ingredients manager that the CocktailPro uses only in constructor.
    */
    AvailableIngredients *availableIngredients;

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
    * print a text to the terminal.
    */
    void selectCocktail();

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
     * @brief Destructor for a CocktailPro object.
     * removes a pointer to the BarTender, a pointer to the DeviceManager,
     * a pointer to the MixableRecipeBook and a pointer to the AvailableIngredients.
     */
    ~CocktailPro();

    /**
     * @brief Copy constructor that creates a CocktailPro object from the param.
     * @param cocktailPro is valid CocktailPro object.
     */
    CocktailPro(const CocktailPro &cocktailPro);


    /**
     * @brief Assignment operator for CocktailPro object.
     * @param rhs must be a valid CocktailPro object.
     * @return copied CocktailPro object.
     */
    CocktailPro& operator=(CocktailPro rhs);

    /**
     * @brief swap a data between two CocktailPro objects.
     * @param lhs must be a valid CocktailPro object.
     * @param rhs must be a valid CocktailPro object.
     */
    friend void swap(CocktailPro &lhs, CocktailPro &rhs);

    /**
    * @brief Starts a cocktail preparing
    *
    * This method prompts the user for a recipe number,
    * which he should select to continue the process
    * and checks the dialed number, whether it is selected meaningfully or not.
    *
    */
    void start();


    /**
     * @brief validate selected number
     * @param cocktailNumberInput  must be an integer number.
     */
    void validateSelectedNumber(int cocktailNumberInput);

    /**
     * @brief checks, if cocktailNumberInput is not valid cocktail number.
     * @param cocktailNumberInput must be an integer number.
     * @return true if cocktailNumberInput is not valid number, otherwise false.
     */
    bool isNotValidNumber(int cocktailNumberInput) const;

    /**
     * @brief print message, that input was not valid.
     * @param cocktailNumberInput must be an integer number.
     */
    void notValidInputMsg(int cocktailNumberInput);
};

#endif
