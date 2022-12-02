/**********************************************************************************/
/*                                 Definitionsmodul                               */
/**********************************************************************************/
/*
 * File       : RecipeBook.cpp
 *
 */

#include <algorithm>

#include "RecipeBook.h"

RecipeBook::RecipeBook() {
    recipes.clear();
    Recipe *r1 = new Recipe();

    createCaipirinha(r1);

    createMargarita(r1);

    createDaiquiri(r1);

    createPlantersPunch(r1);

    createCaipiroska(r1);

    createCaipirissima(r1);

    createCubanIsland(r1);

    createMartiniJamesB(r1);

}

void RecipeBook::createCaipirinha(Recipe *r1) {
    r1 = new Recipe;
    r1->setName("Caipirinha");
    r1->appendStep("Limettenstuecke", 8);
    r1->appendStep("Zucker", 15);
    r1->appendStep("Stampfen", 20);
    r1->appendStep("Eis", 90);
    r1->appendStep("Cachaca", 5);
    r1->appendStep("Mischen", 10);
    recipes.push_back(r1);
}

void RecipeBook::createMargarita(Recipe *r1) {
    r1 = new Recipe;
    r1->setName("Margarita");
    r1->appendStep("Zitronensaft", 2);
    r1->appendStep("Cointreau", 2);
    r1->appendStep("Tequilla", 4);
    r1->appendStep("Eis", 50);
    r1->appendStep("Mischen", 20);
    recipes.push_back(r1);
}

void RecipeBook::createDaiquiri(Recipe *r1) {
    r1 = new Recipe;
    r1->setName("Daiquiri");
    r1->appendStep("Limettensaft", 2);
    r1->appendStep("Zuckersirup", 2);
    r1->appendStep("Rum weiss", 5);
    r1->appendStep("Eis", 50);
    r1->appendStep("Mischen", 20);
    recipes.push_back(r1);
}
void RecipeBook::createPlantersPunch(Recipe *r1) {
    r1 = new Recipe;
    r1->setName("Planters Punch");
    r1->appendStep("Zitronensaft", 2);
    r1->appendStep("Grenadine", 1);
    r1->appendStep("Orangensaft", 8);
    r1->appendStep("Rum braun", 6);
    r1->appendStep("Eis", 100);
    r1->appendStep("Mischen", 20);
    recipes.push_back(r1);
}

void RecipeBook::createCaipiroska(Recipe *r1) {
    r1 = new Recipe;
    r1->setName("Caipiroska");
    r1->appendStep("Limettenstuecke", 8);
    r1->appendStep("Zucker", 15);
    r1->appendStep("Stampfen", 20);
    r1->appendStep("Eis", 90);
    r1->appendStep("Wodka", 5);
    r1->appendStep("Mischen", 10);
    recipes.push_back(r1);
}

void RecipeBook::createCaipirissima(Recipe *r1) {
    r1 = new Recipe;
    r1->setName("Caipirissima");
    r1->appendStep("Limettenstuecke", 8);
    r1->appendStep("Zucker", 15);
    r1->appendStep("Stampfen", 20);
    r1->appendStep("Eis", 90);
    r1->appendStep("Rum weiss", 5);
    r1->appendStep("Mischen", 10);
    recipes.push_back(r1);
}

void RecipeBook::createCubanIsland(Recipe *r1) {
    r1 = new Recipe;
    r1->setName("Cuban Island");
    r1->appendStep("Zitronensaft", 2);
    r1->appendStep("Cointreau", 2);
    r1->appendStep("Rum weiss", 2);
    r1->appendStep("Wodka", 2);
    r1->appendStep("Eis", 30);
    r1->appendStep("Mischen", 30);
    recipes.push_back(r1);
}

void RecipeBook::createMartiniJamesB(Recipe *r1) {
    r1 = new Recipe;
    r1->setName("Martini James B");
    r1->appendStep("Gin", 6);
    r1->appendStep("Wodka", 2);
    r1->appendStep("Noilly Prat", 1);
    r1->appendStep("Schuetteln", 10);
    recipes.push_back(r1);
}


RecipeBook::~RecipeBook() {
    recipes.clear();
}

int RecipeBook::getNumberOfRecipes() {
    return recipes.size();
}

Recipe *RecipeBook::getRecipe(unsigned int recipeIndex) {
    if (recipeIndex >= recipes.size()) {
        return nullptr;
    } else {
        std::list<Recipe *>::iterator recipe; // Iterator
        advance(recipe = recipes.begin(), recipeIndex); // p zeigt jetzt auf das i-te Element
        return *recipe; // Wert von p - also den Pointer zurueck
    }
}

bool RecipeBook::deleteRecipe(unsigned int recipeIndex) {
    if (recipeIndex >= recipes.size()) {
        return false;
    } else {
        std::list<Recipe *>::iterator recipe; // Iterator
        advance(recipe = recipes.begin(), recipeIndex); // now p points to the i-th Element
        recipes.erase(recipe); // delete the element p is pointing to
        return true; // Success!
    }
}