/*******************************************************************************
** Description:  Implementation of Weapon derived class from Item.
*******************************************************************************/

#include <string>

#include "Weapon.hpp"
#include "constants.hpp"


/**
 * Constructor.
 */
Weapon::Weapon
  ( int itemID, std::string name, int modifierHealth
  , int modifierAttack, int modiferDefense, int modifierArmor
  , int modifierInitiative, int modifierCrit
  ) 
  : Item(itemID, name, modifierHealth, modifierAttack, modiferDefense
  , modifierArmor, modifierInitiative, modifierCrit)
{
}

/**
 * Overloaded constructor initializes modifierDice.
 */
Weapon::Weapon
  ( int itemID, std::string name, int modifierHealth
  , int modifierAttack, int modiferDefense, int modifierArmor
  , int modifierInitiative, int modifierCrit, int modifierDice
  ) 
  : Item(itemID, name, modifierHealth, modifierAttack, modiferDefense
  , modifierArmor, modifierInitiative, modifierCrit, modifierDice)
{
}

/**
 * Destructor
 */
Weapon::~Weapon()
{
}
