/*******************************************************************************
** Description:  Implementation of FissionDagger derived class from Weapon.
*******************************************************************************/

#include <iostream>
#include <string>

#include "FissionDagger.hpp"
#include "Weapon.hpp"
#include "util.hpp"
#include "constants.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor.
 */
FissionDagger::FissionDagger() 
  : Weapon(FISSION_DAGGER_ID, FISSION_DAGGER_NAME, 0
  , FISSION_DAGGER_ATTACK_MOD, 0, 0, 0, 0, FISSION_DAGGER_DICE_MOD)
{
}

/**
 * Overrides inherited virtual function to display info specific to 
 * FissionDagger Item.
 */
void FissionDagger::printInfo()
{
  cout << "A dagger capable of cutting through almost anything." << endl;
  cout << "Attack: +" << getModifierAttack();
  cout << ", Attacks/turn: +" << getModifierDice() << endl << endl;
}


/**
 * Overrides inherited virtual function to print a message when the Item 
 * is picked up.
 */
void FissionDagger::handlePickUpMessage()
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
FissionDagger::~FissionDagger()
{
}
