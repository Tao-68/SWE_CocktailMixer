#include "gtest/gtest.h"
#include <chrono>

#define protected public
#define private public
#include "Timer.h"
#undef protected
#undef private

#include <sstream>

class TimerTest: public ::testing::Test {
protected:
    Timer* timer;
    std::basic_streambuf<char>* orig_cout;
    std::stringstream test_cout;

    virtual void SetUp() {
        std::cout << "Start of " << "TimerTest" << std::endl << std::flush;

        timer = new Timer();
        timer->booster = 1;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
        std::cout.rdbuf(orig_cout);
        delete timer;
        std::cout << "End of " << "TimerTest" << std::endl << std::flush;
    }

};

TEST_F(TimerTest, setTurbo){
    timer->set_Turbo(10);
    EXPECT_EQ(10, timer->booster);
}

TEST_F(TimerTest, getInstance){
    //EXPECT_TRUE(timer->theTimer == NULL);
    timer->getInstance();
    EXPECT_FALSE(timer->theTimer == nullptr);
}

TEST_F(TimerTest, checkSleepInIntervalTimeGreaterThan1000) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    timer->sleep_in_intervals(1000);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    int timeDifference = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    EXPECT_TRUE(timeDifference < 1100 && timeDifference > 900);
}

TEST_F(TimerTest, checkSleepInIntervalTimeLessThan1000) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    timer->sleep_in_intervals(200);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    int timeDifference = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    EXPECT_TRUE(timeDifference < 250 && timeDifference > 150);
}

TEST_F(TimerTest, checkSleepTime) {
    timer->booster = 10;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    timer->sleep_in_intervals(2000);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    int timeDifference = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    EXPECT_TRUE(timeDifference < 200 && timeDifference > 150);
}