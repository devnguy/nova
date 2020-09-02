/*******************************************************************************
** Description:  Implementation of input validation functions to return a user 
**               input if it is of the desired data type and within the 
**               specified range.
*******************************************************************************/

#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

int getInt();
int getInt(int min);
int getInt(int min, int max);
double getDouble(int min, int max);
int validateChoice(int option1, int option2);
bool checkDigits(std::string number);
bool checkFloat(std::string number);
bool checkName(std::string);


#endif