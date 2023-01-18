#include "CocktailPro.h"
#include <string>

void CocktailPro::start() {
    while (isCondTrueForStartMethod()) {
        selectCocktail();
        if (executeStart != 0)
            executeStart = executeStart - 1;
    }
}

bool CocktailPro::isCondTrueForStartMethod() const {
    return isOpNormalAndDebugIsFalse() ||
           isOpUS1AndInpForDebNotEq2() ||
           isOpUS2AndExecStartNotEq0() ||
           isOpModeUS5();
}

bool CocktailPro::isOpModeUS5() const { return OperatingMode == USERSTORY5; }

bool CocktailPro::isOpUS2AndExecStartNotEq0() const { return OperatingMode == US2 && executeStart != 0; }

bool CocktailPro::isOpUS1AndInpForDebNotEq2() const {
    return OperatingMode == USERSTORY1 &&
    getLastInputForDebug() != 2;
}

bool CocktailPro::isOpNormalAndDebugIsFalse() const { return OperatingMode == NORMAL && !debug; }

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

// Move getAllCocktails from MixableRecipeBook into CocktailPro
// because we have access to AvailableIngredients,  MixableRecipeBook and DeviceManager in it.
void CocktailPro::getAllCocktails() {
    std::cout << "*********************************************" << std::endl;
    std::cout << "Es gibt " << mixableRecipeBook->getNumberOfRecipes() << " Cocktails" << std::endl;

    // Check if we have a cocktail where we do not have enough of capacity for specific ingredient.
    for (int i = 0; i < mixableRecipeBook->getNumberOfRecipes(); i++) {
        Recipe* r = mixableRecipeBook->getRecipe(i);
        if(r->isHidden())
            continue;

        for (int j = 0; j< r->getNoOfRecipeSteps(); j++) {
            std::string ingredient = r->getRecipeStep(j)->getZutat();
            float amountOfIngredient = r->getRecipeStep(j)->getMenge();
            if(typeid(*deviceManager->devices->at(ingredient)) == typeid(Dispenser)) {
                auto* dispenser = dynamic_cast<Dispenser *>(deviceManager->devices->at(ingredient));
                auto dispenserCapacity = static_cast<float>(dispenser->getCapacity());
                if(dispenserCapacity < amountOfIngredient)
                    notMixableCocktail.insert(std::make_pair(r->getRecipeID(), true));
            }
        }

        if(notMixableCocktail.find(r->getRecipeID()) == notMixableCocktail.end())
            notMixableCocktail.insert(std::make_pair(r->getRecipeID(), false));
    }

    for (int i = 0; i < mixableRecipeBook->getNumberOfRecipes(); i++) {
        Recipe* r = mixableRecipeBook->getRecipe(i);
        if(r->isHidden())
            continue;

        // Die Nummer eines nicht mischbaren Cocktails wird nicht mehr angezeigt.
        if(!notMixableCocktail.at(r->getRecipeID())) // if notMixableCocktail is false
            std::cout << r->getRecipeID() << ". ";

        r->getAllIngredients();

        // Die Makierung wird durch eine Info an den Cocktail geschrieben
        //z.B.: "Caipirinha [...]. (*Nicht mischbar!*)
        if(notMixableCocktail.at(r->getRecipeID())) // if notMixableCocktail is true
            std::cout << " (*Nicht mischbar!*)";

        std::cout << std::endl;
    }


    std::cout << "\n*********************************************" << std::endl;
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
    else if (std::string(param[1]) == "-USERSTORY5")
        OperatingMode = USERSTORY5;
    else
        theTimer->set_Turbo(10);
}

void CocktailPro::setUpUserStories(char *const *param, Timer *theTimer) {
    if (std::string(param[0]) == "-US2" ||
        std::string(param[1]) == "-USERSTORY1" ||
        std::string(param[1]) == "-USERSTORY5") {
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
    } else if(notMixableCocktail.find(cocktailNumberInput) != notMixableCocktail.end() &&
            notMixableCocktail.at(cocktailNumberInput)) {
        std::cout << "Dieser Cocktail ist nicht mischbar, wähle einen anderen." << std::endl;
        selectCocktail();
    } else {
        validateSelectedNumberIsTrue(cocktailNumberInput);
    }

}

void CocktailPro::validateSelectedNumberIsTrue(int cocktailNumberInput) {
    Recipe *rezeptptr = mixableRecipeBook->getRecipeWithID(cocktailNumberInput);
    if (rezeptptr == nullptr) {
        notValidInputMsg(cocktailNumberInput);
    } else {
        barTender->prepareCocktail(rezeptptr);

        if (OperatingMode == OpMode::USERSTORY1)
            setLastInputForDebug(cocktailNumberInput);
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
    // input = setInputForUserStory5(input);
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

    if (OperatingMode == USERSTORY5) {
      if(inputForUserStory5 == 3) {
          input = "8";
          inputForUserStory5--;

      } else if(inputForUserStory5 == 2) {
          input = "6";
          inputForUserStory5--;
      } else if(inputForUserStory5 == 1)  {
          input = "1";
          inputForUserStory5--;
      } else {
          input = "-1";
      }
        std::cout << input << std::endl;
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
        std::cout << "************* Mischbare Rezepte *************" << std::endl;
        this->getAllCocktails();
        std::cout << "Was haetten Sie denn gern? (-1 zum Verlassen)" << std::endl;
}

std::string &CocktailPro::setInputForUserStory5(std::string &input) const {
    if (OperatingMode == USERSTORY5) {
            input = testInput;
            std::cout << testInput << std::endl;
    }
    return input;
}

int CocktailPro::getLastInputForDebug() const {
    return lastInputForDebug;
}

void CocktailPro::setLastInputForDebug(int inputForDebug) {
    CocktailPro::lastInputForDebug = inputForDebug;
}