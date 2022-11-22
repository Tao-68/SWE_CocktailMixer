#include "BarTender.h"

BarTender::BarTender(DeviceVerwalter * dv) {
    myDeviceVerwalter = dv;
}

bool BarTender::cocktailZubereiten(Recipe * rzpt) {
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
  for (std::map<std::string, InternalDevice *>::iterator i1 = myDeviceVerwalter->benutzteDevices->begin();
       i1 != myDeviceVerwalter->benutzteDevices->end(); ++i1) {
    std::cout << "Device mit der Aktion: " << i1->first << " wird jetzt geputzt: " << std::endl;
    i1->second->putzen();
  }
  myDeviceVerwalter->benutzteDevices->clear();
  return (true);
}

