#include "CocktailPro.h"
#include <string>

void CocktailPro::start() {

  while (OperatingMode == OpMode::NORMAL) {
    int CocktailNo = waehle();
    if (CocktailNo == -1) {
      OperatingMode = OpMode::STOP;
    }
    else {
      int max = theMischbaresRezeptbuch->getNumberOfRecipes();
      if (CocktailNo <= max) {
        Recipe *rezeptptr = theMischbaresRezeptbuch->getRecipe(CocktailNo - 1);
        std::cout << rezeptptr->getName() << std::endl;
          theCocktailZubereiter->prepareCocktail(rezeptptr);
      } else {
        std::cout << "Falsche Cocktailnummer!" << std::endl;
      }
    }
  }
}

CocktailPro::CocktailPro(int argc, char **param) {
  theZutatenVerwalter = new AvailableIngredients;

  theMischbaresRezeptbuch = new MixableRecipeBook(theZutatenVerwalter);
  theDeviceVerwalter = new DeviceVerwalter(theZutatenVerwalter);
  theCocktailZubereiter = new BarTender(theDeviceVerwalter);

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
    delete theZutatenVerwalter;
    delete theMischbaresRezeptbuch;
    delete theDeviceVerwalter;
    delete theCocktailZubereiter;
}

CocktailPro::CocktailPro(const CocktailPro &cocktailPro) {

    theZutatenVerwalter = new AvailableIngredients;

    theMischbaresRezeptbuch = new MixableRecipeBook(theZutatenVerwalter);
    theDeviceVerwalter = new DeviceVerwalter(theZutatenVerwalter);
    theCocktailZubereiter = new BarTender(theDeviceVerwalter);

    this->OperatingMode = cocktailPro.OperatingMode;

}

CocktailPro& CocktailPro::operator=(CocktailPro rhs) {
   swap(*this, rhs);
   return *this;
}

void swap(CocktailPro &lhs, CocktailPro &rhs) {

    std::swap(lhs.theZutatenVerwalter, rhs.theZutatenVerwalter);
    std::swap(lhs.theMischbaresRezeptbuch, rhs.theMischbaresRezeptbuch);
    std::swap(lhs.theDeviceVerwalter, rhs.theDeviceVerwalter);
    std::swap(lhs.theCocktailZubereiter, rhs.theCocktailZubereiter);
    std::swap(lhs.OperatingMode, rhs.OperatingMode);

}


void CocktailPro::demo() {
  int CocktailNo = 1;
  int max = theMischbaresRezeptbuch->getNumberOfRecipes();
  if (CocktailNo <= max) {
    Recipe *rezeptptr = theMischbaresRezeptbuch->getRecipe(CocktailNo - 1);
    std::cout << rezeptptr->getName() << std::endl;
      theCocktailZubereiter->prepareCocktail(rezeptptr);
  } else {
    std::cout << "Falsche Cocktailnummer!" << std::endl;
  }
}


int CocktailPro::waehle() {

    std::string eingabe;

    std::cout << "********** Mischbare Rezepte **********" << std::endl;
    theMischbaresRezeptbuch->browse();
    std::cout << "Was haetten Sie denn gern? (-1 zum Verlassen)" << std::endl;
    std::cin >> eingabe;

    // int zahl = atoi(eingabe.c_str()); // alternative 1: converts a string to int.
    int zahl = (int) strtol(eingabe.c_str(), nullptr, 0); // alternative 2: converts a string to int.

    if(zahl == -1)
        return zahl;

    int max = theMischbaresRezeptbuch->getNumberOfRecipes();
    if (zahl > 0 && zahl <= max)
      return zahl;
    else {
      std::cout << "MEEEP! Too many fingers on keyboard error!" << std::endl;
      std::cout << "Ihre Eingabe: " << eingabe << " war nicht zwischen 1 und " << max << "!"
                << std::endl;
    }

}