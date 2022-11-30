#include "gtest/gtest.h"
#include <sstream>

#define protected public
#define private public

#include "Drainer.h"

#undef protected
#undef private

class InternalDeviceTest : public ::testing::Test {

protected:
    std::basic_streambuf<char> *orig_cout = nullptr;
    std::stringstream test_cout;

    void SetUp() override {
        std::cout << "Start of " << "InternalDeviceTest" << std::endl << std::flush;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    }

    void TearDown() override {
        std::cout.rdbuf(orig_cout);
        std::cout << "End of " << "InternalDeviceTest" << std::endl << std::flush;
    }
};


TEST_F(InternalDeviceTest, constructorIsValid) {
    // InternalDevice is an abstract class and cannot instantiate.
    // We check this class with Drainer class, that implements InternalDevice
    auto scale = new Waage(0, 0);
    auto drainer = new Drainer(25, 1000, scale);

    // Timer is not nullptr
    EXPECT_NE(drainer->myTimer, nullptr);
}