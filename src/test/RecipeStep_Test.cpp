#include "gtest/gtest.h"
#define protected public
#define private public
#include "RecipeStep.h"
#undef protected
#undef private
#include <sstream>

class RecipeStepTest: public ::testing::Test {
protected:
    RecipeStep* recipeStep;
    std::basic_streambuf<char>* orig_cout;
    std::stringstream test_cout;

    virtual void SetUp() {
        std::cout << "Start of " << "RecipeStepTest" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());
        recipeStep = new RecipeStep();
    }

    virtual void TearDown() {
        std::cout.rdbuf(orig_cout);
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete recipeStep;
        std::cout << "End of " << "RecipeStepTest" << std::endl << std::flush;

    }
};

TEST_F(RecipeStepTest, checkGetZutat) {
    recipeStep->zutat = "Eis";
    EXPECT_FALSE("Wodka" == recipeStep->getZutat());
    EXPECT_FALSE("" == recipeStep->getZutat());

    EXPECT_TRUE("Eis" == recipeStep->getZutat());
}

TEST_F(RecipeStepTest, checkGetMenge) {
    recipeStep->menge = 10;
    EXPECT_FALSE(0 == recipeStep->getMenge());
    EXPECT_FALSE(-1 == recipeStep->getMenge());

    EXPECT_TRUE(10 == recipeStep->getMenge());
}

TEST_F(RecipeStepTest, checkSetZutat) {
    recipeStep->setZutat("Zucker");
    std::string zutatTemp = recipeStep->getZutat();
    EXPECT_TRUE("Zucker" == zutatTemp);

    EXPECT_FALSE("Wodka" == zutatTemp);
    EXPECT_FALSE("" == zutatTemp);
}

TEST_F(RecipeStepTest, checkSetMenge) {
    recipeStep->setMenge(20);
    int mengeTemp = recipeStep->getMenge();
    EXPECT_TRUE(20 == mengeTemp);

    EXPECT_FALSE(10 == mengeTemp);
    EXPECT_FALSE(-1 == mengeTemp);
}
