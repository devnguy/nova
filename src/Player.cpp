/*******************************************************************************
** Description:  Player class represents the player.
*******************************************************************************/

#include <iostream>
#include <vector>

#include "Player.hpp"
#include "Unit.hpp"
#include "Inventory.hpp"
#include "Item.hpp"
#include "Augment.hpp"
#include "Weapon.hpp"
#include "FusionCore.hpp"
#include "constants.hpp"
#include "util.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor calls base Character class constructor to initialize 
 * inherited data members.
 */
Player::Player() 
  : Unit(P1_ID, P1_NAME, P1_BASE_HEALTH, P1_BASE_ATTACK, P1_BASE_DEFENSE 
  , P1_BASE_ARMOR, P1_BASE_INITIATIVE, P1_BASE_CRIT
  )
  , m_location(PLAYER_START_LOC)
  , m_inventory(new Inventory)
  , m_hasAugmentCK(false)
  , m_hasFusionCore(false)
  , m_hasRepairedReactor(false)
{
}

/**
 * Simulates a Player attack by rolling m_dice with m_attack + m_attackMod
 * sides. Outputs the rolls and returns the total.
 */
int Player::rollAttack()
{
  int dieSides = m_attack + m_attackMod;
  int totalDice = m_dice + m_diceMod;
  int roll;
  int totalAttack = 0;
  int rollSum = 0;

  cout << m_name << " rolled " 
    << totalDice << "d" << dieSides << " for an attack of: ";

  for (int i = 0; i < totalDice; ++i) {
    roll = rollDice(dieSides);
    rollSum += roll;

    cout << roll;
    // Include "+" in output if there are multiple rolls to add.
    if (i < totalDice - 1) {
      cout << " + ";
    }
  }
  // Include "=" in output if there were multiple rolls.
  if (totalDice > 1) {
    cout << " = " << rollSum << endl;
  } else {
    cout << endl;
  }

  totalAttack = rollCrit(rollSum);

  // return rollSum;

  setCurrentAttack(totalAttack);
  return totalAttack;
}


/**
 * Takes damage to be inflicted as a parameter, rolls defense, then 
 * subtracts the roll and m_armor from damage. Subtracts the modified 
 * damage value from m_health. Then returns the modified damage 
 * value as an int >= 0
 */
int Player::defend(int damage)
{
  int defenseStat = m_defense + m_defenseMod;
  int armorStat = m_armor + m_armorMod;

  int damageDealt;
  int totalDefense;
  int rollCorrupt;
  int corrupt;

  int roll = rollDice(defenseStat);
  totalDefense = roll + armorStat;


  cout << m_name << " rolled 1d" << defenseStat << " for a defense of: " 
    << roll << endl;
  cout << "Defense roll + armor: " 
    << roll << " + " << armorStat << " = " << totalDefense << endl;

  // Use corrupt ability. 33% success
  rollCorrupt = useAbility();
  if (rollCorrupt == P1_CORRUPT_SUCCESS) {
    corrupt = P1_CORRUPT_BASE + m_armorMod;
    cout << m_name << " uses CORRUPT! Defense +" << corrupt << endl;
    totalDefense += corrupt;
  }

  damageDealt = calculateDamage(damage, totalDefense);

  // Update health
  setCurrentDefense(totalDefense);
  setHealth(m_health - damageDealt);

  return damageDealt;
}

/**
 * Player ability
 * Corrupt: When defending, 33% chance to corrupt the enemy's neural systems, 
 * causing them to deal less damage. Increased by armor mod.
 */
int Player::useAbility()
{
  return rollDice(3);
}

/**
 * Checks Item class type and adds the item to the appropriate Inventory 
 * container.
 */
