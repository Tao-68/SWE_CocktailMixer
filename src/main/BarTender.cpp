#include "BarTender.h"

BarTender::BarTender(DeviceManager *dv) {
    myDeviceVerwalter = dv;
}


bool BarTender::prepareCocktail(Recipe *recipe) {

    std::cout << "Hallo, ich bin der BarTender!" << std::endl
              << "Ich habe Ihre Bestellung: " << recipe->getName() << " erhalten." << std::endl
              << "Jetzt geht es los!" << std::endl;
    int i = 0;

    for (i = 0; i < recipe->getNoOfRecipeSteps(); i++) {
        RecipeStep *schritt = recipe->getRecipeStep(i);
        std::string zutat = schritt->getZutat();
        float menge = schritt->getMenge();

        std::string ingredientType = getIngridientType(zutat);

        std::cout << "\nRezeptschritt: " << zutat << ", " << menge << ingredientType << std::endl;

        bool isStepSucceeded = myDeviceVerwalter->prepareRecipeSteps(zutat, menge);
        if (!isStepSucceeded) {
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
    for (auto &cleanDevice: myDeviceVerwalter->usedDevices) {
        std::string deviceName = getRightNameOfDevices(cleanDevice->first);
        std::cout << deviceName << cleanDevice->first << " wird geputzt" << std::endl;
        cleanDevice->second->putzen();
        std::cout << deviceName << cleanDevice->first << " ist geputzt worden.\n" << std::endl;
    }
    myDeviceVerwalter->usedDevices.clear();
}

std::string BarTender::getIngridientType(const std::string& s)  {
    std::string ingredientType;
    if (s == "Limettenstuecke" || s == "Eis" || s == "Zucker")
        ingredientType = "g";
    else
        ingredientType = "ml";

    return ingredientType;
}

std::string BarTender::getRightNameOfDevices(const std::string& s) {
    if (isDevice(s))
        return "Device ";
    else
        return "Dosierer ";
}

bool BarTender::isDevice(const std::string &s) const {
    return s == "Entleeren" ||
            s == "Stampfen" ||
            s == "Schuetteln" ||
            s == "Mischen";
}

