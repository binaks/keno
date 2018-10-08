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
 * This function returns the payout scale based on the number of spots in a bet.
 * @param number of spots
 * @return a vector with the corresponding payout scale
 */
std::vector<float> payout (int n_spots);

/**!
 * This function randomly generates hits and returns them in a vector.
 * @return a vector with the hits
 */
std::vector<unsigned short int> generateHits();

/**!
 * This function returns the intersection between two vectors
 * @param spots the vector with the spots
 * @param hits the vector with the hits
 * @return a vector with their intersection
 */
std::vector<unsigned short int> intersect (std::vector <unsigned short int> spots, std::vector <unsigned short int> hits);

#endif
