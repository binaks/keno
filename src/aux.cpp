#include "../include/aux.h"

int strToInt (std::string inputStr_) {
    std::istringstream iss (inputStr_);
    int value;
    iss >> value >> std::ws; // ignores blank spaces

    return value;
}

float strToFloat (std::string inputStr_) {
    std::istringstream iss (inputStr_);
    float value;
    iss >> value >> std::ws; // ignores blank spaces

    return value;
}
