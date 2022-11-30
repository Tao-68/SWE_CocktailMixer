#include <limits.h>
#include <string>
#include "gtest/gtest.h"
#include <string.h>

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#define protected public
#define private public
#include "MixableRecipeBook.h"
#undef protected
#undef private

class MixableRecipeBookTest: public ::testing::Test
{
protected:
    MixableRecipeBook *mrb_1;
    std::basic_streambuf<char>* orig_cout;
    std::stringstream test_cout;


    void SetUp() override
    {
        std::cout << "Start of " << "MixableRecipeBookTest" << std::endl << std::flush;

        mrb_1 = new MixableRecipeBook(new AvailableIngredients());

        orig_cout = std::cout.rdbuf(test_cout.rdbuf());



    }

    virtual void TearDown()
    {
        std::cout.rdbuf(orig_cout);
        delete mrb_1;
        std::cout << "End of " << "MixableRecipeBookTest" << std::endl << std::flush;
    }
};

TEST_F(MixableRecipeBookTest, getAllCocktails)
{
    test_cout.clear();
    std::string backN = "\n";
    std::string expectedText = "*********************************************" + backN
                             + "Es gibt 6 Cocktails" + backN
                             + "1. Caipirinha: Limettenstuecke, Zucker, Stampfen, Eis, Cachaca, Mischen" + backN
                             + "2. Margarita: Zitronensaft, Cointreau, Tequilla, Eis, Mischen" + backN
                             + "3. Caipiroska: Limettenstuecke, Zucker, Stampfen, Eis, Wodka, Mischen" + backN
                             + "4. Caipirissima: Limettenstuecke, Zucker, Stampfen, Eis, Rum weiss, Mischen" + backN
                             + "5. Cuban Island: Zitronensaft, Cointreau, Rum weiss, Wodka, Eis, Mischen" + backN
                             + "6. Martini James B: Gin, Wodka, Noilly Prat, Schuetteln" + backN
                             + "*********************************************" + backN;

    mrb_1->getAllCocktails();
    EXPECT_EQ(expectedText, test_cout.str().substr(0, 565));
};

TEST_F(MixableRecipeBookTest, setZutatenVerwalter)
{
    AvailableIngredients *ai = new AvailableIngredients();
    mrb_1->setZutatenVerwalter(ai);

    EXPECT_NE(mrb_1->myZutatenVerwalter, nullptr);
    EXPECT_EQ(mrb_1->myZutatenVerwalter, ai);

    delete ai;
}

TEST_F(MixableRecipeBookTest, sucheZutat)
{
    std::string search = "Zucker";

    EXPECT_TRUE(mrb_1->sucheZutat(search));
}


TEST_F(MixableRecipeBookTest, MixableRecipeBookConstructor)
{
    MixableRecipeBook *mrb = new MixableRecipeBook(new AvailableIngredients());

    EXPECT_NE(mrb, nullptr);
    EXPECT_EQ(mrb->rezepte.size(), 0);
    EXPECT_NE(mrb->myZutatenVerwalter, nullptr);
}