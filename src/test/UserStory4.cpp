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

/* TODO reimplement user story 4 */