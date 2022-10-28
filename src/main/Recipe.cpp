
#include <algorithm>
#include <iostream>

#include "Recipe.h"

Recipe::Recipe(void) {
    m_RecipeStep.clear();
    m_Name = "";
}

Recipe::~Recipe() {
}

int Recipe::getNoOfRecipeSteps() {
    return (m_RecipeStep.size());
}

RecipeStep * Recipe::getRecipeStep(unsigned int i) {
    if (i > m_RecipeStep.size()) return NULL;
    else {
        std::list<RecipeStep*>::iterator p; // Iterator
        advance(p = m_RecipeStep.begin(), i); // p zeigt jetzt auf das i-te Element
        return (*p); // Adresse vom Wert von p - also den Pointer auf den der Iterator zeigt
    }
}

std::string Recipe::getName(void) const {
    return m_Name;
}

void Recipe::setName(const std::string& Name) {
    this->m_Name = Name;
}

void Recipe::browse() {
    std::cout << m_Name << ": ";
    for (int i = 0; i< this->getNoOfRecipeSteps(); i++) {
        if (i > 0) std::cout << ", ";
        std::cout << getRecipeStep(i)->getZutat();
    }
}

void Recipe::appendStep(std::string z, float m) {
    RecipeStep* t;
    t = new RecipeStep;
    t->setZutat(z);
    t->setMenge(m);
    m_RecipeStep.push_back(t);
}
