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
    Dispenser* dispenser = new Dispenser(gram,
                                         timeUnit,
                                         myZutat,
                                         scale,
                                         type);
    dispenser->setDeviceName(myZutat);
    deviceList.push_back(dispenser);

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
    drainer->setDeviceName("Entleeren");
    deviceList.push_back(drainer);
    devices->insert(std::make_pair("Entleeren", drainer));

    masher = new Masher();
    masher->setDeviceName("Stampfen");
    deviceList.push_back(masher);
    devices->insert(std::make_pair("Stampfen", masher));

    shaker = new Shaker();
    shaker->setDeviceName("Schuetteln");
    deviceList.push_back(shaker);
    devices->insert(std::make_pair("Schuetteln", shaker));

    mixer = new Mixer();
    mixer->setDeviceName("Mischen");
    deviceList.push_back(mixer);
    devices->insert(std::make_pair("Mischen", mixer));
}

void DeviceManager::setIngredientsManager(AvailableIngredients *ze) {
    availableIngredients = ze;
}

bool DeviceManager::prepareRecipeSteps(std::string ingredient, float amount) {

    bool isStepSucceeded;
    InternalDevice* internalDevice;
    for (InternalDevice * iDevice : deviceList)  {
        std::string deviceName = iDevice->getDeviceName();

        if(deviceName == ingredient){
            internalDevice = iDevice;
            Dispenser* dispenser = dynamic_cast<Dispenser *>(iDevice);
            if (dispenser == NULL){
                break;
            }
            if(dispenser->getCapacity() < amount){
                continue;
            }
            break;
        }
    }

    if (ingredient == "Limettenstuecke") {
        // Der Kunde will Limetten ja unbedingt nach Stueck und nicht nach Gewicht abmessen...
        int stckProZeit = dynamic_cast<Dispenser *>(internalDevice)->getPiecePerTime();
        isStepSucceeded = internalDevice->doIt(amount * stckProZeit);
    } else
        isStepSucceeded = internalDevice->doIt(amount);

    if (isStepSucceeded) {
        auto usedDevice = devices->find(ingredient);
        usedDevices.push_back(usedDevice);
    }

    return isStepSucceeded;
}

