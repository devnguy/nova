/*******************************************************************************
** Description:  Implementation of AugmentSDA derived class from Augment.
*******************************************************************************/

#include <iostream>
#include <string>

#include "AugmentSda.hpp"
#include "Augment.hpp"
#include "util.hpp"
#include "constants.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor with no ID.
 */
AugmentSda::AugmentSda() 
  : Augment(AUGMENT_SDA_ID, AUGMENT_SDA_NAME, 0, 0
  , AUGMENT_SDA_DEF, AUGMENT_SDA_ARMOR, 0, 0)
{
}

/**
 * Overrides inherited virtual function to display info specific to 
 * AugmentSda Item.
 */
void AugmentSda::printInfo()
{
  cout << "Name: " << getName() << endl;
  cout << "Description: Subdermal titanium plating reinforces your " << endl;
  cout << " skin." << endl;
  cout << "Defense: +" << getModifierDefense()
  << ", Armor: +" << getModifierArmor() << endl << endl;
}

/**
 * Overrides inherited virtual function to print a message when the Item 
 * is picked up.
 */
void AugmentSda::handlePickUpMessage()
{
  cout << "Found an " << getName() << ". [Installing Nano-Augmentation . . .]"
    << endl << endl;
  pressEnterToContinue();
  cout << "You feel vibrations and movement under your skin as the " << endl;
  cout << "Augment is installed. Tapping your knuckle against your " << endl; 
  cout << "forearm makes a metallic clanking sound that echoes " << endl;
  cout << "throughout the deserted halls." << endl << endl;
  pressEnterToContinue();
  printInfo();
  pressEnterToContinue();
}

/**
 * Destructor
 */
AugmentSda::~AugmentSda()
{
}
