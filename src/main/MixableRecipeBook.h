#ifndef MISCHBARESREZEPTBUCH_H_H
#define MISCHBARESREZEPTBUCH_H_H

#include "Recipe.h"
#include "RecipeBook.h"
#include "AvailableIngredients.h"

#include <iostream>
#include <fstream>
#include <string>

/**
* @class MixableRecipeBook
* @brief This class is inherits from RecipeBook
* This class managing the recipes.
* It can output all recipes and work with ingredients for the available recipes.
*/
class MixableRecipeBook : public RecipeBook {
public:
    /**
     * @brief searching for all recipes if there whether the required ingredients are available.
     * When the ingredient for an recipe not exist anymore then the recipe will be deleted
     * @param ze
     */
    explicit MixableRecipeBook(AvailableIngredients * ze);

    /**
     * @brief Output of all existing Cocktails.
     */
    void browse();

private:
    /**
    * This is the pointer to available ingredients that MixableRecipeBook uses in the constructor.
    */
    AvailableIngredients * myZutatenVerwalter;

    /**
    * This is a vector of all recipes
    */
    std::vector<Recipe *> rezepte;

    /** @brief This is a setter-method for variable myZutatenVerwalter
     *  @param ze
     */
    void setZutatenVerwalter(AvailableIngredients * ze);

};

#endif
