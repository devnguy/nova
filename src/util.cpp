/*******************************************************************************
** Description:  Utility functions include generating random ints, doubles, 
**               rolling dice, and a function to clear the console.
*******************************************************************************/

#include <iostream>
#include <random>
#include <string>
#include <limits>

#include "util.hpp"

using std::string;


// Seed the engine
std::random_device rd;

/**
 * Generates and returns a random double within the specified min and max
 */
int generateRandInt(int min, int max) {
  int randomInt;
  std::mt19937 rng(rd());
  std::uniform_int_distribution<int> distribution(min, max);

  randomInt = distribution(rng);
  return randomInt;
}

/**
 * Generates and returns a random double within the specified min and max
 */
double generateRandDouble(int min, int max) {
  double randomDouble;
  std::mt19937 rng(rd());
  std::uniform_real_distribution<double> distribution(min, max);

  randomDouble = distribution(rng);
  return randomDouble;
}


/**
 * Clears the console to increase readability of output that follows.
 */
void clearConsole()
{
  std::cout << string(100, '\n');
}

/**
 * Simulates a dice roll given the number of sides the dice have and 
 * (optionally) the numberOfDice to roll. Default numberOfDice to roll 
 * is 1.
 */
int rollDice(int sides, int numberOfDice)
{
  int totalRoll = 0;

  for (int i = 0; i < numberOfDice; ++i) {
    totalRoll += generateRandInt(1, sides);
  }
  return totalRoll;
}


/**
 * Prompts user to press the Enter key to continue.
 */
void pressEnterToContinue() 
{
  std::cout << "Press ENTER to continue... ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << std::endl;
}