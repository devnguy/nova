/*******************************************************************************
** Description:  Implementation of FusionCore derived class from Item.
*******************************************************************************/

#include <iostream>
#include <string>

#include "FusionCore.hpp"
#include "Item.hpp"
#include "util.hpp"
#include "constants.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor.
 */
FusionCore::FusionCore() 
  : Item(FUSION_CORE_ID, FUSION_CORE_NAME, 0, 0, 0, 0, 0, 0)
{
}

/**
 * Overrides inherited virtual function to display info specific to 
 * FusionCore Item.
 */
void FusionCore::printInfo()
{
  cout << "An energy source used to power the Reactor of the Imperius. " << endl;
  cout << "Place in the Reactor to restore main power. " << endl << endl;
}

/**
 * Overrides inherited virtual function to print a message when the Item 
 * is picked up.
 */
void FusionCore::handlePickUpMessage()
{
  cout << "Found the " << getName() << endl << endl;
  pressEnterToContinue();
  printInfo();
  pressEnterToContinue();
}

/**
 * Destructor
 */
FusionCore::~FusionCore()
{
}
