#include "BarTender.h"

BarTender::BarTender(DeviceManager * dv) {
    myDeviceVerwalter = dv;
}


bool BarTender::prepareCocktail(Recipe * recipe) {

    if (!checkAvailabilityIngredients(recipe)){
        std::cout << "Sorry! Lack of ingredients! Please choose another drink!\n" << std::endl;
        return false;
    }

    std::cout << "Hallo, ich bin der BarTender!" << std::endl
            << "Ich habe Ihre Bestellung: " << recipe->getName() << " erhalten." << std::endl
            << "Jetzt geht es los!\n" << std::endl;
	int i=0;

    for (i = 0; i < recipe->getNoOfRecipeSteps(); i++) {
        RecipeStep * schritt = recipe->getRecipeStep(i);
        std::string zutat = schritt->getZutat();
        float menge = schritt->getMenge();
        std::cout << "Rezeptschritt: " << zutat << ", " << menge << std::endl;
        myDeviceVerwalter->prepareRecipeSteps(zutat, menge);
    }

  myDeviceVerwalter->drainer->doIt(i); // give out a cocktail

  // device manager cleaning
  for (auto & myDevice : *myDeviceVerwalter->devices) {
    std::cout << "Device mit der Aktion: " << myDevice.first << " wird jetzt geputzt: " << std::endl;
    myDevice.second->putzen();
  }
  return (true);
}

bool BarTender::checkAvailabilityIngredients(Recipe* recipe) {
    for (int i = 0; i < recipe->getNoOfRecipeSteps(); i++) {

        RecipeStep * schritt = recipe->getRecipeStep(i);
        std::basic_string<char> zutat = schritt->getZutat();

        if (myDeviceVerwalter->devices->count(zutat) == 0)
            return false;
    }
    return true;
}

