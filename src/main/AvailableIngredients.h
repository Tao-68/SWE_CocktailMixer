//@(#) AvailableIngredients.h

#ifndef VorhandeneZutaten_H_H
#define VorhandeneZutaten_H_H

#include <string>
#include <map>
#include <vector>
#include <list>
#include <fstream>

#include <iostream>

/**
 *  Liest Zutaten aus Liste ein.
 *  Merkt sich in der Liste die Zutaten + Aggregatszustand.
 *
 */
class AvailableIngredients {
 public:
    AvailableIngredients(void);
    virtual ~AvailableIngredients();

    void browse(void);

    std::string getZutat(int);

    int getAnzahlVorhandeneZutaten();

 private:
    std::vector<std::string> * zutaten;

    static const bool DEBUG = false;

  void DummyZutatenEinfuegen();

    virtual void ZutatenDateiEinlesen(std::string);


  int anzahlDosierer;

};
static std::string FileName;
#endif
