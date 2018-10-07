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
    std::vector<std::string> data;

    std::string initialCredit;
    std::string numberOfRounds;
    std::vector<std::string> spots; // numbers the player picked

    std::string line;
    std::ifstream ifs;

    ifs.open(bet);

    // read the file to get data
    while (getline (ifs, line)) {
        data.push_back(line);
    }

    // read the file to get inicialCredit
    // read the file to get numberOfRounds
    // read the file to get spots

    // validate spots
        // check if each spot is in the proper range [1,80]
        // check if each spot appears only once
        // if there are more than 15 spots, validate only the first 15

    // TODO:tests
    for (auto i(0u); i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
        std::cout << std::endl;


    return 0;
}
