//@(#) DeviceVerwalter.h

#ifndef DEVICEVERWALTER_H_H
#define DEVICEVERWALTER_H_H

#include <string>
#include <map>

#include "InternalDevice.h"
#include "AvailableIngredients.h"
#include "Dispenser.h"
#include "Mixer.h"
#include "Masher.h"
#include "Shaker.h"
#include "Drainer.h"
#include "Waage.h"

/*
 * Befuellt die Dispenser, verwaltet die Interne Hardware
 *  
 */
class DeviceVerwalter {
public:
    DeviceVerwalter(AvailableIngredients * ze);

    void rezeptSchrittZubereiten(std::string zutat, float menge);

  Drainer * myEntleerer;
  std::map<std::string, InternalDevice *> * myDevices;
 private:
    void setZutatenVerwalter(AvailableIngredients * ze);

  Mixer * myMixer;

    Masher * myStampfer;

    Shaker * mySchuettler;

    AvailableIngredients * myZutatenVerwalter;

    Waage * theWaage;

    void createDevices();

};

#endif
