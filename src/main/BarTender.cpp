#include "BarTender.h"

BarTender::BarTender(DeviceManager * dv) {
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

        bool isStepSucceeded = myDeviceVerwalter->prepareRecipeSteps(zutat, menge);
        if(!isStepSucceeded) {
            numberOfStepsDone = i;
            return false;
        }
    }

    auto drainValue = static_cast<float>(i);
    myDeviceVerwalter->drainer->doIt(drainValue); // give out a cocktail
    cleaningDevices();
    return true;
}

void BarTender::undrinkableCocktailDetected() {
    myDeviceVerwalter->drainer->setIsUndrinkableCocktail(true);
    auto drainValue = static_cast<float>(numberOfStepsDone);
    myDeviceVerwalter->drainer->doIt(drainValue);
    cleaningDevices();
}


void BarTender::cleaningDevices() {
    // device manager cleaning
    for (auto & cleanDevice : myDeviceVerwalter->usedDevices) {
        std::cout << "Device mit der Aktion: " << cleanDevice->first << " wird jetzt geputzt: " << std::endl;
        cleanDevice->second->putzen();
    }
    myDeviceVerwalter->usedDevices.clear();
}

