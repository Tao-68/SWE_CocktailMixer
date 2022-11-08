#ifndef _REZEPTSCHRITT_H_472
#define _REZEPTSCHRITT_H_472

#include <list>
#include <string>

/**
 * @class RecipeStep
 *
 * @brief RecipeStep stores the ingredient and amount required.
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
    std::string m_Zutat;

    /**
    * Each step has a required amount of the ingredient
    */
    float m_Menge;

 public:

    /** @brief Constructor that creates a RecipeStep
    * @return The created RecipeStep object
    *
    * This method creates a RecipeStep.
    * The ingredient (Zutat) is set to an empty string
    * and the amount (Menge) is set to zero.
    */
    RecipeStep(void);

    /** @brief Destructor that deletes the RecipeStep
    */
    ~RecipeStep();

    /** @brief Gets the ingredient (Zutat) of RecipeStep
    * @return The name of ingredient in the RecipeStep
    */
    std::string getZutat(void) const;

    /** @brief Gets the amount (Menge) of RecipeStep
    * @return The amount of ingredient in the RecipeStep
    */
    float getMenge(void) const;

    /** @brief Sets ingredient for the RecipeStep
    * @param [in] m_Zutat the ingredient for the RecipeStep
    */
    void setZutat(std::string m_Zutat);

    /** @brief Sets amount for the RecipeStep
    * @param [in] m_Menge the amount for the RecipeStep
    */
    void setMenge(float m_Menge);

};
#endif
