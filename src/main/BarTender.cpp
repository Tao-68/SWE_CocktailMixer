#include "BarTender.h"

BarTender::BarTender(DeviceVerwalter * dv) {
    myDeviceVerwalter = dv;
}

bool BarTender::prepareCocktail(Recipe * recipe) {
    std::cout << "Hallo, ich bin der BarTender!" << std::endl
            << "Ich habe Ihre Bestellung: " << recipe->getName() << " erhalten." << std::endl
            << "Jetzt geht es los!\n" << std::endl;
	int i=0;

    for (i = 0; i < recipe->getNoOfRecipeSteps(); i++) {
        RecipeStep * schritt = recipe->getRecipeStep(i);
        std::string zutat = schritt->getZutat();
        float menge = schritt->getMenge();
        std::cout << "Rezeptschritt: " << zutat << ", " << menge << std::endl;
        myDeviceVerwalter->rezeptSchrittZubereiten(zutat, menge);
    }

  myDeviceVerwalter->myEntleerer->doIt(i); // give out a cocktail

  // device manager cleaning
  for (auto & myDevice : *myDeviceVerwalter->myDevices) {
    std::cout << "Device mit der Aktion: " << myDevice.first << " wird jetzt geputzt: " << std::endl;
    myDevice.second->putzen();
  }
  return (true);
}

