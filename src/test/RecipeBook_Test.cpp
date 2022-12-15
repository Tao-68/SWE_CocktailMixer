#include <limits.h>
#include "gtest/gtest.h"

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#define protected public
#define private public
#include "RecipeBook.h"
#undef protected
#undef private

class RecipeBookTest : public ::testing::Test {
 protected:
  RecipeBook* r;

  virtual void SetUp() {
        r = new RecipeBook();
        // you never know what the constructor is really doing
        // so make the list empty and fill it yourself!
        
        r->recipes.clear();
        Recipe* r1;

        r1 = new Recipe;
        r1->setName("Caipirinha");
        r1->appendStep("Limettenstuecke", 8);
        r1->setRecipeID(1);
        r->recipes.push_back(r1);

        r1 = new Recipe;
        r1->setName("Margarita");
        r1->appendStep("Zitronensaft", 2);
        r1->setRecipeID(2);
        r->recipes.push_back(r1);
          
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    delete r;
  }
};

TEST_F(RecipeBookTest,getNumberOfRecipesReturnsValueOfAttribute){
    int noOfRecipes=r->recipes.size();
    EXPECT_EQ(noOfRecipes,r->getNumberOfRecipes());
}

TEST_F(RecipeBookTest,getRecipeReturnsCorrectRecipe){
    Recipe* rez;
    rez = r->getRecipe(0);
    EXPECT_EQ(rez->getName(),"Caipirinha");

    rez = r->getRecipe(1);
    EXPECT_EQ(rez->getName(),"Margarita");
}

TEST_F(RecipeBookTest,getRecipeReturnsNoRecipe)
{
    EXPECT_EQ(r->getRecipe(2), nullptr);
}

TEST_F(RecipeBookTest,getRecipeWithID)
{
    Recipe* recipe = r->getRecipeWithID(1);
    EXPECT_EQ(recipe->getName(), "Caipirinha");
}

TEST_F(RecipeBookTest,getRecipeWithIDReturnNullptr)
{
    Recipe* recipe = r->getRecipeWithID(10);
    EXPECT_EQ(recipe, nullptr);
}

TEST_F(RecipeBookTest,deleteRecipeRemovesCorrectRecipe){
    EXPECT_FALSE(r->deleteRecipe(-1));
    EXPECT_FALSE(r->deleteRecipe(42));
    EXPECT_FALSE(r->deleteRecipe(2)); 
    
    EXPECT_TRUE(r->deleteRecipe(0));
    // Since recipe #0 is deleted now Margarita is #0
    Recipe* rez;
    rez = r->getRecipe(0);
    EXPECT_EQ(rez->getName(),"Margarita");    
}

TEST_F(RecipeBookTest, createCaipirinha)
{
    r->recipes.clear();
    r->createCaipirinha();
    EXPECT_EQ(r->getNumberOfRecipes(), 1);
    EXPECT_EQ(r->getRecipe(0)->getName(), "Caipirinha");
}

TEST_F(RecipeBookTest, createMargarita)
{
    r->recipes.clear();
    r->createMargarita();
    EXPECT_EQ(r->getNumberOfRecipes(), 1);
    EXPECT_EQ(r->getRecipe(0)->getName(), "Margarita");
}

TEST_F(RecipeBookTest, createDaiquiri)
{
    r->recipes.clear();
    r->createDaiquiri();
    EXPECT_EQ(r->getNumberOfRecipes(), 1);
    EXPECT_EQ(r->getRecipe(0)->getName(), "Daiquiri");
}

TEST_F(RecipeBookTest, createPlantersPunch)
{
    r->recipes.clear();
    r->createPlantersPunch();
    EXPECT_EQ(r->getNumberOfRecipes(), 1);
    EXPECT_EQ(r->getRecipe(0)->getName(), "Planters Punch");
}

TEST_F(RecipeBookTest, createCaipiroska)
{
    r->recipes.clear();
    r->createCaipiroska();
    EXPECT_EQ(r->getNumberOfRecipes(), 1);
    EXPECT_EQ(r->getRecipe(0)->getName(), "Caipiroska");
}

TEST_F(RecipeBookTest, createCaipirissima)
{
    r->recipes.clear();
    r->createCaipirissima();
    EXPECT_EQ(r->getNumberOfRecipes(), 1);
    EXPECT_EQ(r->getRecipe(0)->getName(), "Caipirissima");
}

TEST_F(RecipeBookTest, createCubanIsland)
{
    r->recipes.clear();
    r->createCubanIsland();
    EXPECT_EQ(r->getNumberOfRecipes(), 1);
    EXPECT_EQ(r->getRecipe(0)->getName(), "Cuban Island");
}

TEST_F(RecipeBookTest, createMartiniJamesB)
{
    r->recipes.clear();
    r->createMartiniJamesB();
    EXPECT_EQ(r->getNumberOfRecipes(), 1);
    EXPECT_EQ(r->getRecipe(0)->getName(), "Martini James B");
}