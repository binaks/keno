// Authors: Bianca Rodrigues Cesarino & Gustavo Batista de Araújo Gorgônio

#include "../include/aux.h"
#include <random>
#include <iterator>

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

std::vector<float> payout (int n_spots) {
    std::vector<float> payouts;
    if (n_spots == 0)
        return payouts = {0};
    else if (n_spots == 1)
        return payouts = {0,1};
    else if (n_spots == 2)
        return payouts = {0,1,9};
    else if (n_spots == 3)
        return payouts = {0,1,2,16};
    else if (n_spots == 4)
        return payouts = {0,0.5,2,6,12};
    else if (n_spots == 5)
        return payouts = {0,0.5,1,3,15,50};
    else if (n_spots == 6)
        return payouts = {0,0.5,1,2,3,30,75};
    else if (n_spots == 7)
        return payouts = {0,0.5,0.5,2,6,12,36,100};
    else if (n_spots == 8)
        return payouts = {0,0.5,0.5,1,3,6,19,90,720};
    else if (n_spots == 9)
        return payouts = {0,0.5,0.5,1,2,4,8,20,80,1200};
    else if (n_spots == 10)
        return payouts = {0,0,0.5,1,2,3,5,10,30,600,1800};
    else if (n_spots == 11)
        return payouts = {0,0,0.5,1,1,2,6,15,25,180,1000,3000};
    else if (n_spots == 12)
        return payouts = {0,0,0,0.5,1,2,4,24,72,250,500,2000,4000};
    else if (n_spots == 13)
        return payouts = {0,0,0,0.5,0.5,3,4,5,20,80,240,500,3000,6000};
    else if (n_spots == 14)
        return payouts = {0,0,0,0.5,0.5,2,3,5,12,50,150,500,1000,2000,7500};
    else
        return payouts = {0,0,0,0.5,0.5,1,2,5,15,50,150,300,600,1200,2500, 10000};
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

    std::vector<float> payouts = payout(n_spots);

    for (auto i(0); i <= n_spots; ++i) {
        if (n_spots >= i) {
            std::cout << std::setw(9) << std::setfill(' ') << "";
            std::cout << std::setw(8) << std::left << i;
            std::cout << "| ";
            std::cout << payouts[i];
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

std::vector<unsigned short int> generateHits() {
    std::vector<unsigned short int> hits;

    for (auto i(0); i < 20; ++i) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1,80);

        unsigned short int hit = dist(gen);

        if (not member (hits, hit))
            hits.push_back(hit);
        else i--;
    }

    sort(hits);

    return hits;
}

std::vector<unsigned short int> intersect (std::vector<unsigned short int> spots, std::vector<unsigned short int> hits) {
    std::vector<unsigned short int> intersect;
    
    for (auto i(0u); i < spots.size(); ++i) {
        if (member (hits, spots[i])) {
            intersect.push_back(spots[i]);
        }
    }
    
    sort(intersect);

    return intersect;
}

void sort (std::vector<unsigned short int> &v) {
    int n = v.size() - 1;
    isort (v, n);
}

void isort (std::vector<unsigned short int> &v, int n) {
	for (auto i = 1; i <= n; i++) {
		auto j = i - 1;
		auto key = v[i];

		while (j >= 0 && v[j] > key) {
			swap (v[j+1], v[j]);
			j--;
		}

		key = v[i+1];
    }
}

inline void swap (unsigned short int & x, unsigned short int & y) {
    unsigned short int tmp = x;
    x = y;
    y = tmp;
}
