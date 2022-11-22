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

    // Stream anlegen
    std::ifstream in;

    std::string FileName = "Rezepte.csv";
    // Datei oeffnen
    in.open(FileName.c_str(), std::ios::in);

    if (!in) {// File konnte nicht geoeffnet werden
        Recipe *r1 = new Recipe();

        createCaipirinha(r1);

        createMargarita(r1);

        createDaiquri(r1);

        createPlantersPunch(r1);

        createCaipiroska(r1);

        createCaipirissima(r1);

        createCubanIsland(r1);

        createMartiniJamesB(r1);
    } else {
        /* Daten lesen und ausgeben */
        std::string zeile;

        // 1. Zeile ist Ueberschrift - Einlesen und wegwerfen!
        getline(in, zeile);
        // cout << zeile << endl;

        while (getline(in, zeile)) {
            // cout << zeile << endl;
            std::istringstream inputString(zeile);
            std::string name;
            std::string zutat;
            std::string tempstring;
            float menge;

            Recipe *r1 = new Recipe;

            // Aus istringstream Name einlesen mit Komma als Trennzeichen
            getline(inputString, name, ';');
            // Weiter einlesen bis zum naechsten Trennzeichen (Zutat)
            r1->setName(name);
            //cout << "Name: " << Name << endl;

            while (getline(inputString, zutat, ';') && !zutat.empty()) {
                // Weiter einlesen bis zum naechsten Trennzeichen (Menge)
                if (getline(inputString, tempstring, ';')) {
                    std::istringstream(tempstring) >> menge;
                }
                r1->appendStep(zutat, menge);
                //cout << " Zutat: " << Zutat << " Menge: " << Menge << "\n" << endl;
            }
            this->recipes.push_back(r1);
        }

        /* Datei wieder schliessen */
        in.close();
    }
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

void RecipeBook::createDaiquri(Recipe *r1) {
    r1 = new Recipe;
    r1->setName("Daiquiri");
    r1->appendStep("Limettensaft", 2);
    r1->appendStep("Zuckersirup", 2);
    r1->appendStep("Rum weiss", 5);
    r1->appendStep("Eis", 50);
    r1->appendStep("Mischen", 20);
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

RecipeBook::~RecipeBook() {
    recipes.clear();
}

int RecipeBook::getNumberOfRecipes() {
    return recipes.size();
}

Recipe *RecipeBook::getRecipe(unsigned int recipeIndex) {
    if (recipeIndex >= recipes.size()) {
        return NULL;
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