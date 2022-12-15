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

        // char placeholder[] to let mode[] at param[1]
        char mode[] = "-USERSTORY1";
        char placeholder[] = "";
        char *param[2] = { placeholder,mode};
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
    cp->validateSelectedNumber(id);
    Recipe* recipe = cp->mixableRecipeBook->getRecipeWithID(id);
    EXPECT_TRUE(recipe->isHidden());
}

TEST_F(UserStory1, checkTimer){
    cp->start();
    EXPECT_EQ(1000, cp->deviceManager->drainer->myTimer->booster);
}