#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "../include/aux.h"
#include "../include/KenoBet.h"

int main (int argc, char *argv[]) {

    if (argc < 2)
        std::cout << "Please provide a file name." << std::endl;

    std::string bet = argv[1];

    std::cout << ">>> Preparing to read bet file [" << bet << "], please wait..." << std::endl;

    std::cout << std::setw(40) << std::setfill('-') << "" << std::endl;

    float initialCredit = 0;
    int numberOfRounds = 0;
    std::vector<int> spots; // numbers the player picked
    std::string spot = ""; // each number, but in string format

    std::string line;
    std::ifstream ifs;

    ifs.open(bet);

    // read the file to get inicialCredit
    getline (ifs, line);
    initialCredit = strToFloat (line);

    // read the file to get numberOfRounds
    getline (ifs, line);
    numberOfRounds = strToInt (line);

    // read the file to get spots
    getline (ifs, line);

    for (auto i(0u); i < line.size(); ++i) {
        if (line[i] != ' ') {
            spot += line[i];
        } else if (spot != "") {
            spots.push_back(strToInt (spot));
            spot = "";
        }

    }

    spots.push_back(strToInt (spot));

    ifs.close();

    // validate spots
    for (auto i(0u); i < spots.size(); ++i) {
        // check if each spot is in the proper range [1,80]
        if (spots[i] < 1 or spots[i] > 80) {
            spots.erase(spots.begin()+i);
            i--;
        }
        // check if each spot appears only once
        for (auto j(0u); j < i; ++j) {
            if (spots[i] == spots[j]) {
                spots.erase(spots.begin() + i);
                i--;
            }
        }
        // if there are more than 15 spots, validate only the first 15
        if (i > 14) {
            spots.erase(spots.begin()+i);
            i--;
        }
    }

    std::cout << ">>> Bet successfully read!" << std::endl;
    std::cout << "    You are going to wage a total of $" << initialCredit << " dollars." << std::endl;
    std::cout << "    Going for a total of " << numberOfRounds << " rounds, waging $" << initialCredit / numberOfRounds << " per round." << std::endl;

    std::cout << std::endl;

    std::cout << "    Your bet has " << spots.size() << " numbers. They are: [ ";

    for (auto i(0u); i < spots.size(); ++i) {
        std::cout << spots[i] << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
