#include <string>
#include "gtest/gtest.h"
#include <sstream>

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#define protected public
#define private public

#include "CocktailPro.h"

#undef protected
#undef private

class CocktailProTest : public ::testing::Test {
protected:
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;
    CocktailPro* cocktailPro = new CocktailPro(0, 0);
    AvailableIngredients* availableIngredients = new AvailableIngredients();
    DeviceManager * deviceManager = new DeviceManager(availableIngredients);
    BarTender* bartender = new BarTender(deviceManager);
    MixableRecipeBook* mixableRecipeBook = new MixableRecipeBook(availableIngredients);

    void SetUp() override {
        std::cout << "Start of " << "CocktailProTest" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    }

    void TearDown() override {

        std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
        delete cocktailPro;
        delete availableIngredients;
        delete mixableRecipeBook;
        std::cout << "End of " << "CocktailProTest" << std::endl << std::flush;
    }
};

TEST_F(CocktailProTest, checkDemo){
    cocktailPro->theDeviceVerwalter->drainer->myTimer->booster = 1000;
    cocktailPro->demo();
    Recipe *rezeptptr = mixableRecipeBook->getRecipe( 0);
    EXPECT_TRUE(bartender->prepareCocktail(rezeptptr));
}

TEST_F(CocktailProTest, validateSelectedNumber){
    int cocktailNumber = -1;
    cocktailPro->validateSelectedNumber(cocktailNumber);
    EXPECT_EQ(cocktailPro->STOP, cocktailPro->OperatingMode);


    cocktailPro->OperatingMode = cocktailPro->NORMAL;
    cocktailNumber = 1;
    cocktailPro->theDeviceVerwalter->drainer->myTimer->booster = 1000;
    cocktailPro->validateSelectedNumber(cocktailNumber);
    Recipe *rezeptptr = mixableRecipeBook->getRecipe(cocktailNumber - 1);
    EXPECT_TRUE(bartender->prepareCocktail(rezeptptr));
}

TEST_F(CocktailProTest, notValidInputMessage){
    test_cout.clear();
    int cocktailNumberInput = 100;
    std::string output = "Falsche Cocktailnummer! Ihre Eingabe: 100 war nicht zwischen 1 und 6!";
    cocktailPro->notValidInputMsg(cocktailNumberInput);
    EXPECT_EQ(output, test_cout.str().substr(0, 69));
}

TEST_F(CocktailProTest, isNotValidNumber){
    int cocktailNumberInput = -2;
    EXPECT_TRUE(cocktailPro->isNotValidNumber(cocktailNumberInput));

    cocktailNumberInput = 100;
    EXPECT_TRUE(cocktailPro->isNotValidNumber(cocktailNumberInput));

    cocktailNumberInput = 0;
    EXPECT_TRUE(cocktailPro->isNotValidNumber(cocktailNumberInput));
}

TEST_F(CocktailProTest, selectCocktail){

    std::string input = "1";
    int inputNumber = (int)strtol(input.c_str(), nullptr, 0);
    EXPECT_EQ(1, inputNumber);
}
