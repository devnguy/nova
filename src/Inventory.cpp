/*******************************************************************************
** Description:  Implementation of Inventory class.
*******************************************************************************/

#include <iostream>
#include <iomanip>

#include "Inventory.hpp"
#include "AugmentCK.hpp"
#include "FusionCore.hpp"
#include "constants.hpp"
#include "util.hpp"


using std::cout;
using std::left;
using std::right;
using std::setw;
using std::endl;

/**
 * Default constructor initializes m_map and m_player.
 */
Inventory::Inventory() 
  : m_weapon(nullptr)
  , m_fusionCore(nullptr)
  , m_hasAugmentCK(false)
{
}


/**
 * Adds an augment pointer to m_augments. If the Augment is AugmentCK 
 * (a key), set the hasAugmentCK bool.
 */
void Inventory::addAugment(Item* augmentToAdd)
{
  if (augmentToAdd->getItemID() == AUGMENT_CK_ID) {
    setHasAugmentCK(true);
  }
  m_augments.push_back(augmentToAdd);
}

/**
 * Prints all augments currently in m_augments.
 */
void Inventory::printAugments()
{
  clearConsole();
  cout << "-----NANO-AUGMENTATION-----" << endl;

  int size = m_augments.size();

  if (size) {
    for (int i = 0; i < size; ++i) {
      cout << i + 1 << ". ";
      m_augments[i]->printInfo();
    }
  } else {
    cout << "No augments equipped." << endl << endl;
  }
}

/**
 * Prints weapon name and description.
 */
void Inventory::printWeapon()
{
  clearConsole();
  cout << "-----EQUIPPED WEAPON-----" << endl;

  if (m_weapon) {
    cout << m_weapon->getName() << endl;
    m_weapon->printInfo();
  } else {
    cout << "No weapon equipped." << endl << endl;
  }
}

/**
 * Prints Fusion Core name and description.
 */
void Inventory::printFusionCore()
{
  clearConsole();
  cout << "-----KEY ITEMS-----" << endl;

  if (m_fusionCore) {
    cout << m_fusionCore->getName() << endl;
    m_fusionCore->printInfo();
  } else {
    cout << "No Key Items." << endl << endl;
  }
}


// /**
//  * Setter functions
//  */
void Inventory::setWeapon(Item* weapon)
{
  m_weapon = weapon;
}

void Inventory::setHasAugmentCK(bool hasAugmentCK)
{
  m_hasAugmentCK = hasAugmentCK;
}

void Inventory::setFusionCore(Item* fusionCore)
{
  m_fusionCore = fusionCore;
}

/**
 * Remove currently equipped weapon. Called when a new Weapon is picked up.
 */
void Inventory::removeWeapon()
{
  m_weapon = nullptr;
}



/**
 * Getter functions
 */
Item* Inventory::getWeapon()
{
  return m_weapon;
}

bool Inventory::getHasAugmentCK()
{
  return m_hasAugmentCK;
}

Item* Inventory::getFusionCore()
{
  return m_fusionCore;
}


/**
 * Destructor frees memory.
 */
Inventory::~Inventory()
{
  for (int i = 0; i < m_augments.size(); ++i) {
    delete m_augments[i];
  }
  m_augments.clear();
}