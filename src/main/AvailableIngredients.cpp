#include "AvailableIngredients.h"

AvailableIngredients::AvailableIngredients(void) {
    ingredients = new std::vector<std::string>;

    if (DEBUG)
        insertDummyData();
    else
        readIngredientsFile("ingredients.txt");

    browse();

    ingredients->push_back("Mischen");
    ingredients->push_back("Stampfen");
    ingredients->push_back("Schuetteln");

    numberOfDispenser = ingredients->size();

}

AvailableIngredients::~AvailableIngredients(void) {

}

void AvailableIngredients::readIngredientsFile(std::string fileName) {
    std::ifstream in;

    // ios::in describes the file open for reading
    // c_str returns a pointer to an array that contains a null-terminated sequence of characters
    in.open(fileName.c_str(), std::ios::in);

    if (!in) {
        std::string my_exception = "File not found: " + fileName;
        std::cout << my_exception << std::endl;
        throw my_exception;
    }

    std::cout << "Oeffne Zutatendatei " << fileName << std::endl;

    std::string zeile;
    while (getline(in, zeile)) {

        // Cut trailing \r - to make Linux or Windows Files equal
        if (zeile.size() && zeile[zeile.size() - 1] == '\r') {
            zeile = zeile.substr(0, zeile.size() - 1);
        }

        this->ingredients->push_back(zeile);
    }
    in.close();
}

void AvailableIngredients::insertDummyData() {
    ingredients->push_back("Limettenstuecke");
    ingredients->push_back("Zucker");
    ingredients->push_back("Cointreau");
    ingredients->push_back("Eis");
    ingredients->push_back("Wodka");
    ingredients->push_back("Rum weiss");
    ingredients->push_back("Zitronensaft");
    ingredients->push_back("Grenadine");
    //    ingredients->push_back("Limettensaft");
    //    ingredients->push_back("Tequilla");
    //    ingredients->push_back("Gin");
    //    ingredients->push_back("Noilly Prat");
}

void AvailableIngredients::browse(void) {
    std::cout << "*********** Verfuegbare Einheiten bzw. Zutaten: ***********" << std::endl;
    for (unsigned int i = 0; i < ingredients->size(); i++) {
        std::cout << ingredients->at(i) << std::endl;
    }
    std::cout << "**********************************************************" << std::endl;
}

std::string AvailableIngredients::getIngredient(int position) {
    return ingredients->at(position);
}

int AvailableIngredients::getNumberAvailableIngredients() {
    return ingredients->size();
}
