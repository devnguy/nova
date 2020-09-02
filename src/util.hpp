/*******************************************************************************
** Description:  Implementation of utility functions to generate a pseudorandom 
**               result and a function to clear the console.
*******************************************************************************/

#ifndef UTIL_HPP
#define UTIL_HPP

int generateRandInt(int min, int max);
double generateRandDouble(int min, int max);
void clearConsole();
int rollDice(int sides, int numberOfDice = 1);
void pressEnterToContinue();

#endif