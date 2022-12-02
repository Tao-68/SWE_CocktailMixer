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
    BarTender* bt;

    virtual void SetUp() {
        bt = new BarTender(new DeviceManager(new AvailableIngredients()));
        // you never know what the constructor is really doing
        // so make the list empty and fill it yourself!


    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete bt;
    }
};
