#include "DeviceVerwalter.h"

DeviceVerwalter::DeviceVerwalter(AvailableIngredients *zv) {
    setZutatenVerwalter(zv);
    this->createDevices();
    benutzteDevices = nullptr;

}

void DeviceVerwalter::createDevices() {
    theWaage = new Waage(0,0);
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
    for (int i = myZutatenVerwalter->getAnzahlVorhandeneZutaten() - 1; i >= 0; i--) {
        myZutat = myZutatenVerwalter->getZutat(i);
        if (myZutat == "Eis")
            myDevices->insert(std::make_pair(myZutat, new Dispenser(20, 1000, myZutat, theWaage)));
        else if (myZutat == "Limettenstuecke")
            myDevices->insert(std::make_pair(myZutat, new Dispenser(10, 1000, myZutat, theWaage)));
        else
            myDevices->insert(std::make_pair(myZutat, new Dispenser(1, 250, myZutat, theWaage)));
    }
}

void DeviceVerwalter::setZutatenVerwalter(AvailableIngredients *zv) {
    myZutatenVerwalter = zv;
}

void DeviceVerwalter::rezeptSchrittZubereiten(std::string zutat, float menge) {

    if (zutat == "Limettenstuecke") {
        // Der Kunde will Limetten ja unbedingt nach Stueck und nicht nach Gewicht abmessen...
        int stckProZeit = dynamic_cast<Dispenser *>(myDevices->at(zutat))->getStueckProZeit();
        myDevices->at(zutat)->doIt(menge * stckProZeit);
        std::map<std::string, InternalDevice *>::iterator usedDevice = myDevices->find(zutat);
        benutzteDevices->insert(std::make_pair(usedDevice->first, usedDevice->second));
    } else {
        myDevices->at(zutat)->doIt(menge);
        std::map<std::string, InternalDevice *>::iterator usedDevice = myDevices->find(zutat);
        benutzteDevices->insert(std::make_pair(usedDevice->first, usedDevice->second));
    }
}

