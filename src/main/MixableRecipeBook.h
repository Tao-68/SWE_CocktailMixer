//@(#) MixableRecipeBook.h

#ifndef MISCHBARESREZEPTBUCH_H_H
#define MISCHBARESREZEPTBUCH_H_H

#include "Recipe.h"
#include "RecipeBook.h"
#include "AvailableIngredients.h"

#include <iostream>
#include <fstream>
#include <string>

/**
 *  Kennt die mischbaren Rezepte.
 *  Kann diese Ausgeben.
 *  
 */
class MixableRecipeBook : public RecipeBook {
public:
    /* Überprüft in allen Rezepten, ob die gebrauchten Zutaten existieren/vorhanden sind.
     * Wenn nicht, wird das Rezept gelöscht.
     */
    MixableRecipeBook(AvailableIngredients * ze);

    //Ausgabe aller vorhandenen Cocktails
    void browse();

private:
    AvailableIngredients * myZutatenVerwalter;

    std::vector<Recipe *> rezepte;

    // Setzt den Pointer "availableIngredients" auf den Parameter
    void setZutatenVerwalter(AvailableIngredients * ze);

};

#endif
