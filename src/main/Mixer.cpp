#include "Mixer.h"

Mixer::Mixer() : InternalDevice() {

}

bool Mixer::doIt(float time) {
  myTimer->sleep_in_intervals(time * 1000);
    std::cout << std::endl;

    return true;
}
