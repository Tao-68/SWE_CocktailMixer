#include "gtest/gtest.h"
#define protected public
#define private public
#include "CocktailPro.h"
#undef protected
#undef private
#include <sstream>

class UserStory1 : public ::testing::Test {
protected:
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;
    CocktailPro *cp;

    void SetUp() override {
        std::cout << "Start of " << "UserStory1" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());

        // When it is a real test, then "real_test[]" set to "true"
        // When not real test, then set to the default "false"
        char mode[] = "-USERSTORY1";
        char real_test[] = "false";
        char *param[2] = { mode , real_test};
        cp = new CocktailPro(2, param);

    }

    void TearDown() override {
        std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
        delete cp;
        std::cout << "End of " << "UserStory1" << std::endl << std::flush;
    }
};

TEST_F(UserStory1, validateSelectedNumber){
    unsigned int id = 1;
    cp->setLastInputForDebug(id);
    cp->OperatingMode = cp->USERSTORY1;
    cp->debug = true;
    cp->validateSelectedNumber(id);
    Recipe* recipe = cp->mixableRecipeBook->getRecipeWithID(id);
    EXPECT_TRUE(recipe->isHidden());
}

TEST_F(UserStory1, checkTimer){
    cp->OperatingMode = cp->USERSTORY1;
    cp->debug = true;
    cp->start();
    EXPECT_EQ(1000, cp->barTender->myDeviceVerwalter->drainer->myTimer->booster);
}