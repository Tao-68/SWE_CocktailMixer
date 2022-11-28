#include "MixableRecipeBook.h"
#include <iostream>
//

void MixableRecipeBook::getAllCocktails() {
    std::cout << "*********************************************" << std::endl;
    std::cout << "Es gibt " << this->getNumberOfRecipes() << " Cocktails" << std::endl;

    for (int i = 0; i<this->getNumberOfRecipes(); i++) {
        Recipe* r = this->getRecipe(i);
        std::cout << i + 1 << ". ";
        r->getAllIngredients();
        std::cout << std::endl;
    }
    std::cout << "*********************************************" << std::endl;

}

MixableRecipeBook::MixableRecipeBook(AvailableIngredients * zv) {

    // Debug *********
    std::cout << "********** Rezepte vor dem Filtern **********" << std::endl;
    getAllCocktails();
    // ******************

    setZutatenVerwalter(zv);

    bool istZutatGefunden = false;
    for (int i = 0; i < getNumberOfRecipes(); i++) {
        Recipe *r = getRecipe(i);

        // Steps durchgehen
        for (int j = 0; j < r->getNoOfRecipeSteps(); j++) {
            std::string gesuchteZutat;
            gesuchteZutat = r->getRecipeStep(j)->getZutat();
            istZutatGefunden = sucheZutat(gesuchteZutat);

            if (!istZutatGefunden) {
                deleteRecipe(i);
                i--;
                break;
            }
        }
    }
}

bool MixableRecipeBook::sucheZutat(const std::string &gesuchteZutat) {
    for (int k = 0; k < myZutatenVerwalter->getNumberAvailableIngredients(); k++) {
        if (myZutatenVerwalter->getIngredient(k) == gesuchteZutat) {
            return true;
        }
    }
    return false;
}

void MixableRecipeBook::setZutatenVerwalter(AvailableIngredients * zv) {
    myZutatenVerwalter = zv;
}
