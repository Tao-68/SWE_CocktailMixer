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
    MixableRecipeBook(AvailableIngredients * ze);
    void browse();

private:
    AvailableIngredients * myZutatenVerwalter;

    std::vector<Recipe *> rezepte;

  void setZutatenVerwalter(AvailableIngredients * ze);

};

#endif
