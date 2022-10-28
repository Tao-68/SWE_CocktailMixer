
#include <algorithm>

#include "RecipeStep.h"

/**
 * Konstruktor 
 *  
 */
RecipeStep::RecipeStep(void) {
    m_Zutat = "";
    m_Menge = 0;
}

RecipeStep::~RecipeStep() {
}

std::string RecipeStep::getZutat(void) const {
    return m_Zutat;
}

float RecipeStep::getMenge(void) const {
    return m_Menge;
}

void RecipeStep::setZutat(std::string m_Zutat) {
    this->m_Zutat = m_Zutat;
}

void RecipeStep::setMenge(float m_Menge) {
    this->m_Menge = m_Menge;
}
