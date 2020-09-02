/*******************************************************************************
** Description:  Implementation of Item base class.
*******************************************************************************/

#include <iostream>
#include <string>

#include "Item.hpp"
#include "constants.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor.
 */
Item::Item() 
{
}

/**
 * Overloaded constructor initializes data members.
 */
Item::Item(int itemID, std::string name, int modifierHealth
  , int modifierAttack, int modiferDefense, int modifierArmor
  , int modifierInitiative, int modifierCrit
  ) 
  : m_itemID(itemID)
  , m_name(name)
  , m_modifierHealth(modifierHealth)
  , m_modifierAttack(modifierAttack)
  , m_modifierDefense(modiferDefense)
  , m_modifierArmor(modifierArmor)
  , m_modifierInitiative(modifierInitiative)
  , m_modifierCrit(modifierCrit)
  , m_modifierDice(0)
{
}

/**
 * Overloaded constructor initializes modifierDice
 */
Item::Item(int itemID, std::string name, int modifierHealth
  , int modifierAttack, int modiferDefense, int modifierArmor
  , int modifierInitiative, int modifierCrit, int modifierDice
  ) 
  : m_itemID(itemID)
  , m_name(name)
  , m_modifierHealth(modifierHealth)
  , m_modifierAttack(modifierAttack)
  , m_modifierDefense(modiferDefense)
  , m_modifierArmor(modifierArmor)
  , m_modifierInitiative(modifierInitiative)
  , m_modifierCrit(modifierCrit)
  , m_modifierDice(modifierDice)
{
}

/**
 * Virtual function to display the Item info. Abstract classes will 
 * not have a description.
 */
void Item::printInfo()
{
}

/**
 * Virtual function to print a message the Player picks up the Item.
 * Abstract classes will not have a pick up message.
 */
void Item::handlePickUpMessage()
{
}

/**
 * Setter functions.
 */
void Item::setItemID(int itemID)
{
  m_itemID = itemID;
}

void Item::setName(std::string name)
{
  m_name = name;
}

void Item::setDescritpion(std::string description)
{
  m_description = description;
}

void Item::setModifierHealth(int modifierHealth)
{
  m_modifierHealth = modifierHealth;
}

void Item::setModifierAttack(int modifierAttack)
{
  m_modifierAttack = modifierAttack;
}

void Item::setModifierDefense(int modifierDefense)
{
  m_modifierDefense = modifierDefense;
}

void Item::setModifierArmor(int modifierArmor)
{
  m_modifierArmor = modifierArmor;
}

void Item::setModifierInitiative(int modifierInitiative)
{
  m_modifierInitiative = modifierInitiative;
}

void Item::setModifierCrit(int modifierCrit)
{
  m_modifierCrit = modifierCrit;
}

void Item::setModifierDice(int modifierDice)
{
  m_modifierDice = modifierDice;
}


/**
 * Getter functions.
 */
int Item::getItemID() 
{
  return m_itemID;
}

std::string Item::getName() 
{
  return m_name;
}

std::string Item::getDescription() 
{
  return m_description;
}

int Item::getModifierHealth() 
{
  return m_modifierHealth;
}

int Item::getModifierAttack() 
{
  return m_modifierAttack;
}

int Item::getModifierDefense() 
{
  return m_modifierDefense;
}

int Item::getModifierArmor() 
{
  return m_modifierArmor;
}

int Item::getModifierInitiative() 
{
  return m_modifierInitiative;
}

int Item::getModifierCrit() 
{
  return m_modifierCrit;
}

int Item::getModifierDice() 
{
  return m_modifierDice;
}



/**
 * Destructor.
 */
Item::~Item()
{
  
}