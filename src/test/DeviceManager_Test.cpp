#include "gtest/gtest.h"
#include <sstream>

#define protected public
#define private public

#include "DeviceManager.h"

#undef protected
#undef private

class DeviceManagerTest : public ::testing::Test {

protected:
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;
    AvailableIngredients* availableIngredients = new AvailableIngredients();

    void SetUp() override {
        std::cout << "Start of " << "DeviceManagerTest" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());

    }

    void TearDown() override {
        delete availableIngredients;

        std::cout.rdbuf(orig_cout);
        std::cout << "End of " << "DeviceManagerTest" << std::endl << std::flush;
    }
};

TEST_F(DeviceManagerTest, constructorIsValid) {

    DeviceManager deviceManager(availableIngredients);
    // avaiableIngredients is not null pointer
    EXPECT_NE(deviceManager.availableIngredients, nullptr);
    // scale is not null pointer
    // devices is not null pointer
    // masher is not null pointer
    // shaker is not null pointer
    // mixer is not null pointer
    EXPECT_NE(deviceManager.scale, nullptr);
    EXPECT_NE(deviceManager.devices, nullptr);
    EXPECT_NE(deviceManager.masher, nullptr);
    EXPECT_NE(deviceManager.shaker, nullptr);
    EXPECT_NE(deviceManager.mixer, nullptr);

    // device size is right
    EXPECT_EQ(deviceManager.devices->size(), 17);

}

TEST_F(DeviceManagerTest, createDevicesIsValid) {

    DeviceManager deviceManager(availableIngredients);
    // avaiableIngredients is not null pointer
    // scale is not null pointer
    // devices is not null pointer
    // masher is not null pointer
    // shaker is not null pointer
    // mixer is not null pointer
    EXPECT_NE(deviceManager.availableIngredients, nullptr);
    EXPECT_NE(deviceManager.scale, nullptr);
    EXPECT_NE(deviceManager.devices, nullptr);
    EXPECT_NE(deviceManager.masher, nullptr);
    EXPECT_NE(deviceManager.shaker, nullptr);
    EXPECT_NE(deviceManager.mixer, nullptr);

    // device size is right
    EXPECT_EQ(deviceManager.devices->size(), 17);

}

TEST_F(DeviceManagerTest, setIngredientsManagerIsValid) {

    DeviceManager deviceManager(availableIngredients);
    auto availableIngredients2 = new AvailableIngredients();

    deviceManager.setIngredientsManager(availableIngredients2);

    EXPECT_EQ(deviceManager.availableIngredients, availableIngredients2);

    delete availableIngredients2;
}

TEST_F(DeviceManagerTest, prepareRecipeStepsIsValid) {


    DeviceManager deviceManager(availableIngredients);


    // Test Case 1
    deviceManager.prepareRecipeSteps("Limettenstuecke", 8); // amount is 8 as in RecipeBook.cpp
    // Test Case 2
    deviceManager.prepareRecipeSteps("Gin", 6); // amount is 6 as in RecipeBook.cpp

    bool isLimettenstueckeFound = false;
    bool isGinFound = false;
    for (auto & element : deviceManager.usedDevices)
        if(element->first == "Limettenstuecke" )
            isLimettenstueckeFound = true;
        else if (element->first == "Gin")
            isGinFound = true;
        else if(isLimettenstueckeFound && isGinFound)
            break;

    EXPECT_EQ(isLimettenstueckeFound, true);
    EXPECT_EQ(isGinFound, true);
     
}