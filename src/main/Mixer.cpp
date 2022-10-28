//@(#) Mixer.cpp


#include "Mixer.h"

Mixer::Mixer() : InternalDevice() {

}

void Mixer::doIt(float time) {
  myTimer->sleep_in_intervals(time * 1000);
    std::cout << std::endl;
}
