#include "CocktailPro.h"
#include <string>

void CocktailPro::start() {

  while (OperatingMode == OpMode::NORMAL) {
    int CocktailNo = selectCocktail();

    if (CocktailNo == -1)
      OperatingMode = OpMode::STOP;
    else {
      int max = mixableRecipeBook->getNumberOfRecipes();
      if (CocktailNo <= max) {
        Recipe *rezeptptr = mixableRecipeBook->getRecipe(CocktailNo - 1);
        std::cout << rezeptptr->getName() << std::endl;
        barTender->prepareCocktail(rezeptptr);
      } else
        std::cout << "Falsche Cocktailnummer!" << std::endl;
    }
  }
}

CocktailPro::CocktailPro(int argc, char **param) {
    availableIngredients = new AvailableIngredients;

    mixableRecipeBook = new MixableRecipeBook(availableIngredients);
  theDeviceVerwalter = new DeviceManager(availableIngredients);
    barTender = new BarTender(theDeviceVerwalter);

  Timer *theTimer = Timer::getInstance();
  if (argc == 2) {
    if (std::string(param[1]) == "-D") {
      this->OperatingMode = OpMode::DEMO;
      theTimer->set_Turbo(1000); // increase preparing time ?
      this->demo();
    } else {
      theTimer->set_Turbo(10);
    }
  }
}

CocktailPro::~CocktailPro() {
    delete availableIngredients;
    delete mixableRecipeBook;
    delete theDeviceVerwalter;
    delete barTender;
}

CocktailPro::CocktailPro(const CocktailPro &cocktailPro) {

    availableIngredients = new AvailableIngredients;

    mixableRecipeBook = new MixableRecipeBook(availableIngredients);
    theDeviceVerwalter = new DeviceManager(availableIngredients);
    barTender = new BarTender(theDeviceVerwalter);

    this->OperatingMode = cocktailPro.OperatingMode;

}

CocktailPro& CocktailPro::operator=(CocktailPro rhs) {
   swap(*this, rhs);
   return *this;
}

void swap(CocktailPro &lhs, CocktailPro &rhs) {

    std::swap(lhs.availableIngredients, rhs.availableIngredients);
    std::swap(lhs.mixableRecipeBook, rhs.mixableRecipeBook);
    std::swap(lhs.theDeviceVerwalter, rhs.theDeviceVerwalter);
    std::swap(lhs.barTender, rhs.barTender);
    std::swap(lhs.OperatingMode, rhs.OperatingMode);

}


void CocktailPro::demo() {

  int CocktailNo = 1;
  int max = mixableRecipeBook->getNumberOfRecipes();
  if (CocktailNo <= max) {
    Recipe *rezeptptr = mixableRecipeBook->getRecipe(CocktailNo - 1);
    std::cout << rezeptptr->getName() << std::endl;
      barTender->prepareCocktail(rezeptptr);
  } else {
    std::cout << "Falsche Cocktailnummer!" << std::endl;
  }
}


int CocktailPro::selectCocktail() {

    std::string eingabe;

    std::cout << "********** Mischbare Rezepte **********" << std::endl;
    mixableRecipeBook->browse();
    std::cout << "Was haetten Sie denn gern? (-1 zum Verlassen)" << std::endl;
    std::cin >> eingabe;

    // int zahl = atoi(eingabe.c_str()); // alternative 1: converts a string to int.
    int zahl = (int) strtol(eingabe.c_str(), nullptr, 0); // alternative 2: converts a string to int.

    if(zahl == -1)
        return zahl;

    int max = mixableRecipeBook->getNumberOfRecipes();
    if (zahl > 0 && zahl <= max)
      return zahl;
    else {
      std::cout << "MEEEP! Too many fingers on keyboard error!" << std::endl;
      std::cout << "Ihre Eingabe: " << eingabe << " war nicht zwischen 1 und " << max << "!"
                << std::endl;
    }

}