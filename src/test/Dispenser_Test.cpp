#include "gtest/gtest.h"
#include <sstream>

#define protected public
#define private public

#include "Dispenser.h"
#include "Waage.h"

#undef protected
#undef private

class DispenserTest : public ::testing::Test {

protected:
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;
    Waage* scale = new Waage(0, 0);
    Dispenser* dispenser = new Dispenser(20, 1000, "Gin", scale, "ml");

    void SetUp() override {
        std::cout << "Start of " << "DispenserTest" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    }

    void TearDown() override {
        // "delete scale;" scale will be automatically deleted in dispenser destructor
        scale->detach(scale->observers.at(0));
        delete dispenser;

        std::cout.rdbuf(orig_cout);
        std::cout << "End of " << "DispenserTest" << std::endl << std::flush;
    }
};

TEST_F(DispenserTest, constructorIsValid) {

    EXPECT_EQ(dispenser->gramPerTime, 20);
    EXPECT_EQ(dispenser->zeiteinheit, 1000);
    EXPECT_EQ(dispenser->content, "Gin");
    // Scale is not nullptr
    EXPECT_NE(dispenser->scale, nullptr);
    // "attach" works fine
    // Dispenser* dispenserPtr = &dispenser;
    EXPECT_EQ(scale->observers.at(0), dispenser);


}

TEST_F(DispenserTest, getPiecePerTimeIsValid) {
    
    EXPECT_EQ(dispenser->getPiecePerTime(), dispenser->gramPerTime);
}

TEST_F(DispenserTest, updateIsValid) {

    dispenser->doinIt = true;
    scale->deltaWeight = 100;

    // Case 1: deltaWeight > weight
    scale->weight = 10;
    dispenser->update();
    EXPECT_EQ(dispenser->doinIt, false);

    // Case 2: deltaWeight = weight
    dispenser->doinIt = true;
    scale->weight = 100;
    dispenser->update();
    EXPECT_EQ(dispenser->doinIt, false);
}


TEST_F(DispenserTest, DoItIsValid) {

    dispenser->doIt(5.0);
    EXPECT_EQ(dispenser->weight, 5.0);
    EXPECT_EQ(dispenser->doinIt, false);
}

TEST_F(DispenserTest, decreaseCapacity) {

    EXPECT_EQ(1000, dispenser->capacity);
    dispenser->decreaseCapacity(100);
    EXPECT_EQ(900, dispenser->capacity);

    dispenser->decreaseCapacity(1000000);
    EXPECT_EQ(0, dispenser->capacity);
}

TEST_F(DispenserTest, maxAvailableOutput) {

    dispenser->weight = 0;
    EXPECT_EQ(0, dispenser->weight);
    dispenser->maxAvailableOutput(100);
    EXPECT_EQ(100, dispenser->weight);

    dispenser->maxAvailableOutput(900000);
    EXPECT_EQ(dispenser->capacity, dispenser->weight);
}