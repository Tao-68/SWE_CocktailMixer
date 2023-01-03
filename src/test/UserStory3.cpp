#include "gtest/gtest.h"
#define protected public
#define private public
#include "CocktailPro.h"
#undef protected
#undef private
#include <sstream>

class UserStory3 : public ::testing::Test {
protected:
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;
    CocktailPro *cp;

    void SetUp() override {
        std::cout << "\n\nStart of " << "UserStory3\n" << std::endl << std::flush;
      //  orig_cout = std::cout.rdbuf(test_cout.rdbuf());

        // char placeholder[] to let mode[] at param[1]
        char mode[] = "-USERSTORY3";
        char placeholder[] = "";
        char *param[2] = { placeholder,mode};
        cp = new CocktailPro(2, param);

    }

    void TearDown() override {
    //    std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
        delete cp;
        std::cout << "\n\nEnd of " << "UserStory3\n" << std::endl << std::flush;
    }
};

// For presentation 13. January (1/2)
/*
TEST_F(UserStory3, userStory3Demo1) {
    Dispenser* dispenserCachaca = dynamic_cast<Dispenser*>(cp->deviceManager->devices->at("Cachaca"));
    dispenserCachaca->setCapacity(4);
    cp->testInput = "1";
    cp->start();

};
*/

/*
// For presentation 13. January (2/2)
TEST_F(UserStory3, userStory3Demo2) {
    Dispenser* dispenserCachaca = dynamic_cast<Dispenser*>(cp->deviceManager->devices->at("Eis"));
    dispenserCachaca->setCapacity(20);
    cp->testInput = "7";
    cp->start();
};
*/

