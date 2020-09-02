/*******************************************************************************
** Description:  Implementation of AugmentOPTIK derived class from Augment.
*******************************************************************************/

#include <iostream>
#include <string>

#include "AugmentOptik.hpp"
#include "Augment.hpp"
#include "util.hpp"
#include "constants.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor with no ID.
 */
AugmentOptik::AugmentOptik() 
  : Augment(AUGMENT_OPTIK_ID, AUGMENT_OPTIK_NAME, 0, 0
  , 0, 0, 0, AUGMENT_OPTIK_CRIT)
{
}

/**
 * Overrides inherited virtual function to display info specific to 
 * AugmentOptik Item.
 */
void AugmentOptik::printInfo()
{
  cout << "Name: " << getName() << endl;
  cout << "Description: Enhances your vision and allows you to " << endl;
  cout << " more easily spot enemy weak points." << endl;
  cout << "Crit chance: +" << getModifierCrit() << "%" << endl << endl;
}

/**
 * Overrides inherited virtual function to print a message when the Item 
 * is picked up.
 */
void AugmentOptik::handlePickUpMessage()
{
  cout << "Found an " << getName() << ". [Installing Nano-Augmentation . . .]"
    << endl << endl;
  pressEnterToContinue();
  cout << "Your pupils begin to dilate. You feel your eyes twitching " << endl;
  cout << "and burning until your body forces them shut. As the pain " << endl;
  cout << "subsides, you open your eyes and see the environment " << endl; 
  cout << "around you in a higher resolution and more detail." << endl << endl;
  pressEnterToContinue();
  printInfo();
  pressEnterToContinue();
}

/**
 * Destructor
 */
AugmentOptik::~AugmentOptik()
{
}
