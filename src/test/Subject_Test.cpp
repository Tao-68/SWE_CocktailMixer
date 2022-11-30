#include <limits.h>
#include <algorithm>
#include "gtest/gtest.h"

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#define protected public
#define private public
#include "Subject.h"
#include "Drainer.h"
#include "Dispenser.h"
#undef protected
#undef private

class SubjectTest : public ::testing::Test {
protected:
    Subject* subject;
    Observer* drainer;
    Observer* dispenser;
    Waage* scale;
    std::basic_streambuf<char>* orig_cout;
    std::stringstream test_cout;

    virtual void SetUp() {
        std::cout << "Start of " << "SubjectTest" << std::endl << std::flush;

        subject = new Subject();
        scale = new Waage(0,0);
        drainer = new Drainer(25, 1000, scale);
        dispenser = new Dispenser(20 ,1000, "Eis", scale);
        // you never know what the constructor is really doing
        // so make the list empty and fill it yourself!

        subject->observers.clear();
        orig_cout = std::cout.rdbuf(test_cout.rdbuf());

    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
        std::cout.rdbuf(orig_cout);
        delete subject;
        std::cout << "End of " << "SubjectTest" << std::endl << std::flush;
    }
};

TEST_F(SubjectTest, attachObserver){
    subject->attach(drainer);
    subject->attach(dispenser);
    int noOfObservers = subject->observers.size();
    EXPECT_EQ(2, noOfObservers);
}

TEST_F(SubjectTest, detachAvailableObserver){
    subject->attach(drainer);
    subject->attach(dispenser);

    subject->detach(drainer);
    int noOfObservers = subject->observers.size();
    EXPECT_EQ(1, noOfObservers);

    EXPECT_FALSE(std::find(subject->observers.begin(), subject->observers.end(), drainer) != subject->observers.end());
}