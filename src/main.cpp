#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "../include/aux.h"

int main (int argc, char *argv[]) {

    if (argc < 2)
        std::cout << "Please provide a file name." << std::endl;

    std::string bet = argv[1];

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
        // check if each spot is in the proper range [1,80]
        // check if each spot appears only once
        // if there are more than 15 spots, validate only the first 15

    // TODO:tests
    std::cout << initialCredit << std::endl;
    std::cout << numberOfRounds << std::endl;

    for (auto i(0u); i < spots.size(); ++i) {
        std::cout << spots[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}
