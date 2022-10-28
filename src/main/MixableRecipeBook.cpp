//@(#) MixableRecipeBook.cpp


#include "MixableRecipeBook.h"
#include <iostream>
//

void MixableRecipeBook::browse() {
    std::cout << "*********************************************" << std::endl;
    std::cout << "Es gibt " << this->getNumberOfRecipes() << " Cocktails" << std::endl;

    for (int i = 0; i<this->getNumberOfRecipes(); i++) {
        Recipe* r = this->getRecipe(i);
        std::cout << i + 1 << ". ";
        r->browse();
        std::cout << std::endl;
    }
    std::cout << "*********************************************" << std::endl;

}

MixableRecipeBook::MixableRecipeBook(AvailableIngredients * zv) {

    // Debug *********
    std::cout << "********** Rezepte vor dem Filtern **********" << std::endl;
    browse();
    // ******************

    setZutatenVerwalter(zv);

  for (int i = 0; i < getNumberOfRecipes(); i++) {
    bool x;
    Recipe *r = getRecipe(i);
    x = true;
    for (int j = 0; j < r->getNoOfRecipeSteps(); j++) {
      std::string gesuchteZutat;

      gesuchteZutat = r->getRecipeStep(j)->getZutat();
      bool zOk = false;

      for (int k = 0; k < myZutatenVerwalter->getAnzahlVorhandeneZutaten(); k++) {
        if (myZutatenVerwalter->getZutat(k) == gesuchteZutat) {
          zOk = true;
          break;
        }
      }
      if (!zOk) {
        x = false;
      }
    }
    if (!x) {
      deleteRecipe(i);
    }
  }
}

void MixableRecipeBook::setZutatenVerwalter(AvailableIngredients * zv) {
    myZutatenVerwalter = zv;
}

