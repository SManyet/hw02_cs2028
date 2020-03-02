#include "Wheel.h"
#include <ctime>
#include <cstdlib>

Wheel::Wheel() {
    maxVal = 10;
}

Wheel::Wheel(int mV) {
    maxVal = mV;
}

int Wheel::spin() {
    srand(time(0));
    return ((rand() % maxVal) + 1);
}

int Wheel::getMaxVal() {
    return maxVal;
}
