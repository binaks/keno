#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

int main (int argc, char *argv[]) {

    if (argc < 2)
        std::cout << "Please provide a file name." << std::endl;

    std::string initialCredit;
    std::string numberOfRounds;
    std::vector<std::string> spots; // numbers the player picked

    // read the file to get inicialCredit
    // read the file to get numberOfRounds
    // read the file to get spots

    // validate spots
        // check if each spot is in the proper range [1,80]
        // check if each spot appears only once
        // if there are more than 15 spots, validate only the first 15

    return 0;
}
