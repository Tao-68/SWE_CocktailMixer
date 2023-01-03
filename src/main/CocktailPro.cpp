#include "CocktailPro.h"
#include <string>

void CocktailPro::start() {
    bool a = OperatingMode == OpMode::NORMAL && !debug;
    bool b = OperatingMode == OpMode::USERSTORY1 && getLastInputForDebug() != 2;
    bool c = OperatingMode == OpMode::US2 && executeStart != 0;
    bool d = OperatingMode == OpMode::USERSTORY3;


    while (a || b || c || d) {

        selectCocktail();
        if (executeStart != 0)
            executeStart = executeStart - 1;

        a = OperatingMode == OpMode::NORMAL && !debug;
        b = OperatingMode == OpMode::USERSTORY1 && getLastInputForDebug() != 2;
        c = OperatingMode == OpMode::US2 && executeStart != 0;
        d = OperatingMode == OpMode::USERSTORY3;
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
        initializeOperatingMode(param, theTimer);
        setUpUserStories(param, theTimer);
    }
}

void CocktailPro::initializeOperatingMode(char *const *param, Timer *theTimer) {
    if (std::string(param[1]) == "-D") {
        OperatingMode = DEMO;
        theTimer->set_Turbo(1000); // increase preparing time.
        demo();
    } else if (std::string(param[0]) == "-US2")
        OperatingMode = US2;
    else if (std::string(param[1]) == "-USERSTORY1")
        OperatingMode = USERSTORY1;
    else if (std::string(param[1]) == "-USERSTORY3")
        OperatingMode = USERSTORY3;
    else
        theTimer->set_Turbo(10);
}

void CocktailPro::setUpUserStories(char *const *param, Timer *theTimer) {
    if (std::string(param[0]) == "-US2" ||
        std::string(param[1]) == "-USERSTORY1" ||
        std::string(param[1]) == "-USERSTORY3") {
        theTimer->set_Turbo(1000);
        debug = true;
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
        validateSelectedNumberUserStory1(cocktailNumberInput);
    } else if (cocktailNumberInput == -2) {
        barTender->undrinkableCocktailDetected();
        isPrepareCocktailFailed = false;
        OperatingMode = OpMode::STOP;
    } else {
        validateSelectedNumberIsTrue(cocktailNumberInput);
    }

}

void CocktailPro::validateSelectedNumberIsTrue(int cocktailNumberInput) {
    Recipe *rezeptptr = mixableRecipeBook->getRecipeWithID(cocktailNumberInput);
    if (rezeptptr == nullptr) {
        notValidInputMsg(cocktailNumberInput);
    } else {
        bool isPrepareCocktailSucceeded = barTender->prepareCocktail(rezeptptr);
        if (!isPrepareCocktailSucceeded && (OperatingMode != OpMode::US2)) {
            std::cout << "\nDer naechste Cocktail ist ungeniessbar, bitte wegschuetteln!" << std::endl;
            std::cout << "Druecken Sie -2 fuer Bestaetigung, dass Sie diese Warnung gelesen haben." << std::endl;
            isPrepareCocktailFailed = true;
            selectCocktail();
        }
        if (OperatingMode == OpMode::USERSTORY1) {
            setLastInputForDebug(cocktailNumberInput);
        }
    }
}

void CocktailPro::validateSelectedNumberUserStory1(int cocktailNumberInput) {
    Recipe *rezeptptr = mixableRecipeBook->getRecipeWithID(this->getLastInputForDebug());
    if (rezeptptr == nullptr) {
        notValidInputMsg(cocktailNumberInput);
        return;
    }
    rezeptptr->setHidden(true);
}

void CocktailPro::notValidInputMsg(int cocktailNumberInput) {
    std::cout << "Falsche Cocktailnummer! Ihre Eingabe: " << cocktailNumberInput << " ist nicht mischbar!" << std::endl;
}

void CocktailPro::selectCocktail() {
    printMsgWithMixedRecipe();

    std::string input;
    input = setInputForUserStory3(input);
    input = isDebugNotEnabled(input);
    input = setInputForUserStory2(input);

    bool isUserStory1Enabled = (OperatingMode == OpMode::USERSTORY1 && debug);
    if (isUserStory1Enabled) {
        if (getLastInputForDebug() == 1) {
            setLastInputForDebug(2);
            return;
        }
        input = "1";
        setLastInputForDebug(1);
        std::cout << "1" << std::endl;
    }

    int inputNumber = (int) strtol(input.c_str(), nullptr, 0);
    validateSelectedNumber(inputNumber);
}

std::string &CocktailPro::isDebugNotEnabled(std::string &input) const {
    if (!debug)
        std::cin >> input;
    return input;
}

std::string &CocktailPro::setInputForUserStory2(std::string &input) const {
    if (OperatingMode == US2 && debug) {
        input = "1";
        std::cout << "1" << std::endl;
    }
    return input;
}

void CocktailPro::printMsgWithMixedRecipe() {
    if (!isPrepareCocktailFailed) {
        std::cout << "************* Mischbare Rezepte *************" << std::endl;
        mixableRecipeBook->getAllCocktails();
        std::cout << "Was haetten Sie denn gern? (-1 zum Verlassen)" << std::endl;

    }
}

std::string &CocktailPro::setInputForUserStory3(std::string &input) const {
    if (OperatingMode == USERSTORY3) {
        if (isPrepareCocktailFailed) {
            input = "-2";
            std::cout << "-2" << std::endl;
        } else {
            input = testInput;
            std::cout << testInput << std::endl;
        }
    }
    return input;
}

int CocktailPro::getLastInputForDebug() const {
    return lastInputForDebug;
}

void CocktailPro::setLastInputForDebug(int inputForDebug) {
    CocktailPro::lastInputForDebug = inputForDebug;
}