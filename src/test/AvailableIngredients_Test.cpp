#include <string>
#include "gtest/gtest.h"
#include <sstream>

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#define protected public
#define private public

#include "AvailableIngredients.h"

#undef protected
#undef private

class AvailableIngredientsTest : public ::testing::Test {
protected:
    AvailableIngredients *availableIngredientsPtr = nullptr;
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;

    void SetUp() override {
        // Check whether cout works normal - otherwise you will get very strange errors
        // if someone else made a mistake when redirecting cout
        std::cout << "Start of " << "AvailableIngredientsTest" << std::endl << std::flush;

        // redirect cout to my test_cout stream for testing
        // and store orig cout for restoring after test (!!!do not forget to restore!!!)
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());

        availableIngredientsPtr = new AvailableIngredients();
    }

    void TearDown() override {
        // Code here will be called immediately after each test
        // (right before the destructor).
        std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
        delete availableIngredientsPtr;
        // Check whether cout works normal again - otherwise the next one using cout
        // will get very strange behavior
        std::cout << "End of " << "AvailableIngredientsTest" << std::endl << std::flush;
    }
};

TEST_F(AvailableIngredientsTest, copyConstructorIsValid) {

    AvailableIngredients copiedObject(*availableIngredientsPtr);

    // have different pointer address
    EXPECT_NE(availableIngredientsPtr, &copiedObject);
    EXPECT_NE(availableIngredientsPtr->ingredients, copiedObject.ingredients);
    // have same number of dispenser.
    EXPECT_EQ(availableIngredientsPtr->numberOfDispenser, copiedObject.numberOfDispenser);
    
    // have same ingredients
    for (int i = 0; i < availableIngredientsPtr->ingredients->size(); i++)
        EXPECT_EQ(availableIngredientsPtr->getIngredient(i), copiedObject.getIngredient(i));

}

TEST_F(AvailableIngredientsTest, assignmentOperatorIsValid) {

    AvailableIngredients copiedObject;
    copiedObject.operator=(*availableIngredientsPtr);

    // have different pointer address
    EXPECT_NE(availableIngredientsPtr, &copiedObject);
    EXPECT_NE(availableIngredientsPtr->ingredients, copiedObject.ingredients);
    // have same number of dispenser.
    EXPECT_EQ(availableIngredientsPtr->numberOfDispenser, copiedObject.numberOfDispenser);

    // have same ingredients
    for (int i = 0; i < availableIngredientsPtr->ingredients->size(); i++)
        EXPECT_EQ(availableIngredientsPtr->getIngredient(i), copiedObject.getIngredient(i));

}

TEST_F(AvailableIngredientsTest, ingredientIsValid) {
    EXPECT_EQ("Limettenstuecke", availableIngredientsPtr->getIngredient(0));
}

TEST_F(AvailableIngredientsTest, numberOfAvailableIngredientsIsValid) {
    EXPECT_EQ(16, availableIngredientsPtr->getNumberAvailableIngredients());
}

TEST_F(AvailableIngredientsTest, ingredientsFileIsValid) {
    // SetUp() redirects the standard cout to another stream (test_cout)
    // this stream can be read and compared
    // in TearDown() the normal cout is restored again

    test_cout.clear();
    availableIngredientsPtr->readIngredientsFile("ingredients.txt");
    EXPECT_EQ("Open the ingredients file", test_cout.str().substr(0, 25));
}

/*
TEST_F(AvailableIngredientsTest, browseIngredientsIsValid) {
    test_cout.clear();

    availableIngredientsPtr->browse();
    // How can I test it?
    // Solution: change browse() method signature and return number of printed lines
}
*/


TEST_F(AvailableIngredientsTest, ingredientsFileIsNotAvailable) {
    // Test asserts that an exception is thrown and that the type of the exception is the one expected
    //https://stackoverflow.com/questions/23270078/test-a-specific-exception-type-is-thrown-and-the-exception-has-the-right-propert
    EXPECT_THROW({
                     try {
                         availableIngredientsPtr->readIngredientsFile("xxxx.txt");
                     }
                     catch (std::string &e) {
                         std::cout << e << std::endl;
                         EXPECT_EQ("File not found", e.substr(0, 14));
                         throw;
                     }
                 }, std::string
    );
}
