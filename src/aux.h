#include "../include/aux.h"

int strToInt (string inputStr_) {
    istringstream iss (inputStr_);
    int value;
    iss >> value >> std::ws; // ignores blank spaces

    return value;
}
