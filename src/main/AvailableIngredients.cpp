#include "AvailableIngredients.h"

AvailableIngredients::AvailableIngredients() {
    ingredients = new std::vector<std::string>;

    readIngredientsFile("ingredients.txt");

    browse();

    ingredients->push_back("Mischen");
    ingredients->push_back("Stampfen");
    ingredients->push_back("Schuetteln");

    numberOfDispenser = ingredients->size();

}

AvailableIngredients::AvailableIngredients(const AvailableIngredients &availableIngredients) {

    ingredients = new std::vector<std::string>();
    for (std::string z : *availableIngredients.ingredients)
        ingredients->push_back(z);

    numberOfDispenser = availableIngredients.numberOfDispenser;

}

AvailableIngredients& AvailableIngredients::operator=(const AvailableIngredients &eqopAvailableIngredients) {

    if (&eqopAvailableIngredients != this) {
        ingredients = new std::vector<std::string>();
        for (std::string z : *eqopAvailableIngredients.ingredients)
            ingredients->push_back(z);

        numberOfDispenser = eqopAvailableIngredients.numberOfDispenser;
    }

    return *this;
}

AvailableIngredients::~AvailableIngredients() {
    delete ingredients;
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

    std::cout << "Open the ingredients file" << fileName << std::endl;

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

void AvailableIngredients::browse() {
    std::cout << "*********** Verfuegbare Zutaten: *************" << std::endl;
    for (auto & ingredient : *ingredients)
        std::cout << ingredient << std::endl;
    std::cout << "*********************************************" << std::endl;
}

std::string AvailableIngredients::getIngredient(int position) {
    return ingredients->at(position);
}

int AvailableIngredients::getNumberAvailableIngredients() {
    return ingredients->size();
}
