#include "gtest/gtest.h"
#include <chrono>

#define protected public
#define private public
#include "Shaker.h"
#undef protected
#undef private
#include <sstream>

class ShakerTest: public ::testing::Test {
protected:
    Shaker* shaker;
    std::basic_streambuf<char>* orig_cout;
    std::stringstream test_cout;

    virtual void SetUp() {
        std::cout << "Start of " << "ShakerTest" << std::endl << std::flush;

        shaker = new Shaker();
        shaker->myTimer->booster = 1;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());

    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
        std::cout.rdbuf(orig_cout);
        delete shaker;
        std::cout << "End of " << "ShakerTest" << std::endl << std::flush;

    }
};

TEST_F(ShakerTest, checkSleepTimeGreaterThan1000) {

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    shaker->doIt(1);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    int timeDifference = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    EXPECT_TRUE(timeDifference < 1005 && timeDifference > 995);
}

TEST_F(ShakerTest, checkSleepTimeLessThan1000) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    shaker->doIt(0.2);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    int timeDifference = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    EXPECT_TRUE(timeDifference < 250 && timeDifference > 150);

}