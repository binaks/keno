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

bool member (const std::vector<unsigned short int> & spots, const int & spot) {
    for (auto i(0u); i < spots.size(); ++i) {
        if (spots[i] == spot)
            return true;
    }
    
    return false;
}
