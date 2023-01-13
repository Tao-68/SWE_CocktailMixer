#include "gtest/gtest.h"
#define protected public
#define private public
#include "CocktailPro.h"
#undef protected
#undef private
#include <sstream>

class UserStory4 : public ::testing::Test {
protected:
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;
    CocktailPro *cp;
    AvailableIngredients availableIngredients;

    void SetUp() override {
        std::cout << "\n\nStart of " << "UserStory4\n" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());

        // char placeholder[] to let mode[] at param[1]
        char mode[] = "-USERSTORY4";
        char placeholder[] = "";
        char *param[2] = { placeholder,mode};
        cp = new CocktailPro(2, param);

    }

    void TearDown() override {
        std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
        delete cp;
        std::cout << "\n\nEnd of " << "UserStory4\n" << std::endl << std::flush;
    }
};

//unsure how to test this

/*
TEST_F(UserStory4, UserStoryDemo1){
    std::vector<std::string> ingredients {"Zitronensaft", "Cointreau", "Tequilla", "Tequilla", "Eis", "Mischen"};
    Dispenser* dispenserTequila = dynamic_cast<Dispenser*>(cp->deviceManager->devices->at("Tequila"));
    dispenserTequila->capacity = 3;

    test_cout.clear();
    cp->testInput = "2";
    cp->start();



    EXPECT_EQ(expected_text, test_cout.str().substr(1587, 2100));
}
*/