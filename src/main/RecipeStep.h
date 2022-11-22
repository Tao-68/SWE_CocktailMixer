#ifndef _REZEPTSCHRITT_H_472
#define _REZEPTSCHRITT_H_472

#include <list>
#include <string>

/**
 * @class RecipeStep
 *
 * @brief RecipeStep stores the ingredient and amount required
 *
 * A RecipeStep stores the ingredient name and amount required
 * You can ask for the name of ingredient, amount required
 * or set the name of ingredient, amount required
 *
 */
class RecipeStep {
 private:
    /**
    * Each step has an ingredient
    */
    std::string zutat;

    /**
    * Each step has a required amount of the ingredient
    */
    float menge;

 public:

    /** @brief Constructor that creates a RecipeStep
    * @return The created RecipeStep object
    *
    * This method creates a RecipeStep
    * The ingredient (Zutat) is set to an empty string
    * And the amount (Menge) is set to zero
    */
    RecipeStep();

    /** @brief Destructor that deletes the RecipeStep
    */
    ~RecipeStep();

    /** @brief Gets the ingredient (zutat) of RecipeStep
    * @return The name of ingredient in the RecipeStep
    */
    std::string getZutat() const;

    /** @brief Gets the amount (menge) of RecipeStep
    * @return The amount of ingredient in the RecipeStep
    */
    float getMenge() const;

    /** @brief Sets ingredient for the RecipeStep
    * @param [in] inputZutat the ingredient for the RecipeStep
    */
    void setZutat(const std::string& inputZutat);

    /** @brief Sets amount for the RecipeStep
    * @param [in] inputMenge the amount for the RecipeStep
    */
    void setMenge(float inputMenge);

};
#endif
