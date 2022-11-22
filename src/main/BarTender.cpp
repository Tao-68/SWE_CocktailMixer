#include "BarTender.h"

BarTender::BarTender(DeviceVerwalter * dv) {
    myDeviceVerwalter = dv;
}

bool BarTender::cocktailZubereiten(Recipe * rzpt) {

    if (!checkAvailabilityIngredients(rzpt)){
        std::cout << "Sorry! Lack of ingredients! Please choose another drink!\n" << std::endl;
        return false;
    }
    std::cout << "Hallo, ich bin der BarTender!" << std::endl
            << "Ich habe Ihre Bestellung: " << rzpt->getName() << " erhalten." << std::endl
            << "Jetzt geht es los!\n" << std::endl;
	int i=0;

    for (i = 0; i < rzpt->getNoOfRecipeSteps(); i++) {
        RecipeStep * schritt = rzpt->getRecipeStep(i);
        std::string zutat = schritt->getZutat();
        float menge = schritt->getMenge();
        std::cout << "Rezeptschritt: " << zutat << ", " << menge << std::endl;
        myDeviceVerwalter->rezeptSchrittZubereiten(zutat, menge);
    }

  myDeviceVerwalter->myEntleerer->doIt(i); // give out a cocktail

  // device manager cleaning
  for (std::map<std::string, InternalDevice *>::iterator i1 = myDeviceVerwalter->myDevices->begin();
       i1 != myDeviceVerwalter->myDevices->end(); ++i1) {
    std::cout << "Device mit der Aktion: " << i1->first << " wird jetzt geputzt: " << std::endl;
    i1->second->putzen();
  }
  return (true);
}

bool BarTender::checkAvailabilityIngredients(Recipe* recipe) {
    for (int i = 0; i < recipe->getNoOfRecipeSteps(); i++) {

        RecipeStep * schritt = recipe->getRecipeStep(i);
        std::basic_string<char> zutat = schritt->getZutat();

        if (myDeviceVerwalter->myDevices->count(zutat) == 0){
            return false;
        }
    }
    return true;
}

