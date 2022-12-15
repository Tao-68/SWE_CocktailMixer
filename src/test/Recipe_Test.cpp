#include <limits.h>
#include <string>
#include "gtest/gtest.h"

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#include "Recipe.h"

class RecipeTest: public ::testing::Test
{
protected:
    Recipe* r_1;
    Recipe* r_2;
    std::basic_streambuf<char>* orig_cout;
    std::stringstream test_cout;


    void SetUp() override
    {
        std::cout << "Start of " << "RecipeTest" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());

        r_1 = new Recipe();
        r_1->setName("Caipirinha");
        r_1->appendStep("Apfelsaft", 0.5);
        r_1->appendStep("Vodka", 1.7);

        r_2 = new Recipe();
    }

    virtual void TearDown()
    {
        std::cout.rdbuf(orig_cout);
        delete r_1;
        delete r_2;
        std::cout << "End of " << "RecipeTest" << std::endl << std::flush;
    }
};

TEST_F(RecipeTest, getName)
{
    EXPECT_EQ("Caipirinha", r_1->getName());
}

TEST_F(RecipeTest, setName)
{
    std::string name = "Daiquiri";
    EXPECT_EQ("", r_2->getName());
    r_2->setName(name);
    EXPECT_EQ(name, r_2->getName());
}

TEST_F(RecipeTest, getNoOfRecipeSteps)
{
    EXPECT_EQ(2, r_1->getNoOfRecipeSteps());
}

TEST_F(RecipeTest, getRecipeStep)
{
    EXPECT_TRUE(r_1->getRecipeStep(0));
    EXPECT_FALSE(r_1->getRecipeStep(5));
}

TEST_F(RecipeTest, appendStep)
{
    std::string ingredient = "Zitrone";
    float amount = 5;
    r_2->appendStep(ingredient, amount);
    RecipeStep *recipe_r_2 = r_2->getRecipeStep(0);

    EXPECT_EQ(ingredient,recipe_r_2->getZutat());
    EXPECT_EQ(amount,recipe_r_2->getMenge());
}

TEST_F(RecipeTest, getAllIngredients)
{
    test_cout.clear();
    std::string expectedName = "Caipirinha: ";
    std::string expectedSteps = "Apfelsaft, Vodka";

    r_1->getAllIngredients();

    // First: Name of Recipe
    EXPECT_EQ(expectedName, test_cout.str().substr(0, 12));

    // Second: The Steps
    EXPECT_EQ(expectedSteps, test_cout.str().substr(12, 16));
}

TEST_F(RecipeTest, setRecipeID){
    r_1->setRecipeID(10);
    EXPECT_EQ(10, r_1->getRecipeID());
    EXPECT_NE(1, r_1->getRecipeID());
    EXPECT_NE(100, r_1->getRecipeID());
}

TEST_F(RecipeTest, getRecipeID){
    r_1->setRecipeID(5);
    EXPECT_EQ(5, r_1->getRecipeID());
    EXPECT_NE(-5, r_1->getRecipeID());
    EXPECT_NE(50, r_1->getRecipeID());
}
TEST_F(RecipeTest, setHidden){
    r_1->setHidden(true);
    EXPECT_TRUE(r_1->isHidden());
    EXPECT_FALSE(r_2->isHidden());
}

TEST_F(RecipeTest, isHidden){
    r_1->setHidden(false);
    EXPECT_FALSE(r_1->isHidden());
    EXPECT_FALSE(r_2->isHidden());
}
