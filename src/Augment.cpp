/*******************************************************************************
** Description:  Implementation of Augment base class.
*******************************************************************************/

#include <iostream>
#include <string>

#include "Item.hpp"
#include "Augment.hpp"
#include "constants.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor with no ID.
 */
Augment::Augment() 
{
}

/**
 * Overloaded constructor initializes spaceID.
 */
Augment::Augment
  ( int itemID, std::string name, int modifierHealth
  , int modifierAttack, int modiferDefense, int modifierArmor
  , int modifierInitiative, int modifierCrit
  ) 
  : Item(itemID, name, modifierHealth, modifierAttack
  , modiferDefense, modifierArmor, modifierInitiative, modifierCrit)
{
}


/**
 * Setter functions.
 */



/**
 * Getter functions.
 */




/**
 * Destructor.
 */
Augment::~Augment()
{
}