#ifndef AUX_H
#define AUX_H

#include <sstream>
#include <string>
#include <vector>

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
bool member (const std::vector<int> & spots, const int & spot);

#endif
