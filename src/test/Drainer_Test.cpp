#include "gtest/gtest.h"
#include <sstream>

#define protected public
#define private public

#include "Drainer.h"

#undef protected
#undef private

class DrainerTest : public ::testing::Test {

protected:
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;
    Waage* scale = new Waage(0, 0);
    Drainer* drainer = new Drainer(25, 1000, scale);

    void SetUp() override {
        std::cout << "Start of " << "DrainerTest" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    }

    void TearDown() override {
        scale->detach(scale->observers.at(0));
        delete drainer;

        std::cout.rdbuf(orig_cout);
        std::cout << "End of " << "DrainerTest" << std::endl << std::flush;
    }
};

TEST_F(DrainerTest, constructorIsValid) {

    EXPECT_EQ(drainer->gramPerTime, 25);
    EXPECT_EQ(drainer->zeiteinheit, 1000);
    // Scale is not nullptr
    EXPECT_NE(drainer->scale, nullptr);
    // "attach" works fine
    EXPECT_EQ(scale->observers.at(0), drainer);
}

TEST_F(DrainerTest, updateIsValid) {

    drainer->doinIt = true;
    scale->deltaWeight = 10;

    // Case 1: deltaWeight < value
    drainer->value = 100;
    drainer->update();
    EXPECT_EQ(drainer->doinIt, false);

    // Case 2: deltaWeight = value
    drainer->doinIt = true;
    drainer->value = 100;
    drainer->update();
    EXPECT_EQ(drainer->doinIt, false);
}

TEST_F(DrainerTest, DoItIsValid) {

    drainer->doIt(15.0);
    EXPECT_EQ(drainer->value, 15.0);
    EXPECT_EQ(drainer->doinIt, false);
}