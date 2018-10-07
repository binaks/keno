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

int payout (int n_spots) {
    if (n_spots == 0) return 0;
    if (n_spots == 1) return 1; 
    if (n_spots == 2) return 2;
    if (n_spots == 3) return 16;
    if (n_spots == 4) return 16;
    else return 16;
}

void printPayoutTable (unsigned short int n_spots) {
    std::cout << std::setw(9) << std::setfill(' ') << "";
    std::cout << std::setw(9) << std::setfill('-') << "+";
    std::cout << std::setw(9) << std::setfill('-') << "";
    std::cout << std::endl;

    std::cout << std::setw(9) << std::setfill(' ') << "";
    std::cout << "Hits    ";
    std::cout << "|";
    std::cout << " Payout ";
    std::cout << std::endl;

    std::cout << std::setw(9) << std::setfill(' ') << "";
    std::cout << std::setw(9) << std::setfill('-') << "+";
    std::cout << std::setw(9) << std::setfill('-') << "";
    std::cout << std::endl;

    for (auto i(0); i <= n_spots; ++i) {
        if (n_spots >= i) {
            std::cout << std::setw(9) << std::setfill(' ') << "";
            std::cout << std::setw(8) << std::left << i;
            std::cout << "| ";
            std::cout << payout(i);
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << std::setw(9) << std::setfill(' ') << "";
    std::cout << std::setw(40) << std::setfill('-') << "" << std::endl;
}

//std::vector<unsigned short int> generateHits() {
//}
