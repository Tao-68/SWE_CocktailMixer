#include "gtest/gtest.h"
#define protected public
#define private public
#include "CocktailPro.h"
#undef protected
#undef private
#include <sstream>

class UserStory3 : public ::testing::Test {
protected:
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;
    CocktailPro *cp;

    void SetUp() override {
        std::cout << "\n\nStart of " << "UserStory3\n" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());

        // char placeholder[] to let mode[] at param[1]
        char mode[] = "-USERSTORY3";
        char placeholder[] = "";
        char *param[2] = { placeholder,mode};
        cp = new CocktailPro(2, param);

    }

    void TearDown() override {
        std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
        delete cp;
        std::cout << "\n\nEnd of " << "UserStory3\n" << std::endl << std::flush;
    }
};

// For presentation 13. January (1/2)
// We need to comment the line 17, 28 and 40 if we want to see a output in the terminal.
TEST_F(UserStory3, userStory3Demo1) {
    Dispenser* dispenserCachaca = dynamic_cast<Dispenser*>(cp->deviceManager->devices->at("Cachaca"));
    dispenserCachaca->capacity = 4;

    test_cout.clear();
    cp->testInput = "1";
    cp->start();

    std::string backN = "\n";
    
    std::string expected_text = "Hallo, ich bin der BarTender!" + backN +
            "Ich habe Ihre Bestellung: Caipirinha erhalten." + backN +
            "Jetzt geht es los!" + backN + "" + backN +
            "Rezeptschritt: Limettenstuecke, 8g" + backN +
            "Limettenstuecke Dosierer-Kapazitaet vor der Ventiloeffnung (1000g)" + backN +
            "Limettenstuecke Ventil wurde geoeffnet" + backN + "********" + backN +
            "Limettenstuecke Ventil wurde geschlossen" + backN +
            "Es wurden 80g Limettenstuecke abgefuellt" + backN +
            "Limettenstuecke Dosierer-Kapazitaet nach der Ventilschliessung (920g)" +backN +
            "" + backN + "Rezeptschritt: Zucker, 15g" + backN +
            "Zucker Dosierer-Kapazitaet vor der Ventiloeffnung (1000g)" + backN +
            "Zucker Ventil wurde geoeffnet" + backN + "..............." + backN +
            "Zucker Ventil wurde geschlossen" + backN +
            "Es wurden 15g Zucker abgefuellt" + backN +
            "Zucker Dosierer-Kapazitaet nach der Ventilschliessung (985g)" + backN +
            "" + backN + "Rezeptschritt: Stampfen, 20ml" + backN +
            "********************" + backN + "" + backN +
            "Rezeptschritt: Eis, 90g" + backN +
            "Eis Dosierer-Kapazitaet vor der Ventiloeffnung (1000g)" + backN +
            "Eis Ventil wurde geoeffnet" + backN + "*****" + backN +
            "Eis Ventil wurde geschlossen" + backN +
            "Es wurden 100g Eis abgefuellt" + backN +
            "Eis Dosierer-Kapazitaet nach der Ventilschliessung (910g)" + backN + "" + backN +
            "Rezeptschritt: Cachaca, 5ml" + backN +
            "Cachaca Dosierer-Kapazitaet vor der Ventiloeffnung (4ml)" + backN + "" + backN +
            "Der naechste Cocktail ist ungeniessbar, bitte wegschuetteln!" + backN +
            "Druecken Sie -2 fuer Bestaetigung, dass Sie diese Warnung gelesen haben." + backN +
            "-2" + backN + "Entleervorgang wird begonnen..." + backN + "********" + backN +
            "Entleervorgang wurde beendet, bitte entnehmen Sie ungeniessbaren Cocktail und "
            "schuetteln diesen weg!" + backN + "" + backN + "Dosierer Limettenstuecke wird geputzt" + backN +
            "**" + backN + "Dosierer Limettenstuecke ist geputzt worden." + backN + "" + backN +
            "Dosierer Zucker wird geputzt" + backN + "**" + backN + "Dosierer Zucker ist geputzt worden." +
            backN + "" + backN + "Device Stampfen wird geputzt" + backN + "**" + backN +
            "Device Stampfen ist geputzt worden." + backN + "" + backN + "Dosierer Eis wird geputzt"
            + backN + "**" + backN + "Dosierer Eis ist geputzt worden." + backN + "" +
            backN + "";

    EXPECT_EQ(expected_text, test_cout.str().substr(1587, 2100));
};

