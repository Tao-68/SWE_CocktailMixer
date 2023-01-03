#include "Shaker.h"

Shaker::Shaker() : InternalDevice() {
}

bool Shaker::doIt(float time) {
  myTimer->sleep_in_intervals(time * 1000);
    std::cout << std::endl;

    return true;
}
