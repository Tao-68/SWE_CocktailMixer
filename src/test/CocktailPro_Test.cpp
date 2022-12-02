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

    void SetUp() override {
        
        std::cout << "Start of " << "CocktailProTest" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    }

    void TearDown() override {

        std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
        std::cout << "End of " << "CocktailProTest" << std::endl << std::flush;
    }
};