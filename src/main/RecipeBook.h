#ifndef RECIPEBOOK_H_489
#define RECIPEBOOK_H_489

#include <fstream>
#include <sstream>

#include <iostream>

#include <list>
#include <string>

#include "Recipe.h"

/**
 * @class RecipeBook
 *
 * @brief RecipeBook manages a collection of recipes
 *
 * A RecipeBook knows a list of recipes
 * You can ask for the number of recipes, query recipes by index
 * or delete a recipe
 *
 */
class RecipeBook {
    /**
    * This is the list of recipes that the RecipeBook manages
    */
private:
    std::list<Recipe *> recipes;

    /**
    * Counter variable
    * which increments for each cocktail
    */
    int counter = 0;

public:
    /** @brief Constructor that creates a RecipeBook
    * @return A pointer to the created RecipeBook
    *
    * This method creates a RecipeBook.
    * It uses temporarily an object of the class Initializer
    * to initialize the list of recipes. After that the
    * Initializer is destroyed.
    */
    RecipeBook();

    /** @brief Destructor that deletes the RecipeBook
    */
    virtual ~RecipeBook();

    /** @brief Returns the number of recipes
    * @return The number of recipes in the RecipeBook
    */
    int getNumberOfRecipes();

    /** @brief fetches the i-th recipe at position recipeIndex
    * @param [in] recipeIndex a positive integer for the i-th recipe
    * @return A pointer to the requested recipe object, NULL for invalid recipeIndex
    *
    * This method returns the recipeIndex-th recipe;
    * where recipeIndex is an integer from 0 to n-1
    * where n is the number of recipes in the RecipeBook
    */
    Recipe *getRecipe(unsigned int recipeIndex);

    /** @brief fetches the i-th recipe at position recipeIndex
    * @param [in] recipeID a positive integer for the recipe ID
    * @return A pointer to the requested recipe object, NULL for invalid recipeIndex
    *
    * This method returns the recipeID of recipe;
    * where recipeIndex is constant for each cocktail
    */
    Recipe *getRecipeWithID(unsigned int recipeID);


    /** @brief Deletes the i-th recipe from the RecipeBook at position recipeIndex
    * @param [in] recipeIndex a positive integer for the i-th recipe
    * @return Boolean that indicates whether the deletion was successful
    *
    * This method deletes the recipeIndex-th recipe from the RecipeBook.
    * And returns true if the deletion was successful (valid recipeIndex).
    * For values of recipeIndex that are invalid (recipeIndex < 0 or recipeIndex >= n) the function return false.
    */
    bool deleteRecipe(unsigned int recipeIndex);

    /** @brief Function that creates a Recipe Object
    * @param [in] r1 pointer to class Recipe
    *
    * This method creates the Recipe object for Caipirinha.
    * It sets the name of Recipe and manages the ingredients (zutat) and amounts (menge).
    */
    void createCaipirinha();

    /** @brief Function that creates a Recipe Object
    * @param [in] r1 pointer to class Recipe
    *
    * This method creates the Recipe object for Margarita.
    * It sets the name of Recipe and manages the ingredients (zutat) and amounts (menge).
    */
    void createMargarita();

    /** @brief Function that creates a Recipe Object
    * @param [in] r1 pointer to class Recipe
    *
    * This method creates the Recipe object for Daiquri.
    * It sets the name of Recipe and manages the ingredients (zutat) and amounts (menge).
    */
    void createDaiquiri();

    /** @brief Function that creates a Recipe Object
    * @param [in] r1 pointer to class Recipe
    *
    * This method creates the Recipe object for Planters Punch.
    * It sets the name of Recipe and manages the ingredients (zutat) and amounts (menge).
    */
    void createPlantersPunch();

    /** @brief Function that creates a Recipe Object
    * @param [in] r1 pointer to class Recipe
    *
    * This method creates the Recipe object for Caipiroska.
    * It sets the name of Recipe and manages the ingredients (zutat) and amounts (menge).
    */
    void createCaipiroska();

    /** @brief Function that creates a Recipe Object
    * @param [in] r1 pointer to class Recipe
    *
    * This method creates the Recipe object for Caipirissima.
    * It sets the name of Recipe and manages the ingredients (zutat) and amounts (menge).
    */
    void createCaipirissima();

    /** @brief Function that creates a Recipe Object
    * @param [in] r1 pointer to class Recipe
    *
    * This method creates the Recipe object for Cuban Island.
    * It sets the name of Recipe and manages the ingredients (zutat) and amounts (menge).
    */
    void createCubanIsland();

    /** @brief Function that creates a Recipe Object
    * @param [in] r1 pointer to class Recipe
    *
    * This method creates the Recipe object for Martini James B.
    * It sets the name of Recipe and manages the ingredients (zutat) and amounts (menge).
    */
    void createMartiniJamesB();
};

#endif
