#include <limits.h>
#include <string>
#include "gtest/gtest.h"

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#define protected public
#define private public
#include "AvailableIngredients.h"
#undef protected
#undef private

#include <sstream>

class AvailableIngredientsTest: public ::testing::Test
{
protected:
    AvailableIngredients* zv;
    std::basic_streambuf<char>* orig_cout;
    std::stringstream test_cout;

    void SetUp() override
    {
        // Check whether cout works normal - otherwise you will get very strange errors
        // if someone else made a mistake when redirecting cout
        std::cout << "Start of " << "AvailableIngredientsTest" << std::endl << std::flush;

      // redirect cout to my test_cout stream for testing
      // and store orig cout for restoring after test (!!!do not forget to restore!!!)
      orig_cout = std::cout.rdbuf(test_cout.rdbuf());

      zv = new AvailableIngredients();
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
        delete zv;
        // Check whether cout works normal again - otherwise the next one using cout
        // will get very strange behavior
         std::cout << "End of " << "AvailableIngredientsTest" << std::endl << std::flush;
    }
};

TEST_F(AvailableIngredientsTest, getNumberAvailableIngredients)
{
    EXPECT_EQ(15, zv->getNumberAvailableIngredients());
}

TEST_F(AvailableIngredientsTest, FileZutatenDotTxtIsAvailable)
{
    // SetUp() redirects the standard cout to another stream (test_cout)
    // this stream can be read and compared
    // in TearDown() the normal cout is restored again

    test_cout.clear();
    zv->readIngredientsFile("ingredients.txt");
    EXPECT_EQ("Oeffne Zutatendatei", test_cout.str().substr(0, 19));
    //std::string s = test_cout.str();
    //std::cout << "!!!" << s.substr(0,31) << "!!!" << std::endl;
}

TEST_F(AvailableIngredientsTest, FileZutatenDotTxtIsNotAvailable)
{
    // Test asserts that an exception is thrown and that the type of the exception is the one expected
    //https://stackoverflow.com/questions/23270078/test-a-specific-exception-type-is-thrown-and-the-exception-has-the-right-propert
    EXPECT_THROW(
    {
        try
        {
            zv->readIngredientsFile("xxxx.txt");
        }
        catch( std::string e)
        {
            std::cout << e << std::endl;
            EXPECT_EQ("File not found", e.substr(0,14));
            throw;
        }
    }, std::string );
}
