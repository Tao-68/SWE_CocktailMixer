#include "gtest/gtest.h"
#include <chrono>

#define protected public
#define private public
#include "Mixer.h"
#undef protected
#undef private
#include <sstream>

class MixerTest: public ::testing::Test {
protected:
    Mixer* mixer;
    std::basic_streambuf<char>* orig_cout;
    std::stringstream test_cout;

    virtual void SetUp() {
        std::cout << "Start of " << "MixerTest" << std::endl << std::flush;

        mixer = new Mixer();
        mixer->myTimer->booster = 1;
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());

    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
        std::cout.rdbuf(orig_cout);
        delete mixer;
        std::cout << "End of " << "MixerTest" << std::endl << std::flush;

    }

};

TEST_F(MixerTest, checkSleepTimeGreaterThan1000) {

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    mixer->doIt(1);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    int timeDifference = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    EXPECT_TRUE(timeDifference < 1005 && timeDifference > 995);
}

TEST_F(MixerTest, checkSleepTimeSmallerThan1000) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    mixer->doIt(0.2);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    int timeDifference = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    EXPECT_TRUE(timeDifference < 205 && timeDifference > 195);

}