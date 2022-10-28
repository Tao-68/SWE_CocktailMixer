//@(#) Masher.cpp


#include "Masher.h"

Masher::Masher() : InternalDevice() {
}

void Masher::doIt(float time) {
  myTimer->sleep_in_intervals(time * 1000);
    std::cout << std::endl;
}
