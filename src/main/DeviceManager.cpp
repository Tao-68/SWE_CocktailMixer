#include "DeviceManager.h"

DeviceManager::DeviceManager(AvailableIngredients *zv) {
    setIngredientsManager(zv);
    this->createDevices();
}

void DeviceManager::createDevices() {
    scale = new Waage(0, 0);
    devices = new std::map<std::string, InternalDevice *>;

    drainer = new Drainer(25, 1000, scale);
    devices->insert(std::make_pair("Entleeren", drainer));

    masher = new Masher();
    devices->insert(std::make_pair("Stampfen", masher));

    shaker = new Shaker();
    devices->insert(std::make_pair("Schuetteln", shaker));

    mixer = new Mixer();
    devices->insert(std::make_pair("Mischen", mixer));

    std::string myZutat;
    for (int i = availableIngredients->getNumberAvailableIngredients() - 1; i >= 0; i--) {
        myZutat = availableIngredients->getIngredient(i);
        if (myZutat == "Eis")
            devices->insert(std::make_pair(
                    myZutat,
                    new Dispenser(
                            20,
                            1000,
                            myZutat,
                            scale,
                            "g")
            ));
        else if (myZutat == "Limettenstuecke")
            devices->insert(std::make_pair(
                    myZutat, new Dispenser(
                            10,
                            1000,
                            myZutat,
                            scale,
                            "g")
            ));
        else if (myZutat == "Zucker")
            devices->insert(std::make_pair(
                    myZutat, new Dispenser(
                            1,
                            250,
                            myZutat,
                            scale,
                            "g")
            ));
        else
            devices->insert(std::make_pair(
                    myZutat, new Dispenser(
                            1,
                            250,
                            myZutat,
                            scale,
                            "ml")
            ));
    }
}

void DeviceManager::setIngredientsManager(AvailableIngredients *ze) {
    availableIngredients = ze;
}

bool DeviceManager::prepareRecipeSteps(std::string ingredient, float amount) {

    bool isStepSucceeded;

    if (ingredient == "Limettenstuecke") {
        // Der Kunde will Limetten ja unbedingt nach Stueck und nicht nach Gewicht abmessen...
        int stckProZeit = dynamic_cast<Dispenser *>(devices->at(ingredient))->getPiecePerTime();
        isStepSucceeded = devices->at(ingredient)->doIt(amount * stckProZeit);
    } else
        isStepSucceeded = devices->at(ingredient)->doIt(amount);

    if (isStepSucceeded) {
        auto usedDevice = devices->find(ingredient);
        usedDevices.push_back(usedDevice);
    }

    return isStepSucceeded;
}

