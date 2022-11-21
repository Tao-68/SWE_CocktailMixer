#ifndef VorhandeneZutaten_H_H
#define VorhandeneZutaten_H_H

#include <string>
#include <map>
#include <vector>
#include <list>
#include <fstream>

#include <iostream>


/**
* @class AvailableIngredients
*
* @brief AvailableIngredients manages a vector of ingredients.
*
* The vector of ingredients (ingredients) contains an ingredients and a state of aggregation (Mischen und Stampfen).
* You can read a file and add an ingredients to the vector of ingredients.
* Apart from that you can print the available ingredients, get an ingredient at specified position,
* get total number of saved elements in the vector of ingredients.
* Finally, you can add dummy data to the vector of ingredients for test purposes.
*/
class AvailableIngredients {
public:

    /** @brief Constructor that creates a AvailableIngredients object.
    *
    * Initializes a vector of ingredients (ingredients) variable.
    * Reads an ingredients file and adds each ingredient to the vector of ingredients (ingredients) variable.
    * Shows an available ingredients in the terminal.
    * Adds a state of aggregation (Mischen and Stampfen) to the vector of ingredients (ingredients).
    * Initializes a number of dispenser (numberOfDispenser) Variable.
    */
    AvailableIngredients(void);

    /**
     * @brief Destructor that deletes the AvailableIngredients.
     *
     * TODO: the vector of ingredients (ingredients) is a pointer and must be removed
     */
    virtual ~AvailableIngredients();

    /**
     * @brief Shows the available ingredients (ingredients)
     * and the state of aggregation (Mischen and Stampfen) line by line.
     *
     */
    void browse(void);

    /**
     * @brief Returns the ingredient (ingredients) at specified position.
     *
     * @param position must be a valid number for a size of the vector ingredients.
     * @return The ingredient at specified postion in the AvailableIngredients.
     */
    std::string getIngredient(int position);

    /**
     * @brief Returns the number than sum between
     * the number of saved ingredients and the number of saved state of aggregation.
     *
     * @return The number of saved elements in the AvailableIngredients.
     */
    int getNumberAvailableIngredients();

private:
    /**
    * This is the vector of ingredients that the AvailableIngredients manages
    *
    */
    std::vector<std::string> *ingredients;

    /**
     * This is the number of Dispenser that the AvailableIngredients uses
     */
    int numberOfDispenser;

    /**
     * This is the debug that the AvailableIngredients uses for test purposes
     */
    static const bool DEBUG = false;

    /**
     * @brief adds a dummy data to the vector of ingredients (ingredients) for test purposes
     */
    void insertDummyData();


    /**
     * @brief Reads an ingredients file and adds each
     *
     * @param fileName must be a valid file name.
     * ingredient to the vector of ingredients (ingredients) variable.
     */
    virtual void readIngredientsFile(std::string fileName);

};
#endif
