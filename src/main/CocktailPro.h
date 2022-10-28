//@(#) CocktailPro.h

#ifndef COCKTAILPRO_H_H
#define COCKTAILPRO_H_H

#include "DeviceVerwalter.h"
#include "AvailableIngredients.h"
#include "MixableRecipeBook.h"
#include "BarTender.h"

/**
 * Gesamtsystem
 *@class CocktailPro
 *
 *@brief CocktailPro diese Klasse leitet die Einfuehrung in das Programm
 *
 * CocktailPro startet den Prozess
 * und in dem wird die Rezeptnummer ausgewaehlt.
 */
class CocktailPro {
 protected:
  /**
  * Objekt von BarTender
  */
  BarTender * theCocktailZubereiter;
  /**
  * Objekt von DeviceVerwalter
  */
  DeviceVerwalter * theDeviceVerwalter;
  /**
  * Objekt von MixableRecipeBook
  */
  MixableRecipeBook * theMischbaresRezeptbuch;
  /**
  *Objekt von AvailableIngredients
  */
  AvailableIngredients * theZutatenVerwalter;

  enum OpMode {NORMAL, DEMO, STOP};
  OpMode OperatingMode = NORMAL;

 protected:
  /**
  *@brief waehle() dient zum Rezeptnummerauswhl
  *@return die ausgewaehlte Rezeptnummer oder -1 zum Beenden
  *
  *und gibt die erste Einleitung aus.
  */
  int waehle();
  /**
  *@brief demo() macht das gleiche wie Methode start()
  *@see start()
  *
  * aber die ausgewaelte Rezeptnummer ist festgestellt bzw. ist(0).
  *d.h. es wird den Rezeptnamen gezeigt und das Cocktail wird vorbereitet.
  *
  */
  void demo();

 public:
  /**
  *@brief Konstruktor erzeugt objekte von CocktailPro
  *@return ein Zeiger auf das erzeugten Objekt
  *@param argc ist die Anzahl der Befehlszeilenoptionen
  *@param turbo Die einzelnen Befehlszeilenoptionen befinden sich im diesem Array.
  *
  *da werden die im protected Variabeln mit dynamischen Objekte intialisiert.
  *
  */
  CocktailPro(int argc, char * * turbo);
  /**
  *@brief diese Methode startet den Prozess
  *
  *Diese Methode fragt den Benutzer nach einer Rezeptnummer
  *,die er auswaehlen soll um den Prozess weiterzufuehren
  *und kontroliert die ausgewaehlte Nummer, ob es sinnvoll ausgewaehlt oder nicht
  * das Cocktail wir auch durch eine aufgerufte Methode vorbereitet.
  *
  */
  void start();


};

#endif
