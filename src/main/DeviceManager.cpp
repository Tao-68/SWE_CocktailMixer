#include "DeviceManager.h"

DeviceManager::DeviceManager(AvailableIngredients *zv) {
    setZutatenVerwalter(zv);
    this->createDevices();
}

void DeviceManager::createDevices() {
    theWaage = new Waage();
    myDevices = new std::map<std::string, InternalDevice *>;

    myEntleerer = new Drainer(25, 1000, theWaage);
    myDevices->insert(std::make_pair("Entleeren", myEntleerer));

    myStampfer = new Masher();
    myDevices->insert(std::make_pair("Stampfen", myStampfer));

    mySchuettler = new Shaker();
    myDevices->insert(std::make_pair("Schuetteln", mySchuettler));

    myMixer = new Mixer();
    myDevices->insert(std::make_pair("Mischen", myMixer));

    std::string myZutat;
    for (int i = myZutatenVerwalter->getNumberAvailableIngredients() - 1; i >= 0; i--) {
        myZutat = myZutatenVerwalter->getIngredient(i);
        if (myZutat == "Eis")
            myDevices->insert(std::make_pair(myZutat, new Dispenser(20, 1000, myZutat, theWaage)));
        else if (myZutat == "Limettenstuecke")
            myDevices->insert(std::make_pair(myZutat, new Dispenser(10, 1000, myZutat, theWaage)));
        else
            myDevices->insert(std::make_pair(myZutat, new Dispenser(1, 250, myZutat, theWaage)));
    }
}

void DeviceManager::setZutatenVerwalter(AvailableIngredients *zv) {
    myZutatenVerwalter = zv;
}

void DeviceManager::rezeptSchrittZubereiten(std::string zutat, float menge) {

    if (zutat == "Limettenstuecke") {
        // Der Kunde will Limetten ja unbedingt nach Stueck und nicht nach Gewicht abmessen...
        int stckProZeit = dynamic_cast<Dispenser *>(myDevices->at(zutat))->getStueckProZeit();
        myDevices->at(zutat)->doIt(menge * stckProZeit);
    } else {
        myDevices->at(zutat)->doIt(menge);
    }
}

