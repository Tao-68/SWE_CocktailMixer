#include "DeviceManager.h"

DeviceManager::DeviceManager(AvailableIngredients *zv) {
    setIngredientsManager(zv);
    this->createDevices();
}

void DeviceManager::createDevices() {
    initializeDevices();

    for (int i = availableIngredients->getNumberAvailableIngredients() - 1; i >= 0; i--)
        initializeDispenser(availableIngredients->getIngredient(i));
}

void DeviceManager::initializeDispenser(std::string myZutat) {
    if (myZutat == "Eis")
        addDevice(myZutat, 20, 1000, "g");
    else if (myZutat == "Limettenstuecke")
        addDevice(myZutat, 10, 1000, "g");
    else if (myZutat == "Zucker")
        addDevice(myZutat, 1, 250, "g");
    else
        addDevice(myZutat, 1, 250, "ml");
}

void DeviceManager::addDevice(std::string &myZutat, float gram, int timeUnit, const std::string &type) {
    devices->insert(std::make_pair(
            myZutat,
            new Dispenser(gram,
                          timeUnit,
                          myZutat,
                          scale,
                          type)
    ));
}

void DeviceManager::initializeDevices() {
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

