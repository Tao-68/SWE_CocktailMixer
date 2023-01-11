#include "gtest/gtest.h"
#define protected public
#define private public
#include "CocktailPro.h"
#undef protected
#undef private
#include <sstream>

class UserStory4 : public ::testing::Test {
protected:
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;
    CocktailPro *cp;

    void SetUp() override {
        std::cout << "\n\nStart of " << "UserStory4\n" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());

        // char placeholder[] to let mode[] at param[1]
        char mode[] = "-USERSTORY4";
        char placeholder[] = "";
        char *param[2] = { placeholder,mode};
        cp = new CocktailPro(2, param);

    }

    void TearDown() override {
        std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
        delete cp;
        std::cout << "\n\nEnd of " << "UserStory4\n" << std::endl << std::flush;
    }
};

//unsure how to test this

/*
TEST_F(UserStory4, UserStoryDemo1){
    Dispenser* dispenserTequila = dynamic_cast<Dispenser*>(cp->deviceManager->devices->at("Tequila"));
    dispenserTequila->capacity = 3;

    test_cout.clear();
    cp->testInput = "2";
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
}
*/