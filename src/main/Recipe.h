#ifndef _REZEPT_H_479
#define _REZEPT_H_479

#include "RecipeStep.h"

#include <list>
#include <string>
/**
 * @class Recipe
 * @brief This class is a recipe and manage there recipe steps
 */
class Recipe {
private:
    /**
     * @brief List of the recipe steps of this recipe
     */
    std::list<RecipeStep*> m_RecipeStep;

    /**
     * Variable Name
     */
    std::string m_Name;

public:
    /**
     * @brief Deletes the current recipe step and sets the default name
     */
    Recipe(void);

    /**
     * @brief Destructor. No code yet.
     */
    ~Recipe();


    /**
     * @brief Give number of recipe steps from the list "m_RecipeStep".
     * @return Number of recipe steps
     */
    int getNoOfRecipeSteps();
    
    /**
     * @brief Returns a pointer of the recipe step by position i,
     * provided i is not greater than the maximum steps.
     * @param i
     * @return A pointer to the recipe step by position i
     */
    RecipeStep * getRecipeStep(unsigned int i);

    /**
     * @brief Getter-method of name
     * @return Get the variable name
     */
    std::string getName(void) const;

    /**
     * @brief Setter-method of name
     * @return Set the variable name
     */
    void setName(const std::string& Name);

    /**
     * @brief Adds another step to the recipe.
     * The step includes a used ingredient and its quantity.
     * The step is then added to the "m_RecipeStep" list
     * @param z
     * @param m
     */
    void appendStep(std::string z, float m);

    /**
     * @brief Returns all the ingredients that are needed for the individual steps of the calling recipe
     */
    void browse();

};

#endif
