#include "CocktailPro.h"
#include <string>

void CocktailPro::start() {

    while (OperatingMode == OpMode::NORMAL)
        selectCocktail();
}

CocktailPro::CocktailPro(int argc, char **param) {
    availableIngredients = new AvailableIngredients;

    mixableRecipeBook = new MixableRecipeBook(availableIngredients);
    theDeviceVerwalter = new DeviceManager(availableIngredients);
    barTender = new BarTender(theDeviceVerwalter);

    Timer *theTimer = Timer::getInstance();
    if (argc == 2) {
        if (std::string(param[1]) == "-D") {
            this->OperatingMode = OpMode::DEMO;
            theTimer->set_Turbo(1000); // increase preparing time ?
            this->demo();
        } else {
            theTimer->set_Turbo(10);
        }
    }
}

CocktailPro::~CocktailPro() {
    delete availableIngredients;
    delete mixableRecipeBook;
    delete theDeviceVerwalter;
    delete barTender;
}

CocktailPro::CocktailPro(const CocktailPro &cocktailPro) {

    availableIngredients = new AvailableIngredients;

    mixableRecipeBook = new MixableRecipeBook(availableIngredients);
    theDeviceVerwalter = new DeviceManager(availableIngredients);
    barTender = new BarTender(theDeviceVerwalter);

    this->OperatingMode = cocktailPro.OperatingMode;

}

CocktailPro &CocktailPro::operator=(CocktailPro rhs) {
    swap(*this, rhs);
    return *this;
}

void swap(CocktailPro &lhs, CocktailPro &rhs) {

    std::swap(lhs.availableIngredients, rhs.availableIngredients);
    std::swap(lhs.mixableRecipeBook, rhs.mixableRecipeBook);
    std::swap(lhs.theDeviceVerwalter, rhs.theDeviceVerwalter);
    std::swap(lhs.barTender, rhs.barTender);
    std::swap(lhs.OperatingMode, rhs.OperatingMode);

}


void CocktailPro::demo() {

    int CocktailNo = 1;
    int max = mixableRecipeBook->getNumberOfRecipes();
    if (CocktailNo <= max) {
        Recipe *rezeptptr = mixableRecipeBook->getRecipe(CocktailNo - 1);
        std::cout << rezeptptr->getName() << std::endl;
        barTender->prepareCocktail(rezeptptr);
    } else {
        std::cout << "Falsche Cocktailnummer!" << std::endl;
    }
}

void CocktailPro::validateSelectedNumber(int cocktailNumberInput) {

    if(cocktailNumberInput == -1)
        OperatingMode = OpMode::STOP;
    else if (isNotValidNumber(cocktailNumberInput))
        notValidInputMsg(cocktailNumberInput);
    else {
        Recipe *rezeptptr = mixableRecipeBook->getRecipe(cocktailNumberInput - 1);
        std::cout << rezeptptr->getName() << std::endl;
        barTender->prepareCocktail(rezeptptr);
    }
}

void CocktailPro::notValidInputMsg(int cocktailNumberInput) {
    std::cout << "Falsche Cocktailnummer!" << std::endl;
    std::cout << "Ihre Eingabe: " << cocktailNumberInput << " war nicht zwischen 1 und " << mixableRecipeBook->getNumberOfRecipes()
              << "!" << std::endl;
}

bool CocktailPro::isNotValidNumber(int cocktailNumberInput) const {
    return  cocktailNumberInput < -1 ||
            cocktailNumberInput > mixableRecipeBook->getNumberOfRecipes() ||
            cocktailNumberInput == 0;
}

void CocktailPro::selectCocktail() {

    std::string input;

    std::cout << "********** Mischbare Rezepte **********" << std::endl;
    mixableRecipeBook->getAllCocktails();
    std::cout << "Was haetten Sie denn gern? (-1 zum Verlassen)" << std::endl;
    std::cin >> input;

    // int zahl = atoi(eingabe.c_str()); // alternative 1: converts a string to int.
    int inputNumber = (int) strtol(input.c_str(), nullptr, 0); // alternative 2: converts a string to int.

    validateSelectedNumber(inputNumber);
}