// For presentation 13. January (2/2)
// We need to comment the line 17, 28 and 91 if we want to see a output in the terminal.
TEST_F(UserStory3, userStory3Demo2) {
    Dispenser* dispenserCachaca = dynamic_cast<Dispenser*>(cp->deviceManager->devices->at("Eis"));
    dispenserCachaca->capacity =20;
    test_cout.clear();

    test_cout.clear();
    cp->testInput = "7";
    cp->start();

    std::string backN = "\n";

    std::string expected_text = "Hallo, ich bin der BarTender!" + backN +
            "Ich habe Ihre Bestellung: Cuban Island erhalten." + backN +
            "Jetzt geht es los!" + backN + "" + backN +
            "Rezeptschritt: Zitronensaft, 2ml" + backN +
            "Zitronensaft Dosierer-Kapazitaet vor der Ventiloeffnung (1000ml)" + backN +
            "Zitronensaft Ventil wurde geoeffnet" + backN + ".." + backN +
            "Zitronensaft Ventil wurde geschlossen" + backN +
            "Es wurden 2ml Zitronensaft abgefuellt" + backN +
            "Zitronensaft Dosierer-Kapazitaet nach der Ventilschliessung (998ml)" + backN + "" + backN +
            "Rezeptschritt: Cointreau, 2ml" + backN +
            "Cointreau Dosierer-Kapazitaet vor der Ventiloeffnung (1000ml)" + backN +
            "Cointreau Ventil wurde geoeffnet" + backN + ".." + backN +
            "Cointreau Ventil wurde geschlossen" + backN +
            "Es wurden 2ml Cointreau abgefuellt" + backN +
            "Cointreau Dosierer-Kapazitaet nach der Ventilschliessung (998ml)" + backN + "" + backN +
            "Rezeptschritt: Rum weiss, 2ml" + backN +
            "Rum weiss Dosierer-Kapazitaet vor der Ventiloeffnung (1000ml)" + backN +
            "Rum weiss Ventil wurde geoeffnet" + backN + ".." + backN +
            "Rum weiss Ventil wurde geschlossen" + backN +
            "Es wurden 2ml Rum weiss abgefuellt" + backN +
            "Rum weiss Dosierer-Kapazitaet nach der Ventilschliessung (998ml)" + backN +
            "" + backN + "Rezeptschritt: Wodka, 2ml" + backN +
            "Wodka Dosierer-Kapazitaet vor der Ventiloeffnung (1000ml)" + backN +
            "Wodka Ventil wurde geoeffnet" + backN + ".." + backN +
            "Wodka Ventil wurde geschlossen" + backN + "Es wurden 2ml Wodka abgefuellt" + backN +
            "Wodka Dosierer-Kapazitaet nach der Ventilschliessung (998ml)" + backN + "" + backN +
            "Rezeptschritt: Eis, 30g" + backN +
            "Eis Dosierer-Kapazitaet vor der Ventiloeffnung (20g)" + backN + "" + backN +
            "Der nae" "chste Cocktail ist ungeniessbar, bitte wegschuetteln!"+ backN +
            "Druecken Sie -2 fuer Bestaetigung, dass Sie diese Warnung gelesen haben." + backN +
            "-2" + backN + "Entleervorgang wird begonnen..." + backN + "*" + backN +
            "Entleervorgang wurde beendet, bitte entnehmen Sie ungeniessbaren Cocktail und schuetteln diesen weg!"
            + backN + "" + backN +
            "Dosierer Zitronensaft wird geputzt" +
            backN + "**" + backN +
            "Dosierer Zitronensaft ist geputzt worden." + backN + "" + backN +
            "Dosierer Cointreau wird geputzt" + backN + "**" + backN +
            "Dosierer Cointreau ist geputzt worden." + backN + "" + backN +
            "Dosierer Rum weiss wird geputzt" + backN + "**" + backN +
            "Dosierer Rum weiss ist geputzt worden." + backN + "" + backN +
            "Dosierer Wodka wird geputzt" + backN + "**" + backN +
            "Dosierer Wodka ist geputzt worden." + backN + "" + backN + "";

    EXPECT_EQ(expected_text, test_cout.str().substr(1587, 2100));
};
