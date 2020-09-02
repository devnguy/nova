/*******************************************************************************
** Description:  Implementation of Wrench derived class from Weapon.
*******************************************************************************/

#include <iostream>
#include <string>

#include "Wrench.hpp"
#include "Weapon.hpp"
#include "util.hpp"
#include "constants.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor with no ID.
 */
Wrench::Wrench() 
  : Weapon(WRENCH_ID, WRENCH_NAME, 0, WRENCH_ATTACK_MOD, 0, 0, 0, 0)
{
}

/**
 * Overrides inherited virtual function to display info specific to 
 * Wrench Item.
 */
void Wrench::printInfo()
{
  cout << "A simple wrench made of titanium. It's better than nothing." << endl;
  cout << "Attack: +" << getModifierAttack() << endl << endl;
}


/**
 * Overrides inherited virtual function to print a message when the Item 
 * is picked up.
 */
void Wrench::handlePickUpMessage()
{
  cout << "Found a " << getName() << ". [Equipping weapon . . .]"
    << endl << endl;
  pressEnterToContinue();
  printInfo();
  pressEnterToContinue();
}


/**
 * Destructor
 */
Wrench::~Wrench()
{
}
