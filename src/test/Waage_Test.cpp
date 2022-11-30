#include "gtest/gtest.h"
#define protected public
#define private public
#include "Waage.h"
#undef protected
#undef private
#include <sstream>

class WaageTest: public ::testing::Test {
protected:
    Waage* waage;
    std::basic_streambuf<char>* orig_cout;
    std::stringstream test_cout;

    virtual void SetUp() {
        std::cout << "Start of " << "WaageTest" << std::endl << std::flush;

        int weight = 0;
        int deltaWeight = 0;
        waage = new Waage(weight, deltaWeight);
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
        std::cout.rdbuf(orig_cout);
        delete waage;
        std::cout << "End of " << "WaageTest" << std::endl << std::flush;

    }

};

TEST_F(WaageTest, checkChangeWeightandDeltaWeight) {
    waage->changeWeight(10);
    EXPECT_FALSE(0 == waage->weight);
    EXPECT_FALSE(0 == waage->deltaWeight);

    EXPECT_TRUE(10 == waage->weight);
    EXPECT_TRUE(10 == waage->deltaWeight);
}

TEST_F(WaageTest, checkChangeWeightandDeltaWeightIfWeightLessThan0) {
    waage->weight = -1;
    waage->changeWeight(0);
    EXPECT_TRUE(0 == waage->weight);
    EXPECT_TRUE(0 == waage->deltaWeight);
}

TEST_F(WaageTest, checkResetDeltaWeight) {
    waage->weight = 10;
    waage->deltaWeight = 10;
    waage->resetDeltaWeight();
    EXPECT_FALSE(0 == waage->weight);
    EXPECT_TRUE(10 == waage->weight);
    EXPECT_TRUE(0 == waage->deltaWeight);
}

TEST_F(WaageTest, checkResetDeltaWeightReturnWrongValue) {
    waage->deltaWeight = 10;
    waage->resetDeltaWeight();
    EXPECT_FALSE(10 == waage->deltaWeight);
}

TEST_F(WaageTest, checkGetWeight) {
    EXPECT_FALSE(10 == waage->weight);
    EXPECT_FALSE(-1 == waage->weight);

    EXPECT_TRUE(0 == waage->getWeight());
}

TEST_F(WaageTest, checkGetDeltaWeight) {
    EXPECT_FALSE(10 == waage->deltaWeight);
    EXPECT_FALSE(-1 == waage->deltaWeight);

    EXPECT_TRUE(0 == waage->getDeltaWeight());
}