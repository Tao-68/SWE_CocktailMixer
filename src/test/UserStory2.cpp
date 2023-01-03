#include <string>
#include "gtest/gtest.h"
#include <sstream>

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#include "CocktailPro.h"

class UserStory2 : public ::testing::Test {
protected:
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;
    CocktailPro *cp;

    void SetUp() override {
        std::cout << "Start of " << "UserStory2" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());

        // When it is a real test, then "real_test[]" set to "true"
        // When not real test, then set to the default "false"
        char mode[] = "-US2";
        char real_test[] = "false";
        char *param[2] = { mode , real_test};
        cp = new CocktailPro(2, param);

    }

    void TearDown() override {
        std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
        delete cp;
        std::cout << "End of " << "UserStory2" << std::endl << std::flush;
    }
};

TEST_F(UserStory2, validateOutput) {
    test_cout.clear();
    cp->executeStart = 1;
    cp->start();


    std::string backN = "\n";
    std::string expected_text = 
            "1" + backN +
            "Hallo, ich bin der BarTender!" + backN + 
            "Ich habe Ihre Bestellung: Caipirinha erhalten." + backN +
            "Jetzt geht es los!" +  backN + backN +
            "Rezeptschritt: Limettenstuecke, 8g" + backN + 
            "Limettenstuecke Dosierer-Kapazitaet (1000g)" + backN +
            "Limettenstuecke Ventil wurde geoeffnet" + backN + 
            "********" + backN + "Limettenstuecke Ventil wurde geschlossen" + backN +
            "Es wurden 80g Limettenstuecke abgefuellt" + backN + backN +
            "Rezeptschritt: Zucker, 15g" + backN +
            "Zucker Dosierer-Kapazitaet (1000g)" + backN +
            "Zucker Ventil wurde geoeffnet" + backN +
            "..............." + backN +
            "Zucker Ventil wurde geschlossen" + backN +
            "Es wurden 15g Zucker abgefuellt" + backN + backN +
            "Rezeptschritt: Stampfen, 20ml" + backN +
            "********************" + backN +
            "Rezeptschritt: Eis, 90g" + backN +
            "Eis Dosierer-Kapazitaet (1000g)" + backN +
            "Eis Ventil wurde geoeffnet" + backN +
            "*****" + backN +
            "Eis Ventil wurde geschlossen" + backN +
            "Es wurden 100g Eis abgefuellt" + backN +
            "" + backN +
            "Rezeptschritt: Cachaca, 5ml" + backN +
            "Cachaca Dosierer-Kapazitaet (1000ml)" + backN +
            "Cachaca Ventil wurde geoeffnet" + backN +
            "....." + backN +
            "Cachaca Ventil wurde geschlossen" + backN +
            "Es wurden 5ml Cachaca abgefuellt" + backN +
            "" + backN +
            "Rezeptschritt: Mischen, 10ml" + backN +
            "**********" + backN +
            "Ihr Cocktail hat ein Gesamtgewicht von 200g";

    EXPECT_EQ(expected_text, test_cout.str().substr(1581, 934));
}

TEST_F(UserStory2, validateNullCapacity) {
    test_cout.clear();
    cp->executeStart = 29;
    cp->start();
}