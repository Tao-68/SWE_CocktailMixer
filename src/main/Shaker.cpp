//@(#) Shaker.cpp


#include "Shaker.h"

Shaker::Shaker() : InternalDevice() {
}

void Shaker::doIt(float time) {
  myTimer->sleep_in_intervals(time * 1000);
    std::cout << std::endl;
}
