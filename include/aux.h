#ifndef AUX_H
#define AUX_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

/**!
 * This function converts a string of a number to an actual integer.
 * @param inputStr_ string of the number
 * @return the string number's corresponding integer
 */
int strToInt (std::string inputStr_);

/**!
 * This function converts a string of a number to a float.
 * @param inputStr_ string of the number
 * @return the string number's corresponding float
 */
float strToFloat (std::string inputStr_); 

/**!
 * This function verifies if a spot is a member of the spots vector.
 * @param spots the spots vector
 * @param spot the spot we want to verify if is a member of spots
 * @return true if the spot is in the spots vector, false otherwise
 */
bool member (const std::vector<unsigned short int> & spots, const int & spot);

/**!
 * This function prints the payout table accordingly to how many spots were bet.
 * @param n_spots the number of spots that were bet
 */
void printPayoutTable (unsigned short int n_spots);


/**!

 */
int payout (int n_spots); 

/**!

 */
std::vector<unsigned short int> generateHits();

#endif
