#include "gtest/gtest.h"
#define protected public
#define private public
#include "CocktailPro.h"
#undef protected
#undef private
#include <sstream>

class UserStory5 : public ::testing::Test {
protected:
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;
    CocktailPro *cp;

    void SetUp() override {
        std::cout << "\n\nStart of " << "UserStory5\n" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());

        // char placeholder[] to let mode[] at param[1]
        char mode[] = "-USERSTORY5";
        char placeholder[] = "";
        char *param[2] = { placeholder,mode};
        cp = new CocktailPro(2, param);

    }

    void TearDown() override {
        std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
        delete cp;
        std::cout << "\n\nEnd of " << "UserStory5\n" << std::endl << std::flush;
    }
};

// For presentation 20. January
// We need to comment the line 17, 28 and 42 if we want to see an output in the terminal.
TEST_F(UserStory5, userStory5Demo1) {
    Dispenser* dispenserCachaca = dynamic_cast<Dispenser*>(cp->deviceManager->devices->at("Cachaca"));
    dispenserCachaca->capacity = 4;

    Dispenser* dispenserWodka = dynamic_cast<Dispenser*>(cp->deviceManager->devices->at("Wodka"));
    dispenserWodka->capacity = 1;
    test_cout.clear();
    cp->start();


    std::string backN = "\n";

    std::string expected_text = "Open the ingredients fileingredients.txt" + backN
            + "" + backN + "*********** Verfuegbare Zutaten: *************" + backN
            + "Limettenstuecke" + backN + "Zucker" + backN + "Cointreau" + backN
            + "Cachaca" + backN + "Eis" + backN + "Wodka" + backN + "Rum weiss" + backN
            + "Zitronensaft" + backN + "Grenadine" + backN + "Limettensaft" + backN + "Tequilla"
            + backN + "Gin" + backN + "Noilly Prat" + backN + "" + backN +
            "*********************************************" + backN +
            "********** Rezepte vor dem Filtern **********" + backN +
            "*********************************************" + backN + "Es gibt 8 Cocktails" +
            backN + "1. Caipirinha: Limettenstuecke, Zucker, Stampfen, Eis, Cachaca, Mischen" +
            backN + "2. Margarita: Zitronensaft, Cointreau, Tequilla, Eis, Mischen" + backN +
            "3. Daiquiri: Limettensaft, Zuckersirup, Rum weiss, Eis, Mischen" + backN +
            "4. Planters Punch: Zitronensaft, Grenadine, Orangensaft, Rum braun, Eis, Mischen" + backN
            + "5. Caipiroska: Limettenstuecke, Zucker, Stampfen, Eis, Wodka, Mischen" + backN +
            "6. Caipirissima: Limettenstuecke, Zucker, Stampfen, Eis, Rum weiss, Mischen" + backN +
            "7. Cuban Island: Zitronensaft, Cointreau, Rum weiss, Wodka, Eis, Mischen" + backN +
            "8. Martini James B: Gin, Wodka, Noilly Prat, Schuetteln" + backN + "" + backN +
            "*********************************************" + backN + "************* Mischbare Rezepte *************" +
            backN + "*********************************************" + backN + "Es gibt 6 Cocktails" + backN +
            "Caipirinha: Limettenstuecke, Zucker, Stampfen, Eis, Cachaca, Mischen (*Nicht mischbar!*)" + backN +
            "2. Margarita: Zitronensaft, Cointreau, Tequilla, Eis, Mischen" + backN +
            "Caipiroska: Limettenstuecke, Zucker, Stampfen, Eis, Wodka, Mischen (*Nicht mischbar!*)" + backN +
            "6. Caipirissima: Limettenstuecke, Zucker, Stampfen, Eis, Rum weiss, Mischen" +
            backN + "Cuban Island: Zitronensaft, Cointreau, Rum weiss, Wodka, Eis, Mischen (*Nicht mischbar!*)" +
            backN + "Martini James B: Gin, Wodka, Noilly Prat, Schuetteln (*Nicht mischbar!*)" + backN + ""
            + backN + "*********************************************" + backN +
            "Was haetten Sie denn gern? (-1 zum Verlassen)" + backN + "8" + backN +
            "Dieser Cocktail ist nicht mischbar, w\xC3\xA4hle einen anderen." + backN +
            "************* Mischbare Rezepte *************" + backN +
            "*********************************************" + backN + "Es gibt 6 Cocktails" + backN +
            "Caipirinha: Limettenstuecke, Zucker, Stampfen, Eis, Cachaca, Mischen (*Nicht mischbar!*)" + backN
            + "2. Margarita: Zitronensaft, Cointreau, Tequilla, Eis, Mischen" + backN +
            "Caipiroska: Limettenstuecke, Zucker, Stampfen, Eis, Wodka, Mischen (*Nicht mischbar!*)" + backN
            + "6. Caipirissima: Limettenstuecke, Zucker, Stampfen, Eis, Rum weiss, Mischen" + backN
            + "Cuban Island: Zitronensaft, Cointreau, Rum weiss, Wodka, Eis, Mischen (*Nicht mischbar!*)" +
            backN + "Martini James B: Gin, Wodka, Noilly Prat, Schuetteln (*Nicht mischbar!*)" + backN +
            "" + backN + "*********************************************" + backN +
            "Was haetten Sie denn gern? (-1 zum Verlassen)" + backN + "6" + backN + "Hallo, ich bin der BarTender!" +
            backN + "Ich habe Ihre Bestellung: Caipirissima erhalten." + backN + "Jetzt geht es los!" + backN + "" +
            backN + "Rezeptschritt: Limettenstuecke, 8g" + backN +
            "Limettenstuecke Dosierer-Kapazitaet vor der Ventiloeffnung (1000g)" + backN +
            "Limettenstuecke Ventil wurde geoeffnet" + backN + "********" + backN +
            "Limettenstuecke Ventil wurde geschlossen" + backN + "Es wurden 80g Limettenstuecke abgefuellt" + backN +
            "Limettenstuecke Dosierer-Kapazitaet nach der Ventilschliessung (920g)" + backN + "" + backN +
            "Rezeptschritt: Zucker, 15g" + backN + "Zucker Dosierer-Kapazitaet vor der Ventiloeffnung (1000g)" + backN +
            "Zucker Ventil wurde geoeffnet" + backN + "..............." + backN + "Zucker Ventil wurde geschlossen" + backN
            + "Es wurden 15g Zucker abgefuellt" + backN + "Zucker Dosierer-Kapazitaet nach der Ventilschliessung (985g)" +
            backN + "" + backN + "Rezeptschritt: Stampfen, 20ml" + backN + "********************" + backN + "" +
            backN + "Rezeptschritt: Eis, 90g" + backN + "Eis Dosierer-Kapazitaet vor der Ventiloeffnung (1000g)" +
            backN + "Eis Ventil wurde geoeffnet" + backN + "*****" + backN + "Eis Ventil wurde geschlossen" + backN
            + "Es wurden 100g Eis abgefuellt" + backN + "Eis Dosierer-Kapazitaet nach der Ventilschliessung (910g)" +
            backN + "" + backN + "Rezeptschritt: Rum weiss, 5ml" + backN +
            "Rum weiss Dosierer-Kapazitaet vor der Ventiloeffnung (1000ml)" + backN + "Rum weiss Ventil wurde geoeffnet"
            + backN + "....." + backN + "Rum weiss Ventil wurde geschlossen" + backN + "Es wurden 5ml Rum weiss abgefuellt"
            + backN + "Rum weiss Dosierer-Kapazitaet nach der Ventilschliessung (995ml)" + backN + "" + backN +
            "Rezeptschritt: Mischen, 10ml" + backN + "**********" + backN + "" + backN +
            "Ihr Cocktail hat ein Gesamtgewicht von 200g " + backN + "" + backN + "Entleervorgang wird begonnen..." + backN
            + "********" + backN + "Entleervorgang wurde beendet, bitte entnehmen Sie ihren Cocktail!" + backN + "" + backN
            + "Dosierer Limettenstuecke wird geputzt" + backN + "**" + backN +
            "Dosierer Limettenstuecke ist geputzt worden." + backN + "" + backN +
            "Dosierer Zucker wird geputzt" + backN + "**" + backN +
            "Dosierer Zucker ist geputzt worden." + backN + "" + backN +
            "Device Stampfen wird geputzt" + backN + "**" + backN +
            "Device Stampfen ist geputzt worden." + backN + "" + backN +
            "Dosierer Eis wird geputzt" + backN + "**" + backN +
            "Dosierer Eis ist geputzt worden." + backN + "" + backN +
            "Dosierer Rum weiss wird geputzt" + backN + "**" + backN +
            "Dosierer Rum weiss ist geputzt worden." + backN + "" + backN +
            "Device Mischen wird geputzt" + backN + "**" + backN +
            "Device Mischen ist geputzt worden." + backN + "" + backN +
            "************* Mischbare Rezepte *************" + backN +
            "*********************************************" + backN + "Es gibt 6 Cocktails" + backN +
            "Caipirinha: Limettenstuecke, Zucker, Stampfen, Eis, Cachaca, Mischen (*Nicht mischbar!*)" +
            backN + "2. Margarita: Zitronensaft, Cointreau, Tequilla, Eis, Mischen" + backN +
            "Caipiroska: Limettenstuecke, Zucker, Stampfen, Eis, Wodka, Mischen (*Nicht mischbar!*)" +
            backN + "6. Caipirissima: Limettenstuecke, Zucker, Stampfen, Eis, Rum weiss, Mischen" + backN
            + "Cuban Island: Zitronensaft, Cointreau, Rum weiss, Wodka, Eis, Mischen (*Nicht mischbar!*)" +
            backN + "Martini James B: Gin, Wodka, Noilly Prat, Schuetteln (*Nicht mischbar!*)" + backN + "" +
            backN + "*********************************************" + backN +
            "Was haetten Sie denn gern? (-1 zum Verlassen)" + backN + "1" + backN +
            "Dieser Cocktail ist nicht mischbar, w\xC3\xA4hle einen anderen." + backN +
            "************* Mischbare Rezepte *************" + backN + "*********************************************"
            + backN + "Es gibt 6 Cocktails" + backN +
            "Caipirinha: Limettenstuecke, Zucker, Stampfen, Eis, Cachaca, Mischen (*Nicht mischbar!*)"
            + backN + "2. Margarita: Zitronensaft, Cointreau, Tequilla, Eis, Mischen" + backN
            + "Caipiroska: Limettenstuecke, Zucker, Stampfen, Eis, Wodka, Mischen (*Nicht mischbar!*)" +
            backN + "6. Caipirissima: Limettenstuecke, Zucker, Stampfen, Eis, Rum weiss, Mischen" + backN
            + "Cuban Island: Zitronensaft, Cointreau, Rum weiss, Wodka, Eis, Mischen (*Nicht mischbar!*)" +
            backN + "Martini James B: Gin, Wodka, Noilly Prat, Schuetteln (*Nicht mischbar!*)" + backN + ""
            + backN + "*********************************************" + backN + "Was haetten Sie denn gern? (-1 zum Verlassen)"
            + backN + "-1" + backN + "";
    

    EXPECT_EQ(expected_text, test_cout.str().substr(0, 10000));
};