void Player::addToInventory(Item* itemToAdd)
{
  if (dynamic_cast<Weapon*>(itemToAdd)) {
    // If player has a weapon, check if it's better than itemToAdd
    if (m_inventory->getWeapon()) {
      Item* currentWeapon = m_inventory->getWeapon();

      // Only remove if itemToAdd is better than currentlWeapon
      if (currentWeapon->getItemID() < itemToAdd->getItemID()) {
        handleRemoveWeapon(currentWeapon);
        m_inventory->setWeapon(itemToAdd);
        handleStatMods(itemToAdd);
      } else {
        cout << "Your current weapon is stronger, so you discard the " 
          << itemToAdd->getName() << "." << endl;
      }
    // if no currentWeapon, add the weapon
    } else {
      m_inventory->setWeapon(itemToAdd);
      handleStatMods(itemToAdd);

    }

  } else if (dynamic_cast<Augment*>(itemToAdd)) {
    m_inventory->addAugment(itemToAdd);
    handleStatMods(itemToAdd);

  } else if (dynamic_cast<FusionCore*>(itemToAdd)) {
    m_inventory->setFusionCore(itemToAdd);
  }

  // Check if item added was a key and set bool values.
  if (!m_hasAugmentCK) {
    if (m_inventory->getHasAugmentCK()) {
      setHasAugmentCK(true);
    }
  }
  if (!m_hasFusionCore) {
    if (m_inventory->getFusionCore()) {
      setHasFusionCore(true);
    }
  }
}



/**
 * Adds the item's stat modifiers to the Player's data members.
 */
void Player::handleStatMods(Item* itemToAdd)
{
  int hpMod = itemToAdd->getModifierHealth();
  int atkMod = itemToAdd->getModifierAttack();
  int defMod = itemToAdd->getModifierDefense();
  int armMod = itemToAdd->getModifierArmor();
  int initMod = itemToAdd->getModifierInitiative();
  int critMod = itemToAdd->getModifierCrit();
  int diceMod = itemToAdd->getModifierDice();

  setHealthMod(getHealthMod() + hpMod);
  setAttackMod(getAttackMod() + atkMod);
  setDefenseMod(getDefenseMod() + defMod);
  setArmorMod(getArmorMod() + armMod);
  setInitiativeMod(getInitiativeMod() + initMod);
  setCritMod(getCritMod() + critMod);
  setDiceMod(getDiceMod() + diceMod);
}

/**
 * Removes the Weapon's stat modifiers from the Player's data members.
 */
void Player::handleRemoveWeapon(Item* weaponToRemove)
{
  int hpMod = weaponToRemove->getModifierHealth();
  int atkMod = weaponToRemove->getModifierAttack();
  int defMod = weaponToRemove->getModifierDefense();
  int armMod = weaponToRemove->getModifierArmor();
  int initMod = weaponToRemove->getModifierInitiative();
  int critMod = weaponToRemove->getModifierCrit();
  int diceMod = weaponToRemove->getModifierDice();

  setHealthMod(getHealthMod() - hpMod);
  setAttackMod(getAttackMod() - atkMod);
  setDefenseMod(getDefenseMod() - defMod);
  setArmorMod(getArmorMod() - armMod);
  setInitiativeMod(getInitiativeMod() - initMod);
  setCritMod(getCritMod() - critMod);
  setDiceMod(getDiceMod() - diceMod);

  // m_inventory->removeWeapon();

  m_inventory->setWeapon(nullptr);
}


/**
 * Calls printAugments to view augment details.
 */
void Player::displayAugments()
{
  m_inventory->printAugments();
}

/**
 * Calls printWeapon to view weapon details.
 */
void Player::displayWeapon()
{
  m_inventory->printWeapon();
}

/**
 * Calls printWeapon to view weapon details.
 */
void Player::displayKeyItems()
{
  m_inventory->printFusionCore();
}


/**
 * Setter functions
 */
void Player::setLocation(int location)
{
  m_location = location;
}

void Player::setHasAugmentCK(bool hasAugmentCK)
{
  m_hasAugmentCK = hasAugmentCK;
}

void Player::setHasFusionCore(bool hasFusionCore)
{
  m_hasFusionCore = hasFusionCore;
}

void Player::setHasRepairedReactor(bool hasRepairedReactor)
{
  m_hasRepairedReactor = hasRepairedReactor;
}



/**
 * Getter functions
 */
int Player::getLocation()
{
  return m_location;
}

bool Player::getHasAugmentCK()
{
  return m_hasAugmentCK;
}

bool Player::getHasFusionCore()
{
  return m_hasFusionCore;
}

bool Player::getHasRepairedReactor()
{
  return m_hasRepairedReactor;
}



/**
 * Destructor: Currently empty.
 */
Player::~Player()
{
  delete m_inventory;
}


