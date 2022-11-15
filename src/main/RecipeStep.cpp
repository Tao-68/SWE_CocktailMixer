
#include <algorithm>

#include "RecipeStep.h"

/**
 * Constructor
 *  
 */
RecipeStep::RecipeStep(void): m_Zutat(""), m_Menge(0){

}

RecipeStep::~RecipeStep() {
}

std::string RecipeStep::getZutat(void) const {
    return m_Zutat;
}

float RecipeStep::getMenge(void) const {
    return m_Menge;
}

void RecipeStep::setZutat(const std::string &zutat) {
    m_Zutat = zutat;
}

void RecipeStep::setMenge(float menge) {
    m_Menge = menge;
}
