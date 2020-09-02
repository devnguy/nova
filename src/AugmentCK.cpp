/*******************************************************************************
** Description:  Implementation of AugmentCK derived class from Augment.
*******************************************************************************/

#include <iostream>
#include <string>

#include "AugmentCK.hpp"
#include "Augment.hpp"
#include "constants.hpp"
#include "util.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor with no ID.
 */
AugmentCK::AugmentCK() 
  : Augment(AUGMENT_CK_ID, AUGMENT_CK_NAME, 0, 0, 0, 0, 0, 0)
{
}


/**
 * Overrides inherited virtual function to display info specific to 
 * AugmentCK Item.
 */
void AugmentCK::printInfo()
{
  cout << "Name: " << getName() << endl;
  cout << "Description: A 65,536 bit authentication key has been " << endl;
  cout << " embedded in your memory. You can override security and " << endl;
  cout << " open the door to the main deck." << endl << endl;
}


/**
 * Overrides inherited virtual function to print a message when the Item 
 * is picked up.
 */
void AugmentCK::handlePickUpMessage()
{
  cout << "Found a " << getName() << ". [Installing Nano-Augmentation . . .]"
    << endl << endl;
  pressEnterToContinue();
  cout << "A 65,536-bit cryptographic authentication key has been " << endl;
  cout << "embedded in your memory." << endl << endl;
  pressEnterToContinue();
  cout << "You can override security and open the door to the " << endl;
  cout << "main deck." << endl << endl;
  pressEnterToContinue();
}


/**
 * Destructor
 */
AugmentCK::~AugmentCK()
{
}