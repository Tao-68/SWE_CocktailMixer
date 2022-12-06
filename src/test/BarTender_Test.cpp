#include <limits.h>
#include "gtest/gtest.h"

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#define protected public
#define private public
#include "BarTender.h"
#undef protected
#undef private


class BarTenderTest : public ::testing::Test {
protected:
    BarTender *bt;
    DeviceManager *dm;
    AvailableIngredients *ai;
    Recipe *r;

    std::basic_streambuf<char>* orig_cout;
    std::stringstream test_cout;

    virtual void SetUp() {
        std::cout << "Start of " << "BarTenderTest" << std::endl << std::flush;

        ai = new AvailableIngredients();
        if(ai != nullptr){
            dm = new DeviceManager(ai);

            if (dm != nullptr){
                bt = new BarTender(dm);
                r = new Recipe();
                r->setName("Caipirinha");
                r->appendStep("Zitronensaft", 2);
                r->appendStep("Limettensaft", 2.7);
            }
        }

        if(bt == nullptr){
            std::cout << "Objekt BarTender konnte nicht erzeugt werden" << std::endl;
        }
        // you never know what the constructor is really doing
        // so make the list empty and fill it yourself!

        orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
        std::cout.rdbuf(orig_cout);
        delete bt;
        delete dm;
        delete ai;
        std::cout << "End of " << "BarTenderTest" << std::endl << std::flush;
        //std::cout.rdbuf(orig_cout);
    }
};

TEST_F(BarTenderTest, BarTenderConstructor)
{
    BarTender *bt2 = new BarTender(dm);

    EXPECT_NE(bt2, nullptr);
    EXPECT_NE(bt2->myDeviceVerwalter, nullptr);

    delete bt2;
}

TEST_F(BarTenderTest, prepareCocktail)
{
    EXPECT_TRUE(bt->prepareCocktail(r));
}

TEST_F(BarTenderTest, cleaningDevice)
{
    test_cout.clear();

    std::map<std::string, InternalDevice *>::iterator device = bt->myDeviceVerwalter->devices->begin();
    std::string name = device->first;
    bt->myDeviceVerwalter->usedDevices.push_back(device);

    std::string ausgabe = "Device mit der Aktion: " + name + " wird jetzt geputzt: ";

    bt->cleaningDevices();
    EXPECT_EQ( ausgabe, test_cout.str().substr(0, 51) );

}