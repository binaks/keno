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

    std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;

    float initialCredit = 0;
    int numberOfRounds = 0;
    std::vector<unsigned short int> spots; // numbers the player picked
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

    // sorts spots
    sort(spots);

    // credits for round
    float credits4round = initialCredit / numberOfRounds;

    // attributing values to the kenobet
    KenoBet kenobet;
    kenobet.set_wage(initialCredit);
    
    for (auto i(0u); i < spots.size(); ++i) {
        kenobet.add_number(spots[i]);
    }

    // starting to play
    std::cout << ">>> Bet successfully read!" << std::endl;
    std::cout << "    You are going to wage a total of $" << kenobet.get_wage() << " dollars." << std::endl;
    std::cout << "    Going for a total of " << numberOfRounds << " rounds, waging $" << credits4round << " per round." << std::endl;

    std::cout << std::endl;

    std::cout << "    Your bet has " << kenobet.size() << " numbers. They are: [ ";

    for (auto i(0u); i < kenobet.size(); ++i) {
        std::cout << kenobet.get_spots()[i] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;

    // print payout table
    printPayoutTable (kenobet.get_spots().size());

    // play rounds
    for (auto i(0); i < numberOfRounds; ++i) {
        std::cout << std::setw(9) << std::setfill(' ') << "";
        std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;

        std::cout << std::setw(9) << std::setfill(' ') << "";
        std::cout << "This is round #" << i + 1 << " of " << numberOfRounds << ", and your wage is $" << credits4round << ". Good luck!" << std::endl;

        std::vector<unsigned short int> hits = generateHits();

        kenobet.set_wage(kenobet.get_wage() - credits4round);

        // print hits
        std::cout << std::setw(9) << std::setfill(' ') << "";
        std::cout << "The hits are: [ ";
        for (auto j(0u); j < hits.size(); ++j) {
            std::cout << hits[j] << " ";
        }
        std::cout << "]" << std::endl;
        
        std::cout << std::endl;

        std::cout << std::setw(9) << std::setfill(' ') << "";
        std::cout << "You hit the following number(s) [ ";

        std::vector<unsigned short int> result = intersect(hits, kenobet.get_spots());

        for (auto j(0u); j < result.size(); ++j) {
            std::cout << result[j] << " ";
        }

        std::cout << "], a total of " << result.size() << " out of " << kenobet.get_spots().size() << "." << std::endl;

        std::cout << std::setw(9) << std::setfill(' ') << "";

        std::cout << "Payout rate is " << payout(kenobet.get_spots().size())[result.size()] << ", thus you came out with: $" << credits4round * payout(kenobet.get_spots().size())[result.size()] << "." << std::endl;

        kenobet.set_wage(kenobet.get_wage() + (credits4round * payout(kenobet.get_spots().size())[result.size()]));

        std::cout << std::setw(9) << std::setfill(' ') << "";
        std::cout << "Your net balance so far is: $" << kenobet.get_wage() << " dollars." << std::endl;

    }

    // end of rounds
    std::cout << ">>> End of rounds!" << std::endl;
    std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;

    std::cout << std::endl;

    // summary
    std::cout << "===== SUMMARY =====" << std::endl;
    std::cout << ">>> You spent in this game a total of $" << initialCredit << " dollars." << std::endl;

    if (kenobet.get_wage() > initialCredit)
        std::cout << ">>> Hooray, you won $" << kenobet.get_wage() - initialCredit << " dollars. See you next time! ;-)" << std::endl;
    else if (kenobet.get_wage() < initialCredit)
        std::cout << ">>> Shoot, you lost $" << initialCredit - kenobet.get_wage() << " dollars. Better luck next time :-(" << std::endl;
    else
        std::cout << ">>> You lost the same amount of money you won ¯\\_(ツ)_/¯" << std::endl;
    
    std::cout << "You are leaving the Keno table with $" << kenobet.get_wage() << " dollars." << std::endl;

    return 0;
}
