#include "CocktailPro.h"
#include <string>

void CocktailPro::start() {

    while (OperatingMode == OpMode::NORMAL && !debug)
        selectCocktail();

    while (OperatingMode == OpMode::US2 && executeStart != 0) {
        selectCocktail();
        executeStart = executeStart - 1;
    }

    while (OperatingMode == OpMode::USERSTORY1) {
        selectCocktail();
    }
}

CocktailPro::CocktailPro(int argc, char **param) {
    availableIngredients = new AvailableIngredients;
    mixableRecipeBook = new MixableRecipeBook(availableIngredients);
    deviceManager = new DeviceManager(availableIngredients);
    barTender = new BarTender(deviceManager);
    lastInputForDebug = 0;
    Timer *theTimer = Timer::getInstance();
    if (argc == 2) {
        if (std::string(param[1]) == "-D") {
            this->OperatingMode = OpMode::DEMO;
            theTimer->set_Turbo(1000); // increase preparing time.
            this->demo();
        } else if (std::string(param[0]) == "-US2") {
            OperatingMode = US2;
            theTimer->set_Turbo(1000); // increase preparing time.
            debug = true;
        } else if (std::string(param[1]) == "-USERSTORY1") {
            OperatingMode = USERSTORY1;
            theTimer->set_Turbo(1000); // increase preparing time.
            debug = true;
        } else {
            theTimer->set_Turbo(10);
        }
    }
}

CocktailPro::~CocktailPro() {
    delete availableIngredients;
    delete mixableRecipeBook;
    delete deviceManager;
    delete barTender;
}

CocktailPro::CocktailPro(const CocktailPro &cocktailPro) {

    availableIngredients = new AvailableIngredients;
    mixableRecipeBook = new MixableRecipeBook(availableIngredients);
    deviceManager = new DeviceManager(availableIngredients);
    barTender = new BarTender(deviceManager);
    lastInputForDebug = 0;
    this->OperatingMode = cocktailPro.OperatingMode;

}

CocktailPro &CocktailPro::operator=(CocktailPro rhs) {
    swap(*this, rhs);
    return *this;
}

void swap(CocktailPro &lhs, CocktailPro &rhs) {

    std::swap(lhs.availableIngredients, rhs.availableIngredients);
    std::swap(lhs.mixableRecipeBook, rhs.mixableRecipeBook);
    std::swap(lhs.deviceManager, rhs.deviceManager);
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

    if (cocktailNumberInput == -1)
        OperatingMode = OpMode::STOP;
    else if (OperatingMode == OpMode::USERSTORY1 && debug) {
        Recipe *rezeptptr = mixableRecipeBook->getRecipeWithID(this->getLastInputForDebug());
        if (rezeptptr == nullptr) {
            notValidInputMsg(cocktailNumberInput);
            return;
        } else {
            rezeptptr->setHidden(true);
        }
    } else {
        Recipe *rezeptptr = mixableRecipeBook->getRecipeWithID(cocktailNumberInput);
        if (rezeptptr == nullptr) {
            notValidInputMsg(cocktailNumberInput);
        } else {
            std::cout << rezeptptr->getName() << std::endl;
            barTender->prepareCocktail(rezeptptr);
            if (OperatingMode == OpMode::USERSTORY1){
                setLastInputForDebug(cocktailNumberInput);
            }
        }
    }
}


void CocktailPro::notValidInputMsg(int cocktailNumberInput) {
    std::cout << "Falsche Cocktailnummer! Ihre Eingabe: " << cocktailNumberInput << " ist nicht mischbar!" << std::endl;
}

void CocktailPro::selectCocktail() {

    std::string input;

    std::cout << "************* Mischbare Rezepte *************" << std::endl;
    mixableRecipeBook->getAllCocktails();
    std::cout << "Was haetten Sie denn gern? (-1 zum Verlassen)" << std::endl;

    if (!debug)
        std::cin >> input;

    if (OperatingMode == OpMode::US2 && debug) {
        input = "1";
    } else if (OperatingMode == OpMode::USERSTORY1 && debug){
        if (getLastInputForDebug() == 1){
            std::cin >> input;
            return;
        }
        input = "1";
        setLastInputForDebug(1);
        std::cout << "1" << std::endl;
    }

    // int zahl = atoi(eingabe.c_str()); // alternative 1: converts a string to int.
    int inputNumber = (int) strtol(input.c_str(), nullptr, 0); // alternative 2: converts a string to int.

    validateSelectedNumber(inputNumber);
}

int CocktailPro::getLastInputForDebug() const {
    return lastInputForDebug;
}

void CocktailPro::setLastInputForDebug(int inputForDebug) {
    CocktailPro::lastInputForDebug = inputForDebug;
}
