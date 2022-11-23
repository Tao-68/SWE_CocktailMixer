
#include <algorithm>

#include "RecipeStep.h"

/**
 * Constructor
 *  
 */
RecipeStep::RecipeStep(): zutat(""), menge(0){

}

RecipeStep::~RecipeStep() {
}

std::string RecipeStep::getZutat() const {
    return zutat;
}

float RecipeStep::getMenge() const {
    return menge;
}

void RecipeStep::setZutat(const std::string& inputZutat) {
    zutat = inputZutat;
}

void RecipeStep::setMenge(float inputMenge) {
    menge = inputMenge;
}
