/*******************************************************************************
** Description:  Implementation of WarpBlade derived class from Weapon.
*******************************************************************************/

#include <iostream>
#include <string>

#include "WarpBlade.hpp"
#include "Weapon.hpp"
#include "util.hpp"
#include "constants.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor.
 */
WarpBlade::WarpBlade() 
  : Weapon(WARP_BLADE_ID, WARP_BLADE_NAME, 0
  , WARP_BLADE_ATTACK_MOD, 0, 0, 0, 0, WARP_BLADE_DICE_MOD)
{
}

/**
 * Overrides inherited virtual function to display info specific to 
 * WarpBlade Item.
 */
void WarpBlade::printInfo()
{
  cout << "A long blade made of Nihilan technology. Space and time " << endl;
  cout << "itself seem to bend around the wielder." << endl;
  cout << "Attack: +" << getModifierAttack();
  cout << ", Attacks/turn: +" << getModifierDice() << endl << endl;
}

/**
 * Overrides inherited virtual function to print a message when the Item 
 * is picked up.
 */
void WarpBlade::handlePickUpMessage()
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
WarpBlade::~WarpBlade()
{
}
