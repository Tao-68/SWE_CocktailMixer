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
      if (CocktailNo >= 0 && CocktailNo <= max) {
        Recipe *rezeptptr = theMischbaresRezeptbuch->getRecipe(CocktailNo - 1);
        std::cout << rezeptptr->getName() << std::endl;
        theCocktailZubereiter->cocktailZubereiten(rezeptptr);
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

void CocktailPro::demo() {
  int CocktailNo = 1;
  int max = theMischbaresRezeptbuch->getNumberOfRecipes();
  if (CocktailNo >= 0 && CocktailNo <= max) {
    Recipe *rezeptptr = theMischbaresRezeptbuch->getRecipe(CocktailNo - 1);
    std::cout << rezeptptr->getName() << std::endl;
    theCocktailZubereiter->cocktailZubereiten(rezeptptr);
  } else {
    std::cout << "Falsche Cocktailnummer!" << std::endl;
  }
}


int CocktailPro::waehle() {
  while (true) {
    std::cout << "********** Mischbare Rezepte **********" << std::endl;
    theMischbaresRezeptbuch->browse();
    std::cout << "Was haetten Sie denn gern? (-1 zum Verlassen)" << std::endl;

    std::string eingabe = "";

    std::cin >> eingabe;

    int zahl = atoi(eingabe.c_str()); // converts a string to int
    int max = theMischbaresRezeptbuch->getNumberOfRecipes();

    if ((zahl >= 0 && zahl <= max) || (zahl == -1)) {
      return zahl;
    } else {
      std::cout << "MEEEP! Too many fingers on keyboard error!" << std::endl;
      std::cout << "Ihre Eingabe: " << eingabe << " war nicht zwischen 1 und " << max << "!"
                << std::endl;
    }
  }
}
