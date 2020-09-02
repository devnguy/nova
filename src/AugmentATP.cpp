/*******************************************************************************
** Description:  Implementation of AugmentATP derived class from Augment.
*******************************************************************************/

#include <iostream>
#include <string>

#include "AugmentAtp.hpp"
#include "Augment.hpp"
#include "util.hpp"
#include "constants.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor with no ID.
 */
AugmentAtp::AugmentAtp() 
  : Augment(AUGMENT_ATP_ID, AUGMENT_ATP_NAME, 0
  , AUGMENT_ATP_ATK, AUGMENT_ATP_DEF, 0, AUGMENT_ATP_INIT, 0)
{
}

/**
 * Overrides inherited virtual function to display info specific to 
 * AugmentAtp Item.
 */
void AugmentAtp::printInfo()
{
  cout << "Name: " << getName() << endl;
  cout << "Description: A muscle enhancement Augment that allows " << endl;
  cout << " you to expend less energy." << endl;
  cout << "Attack: +" << getModifierAttack()
  << ", Defense: +" << getModifierDefense() 
  << ", Initiative: +" << getModifierInitiative() << endl << endl;
}

/**
 * Overrides inherited virtual function to print a message when the Item 
 * is picked up.
 */
void AugmentAtp::handlePickUpMessage()
{
  cout << "Found an " << getName() << ". [Installing Nano-Augmentation . . .]"
    << endl << endl;
  pressEnterToContinue();
  cout << "Your muscles spasm as you lose control over them and fall to " << endl;
  cout << "the ground. After briefly struggling to stand, you feel " << endl;
  cout << "physically stronger, yet faster and lighter than ever. " 
    << endl << endl;
  pressEnterToContinue();
  printInfo();
  pressEnterToContinue();
}

/**
 * Destructor
 */
AugmentAtp::~AugmentAtp()
{
}
