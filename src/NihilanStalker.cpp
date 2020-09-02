/*******************************************************************************
** Description:  NihilanStalker implementation.
**
*******************************************************************************/

#include <iostream>

#include "NihilanStalker.hpp"
#include "Unit.hpp"
#include "constants.hpp"
#include "util.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor calls base Character class constructor to initialize 
 * inherited data members.
 */
NihilanStalker::NihilanStalker() 
  : Unit(NIHILAN_STALKER_ID, NIHILAN_STALKER_NAME
  , NIHILAN_STALKER_HEALTH, NIHILAN_STALKER_ATTACK
  , NIHILAN_STALKER_DEFENSE, NIHILAN_STALKER_ARMOR
  , NIHILAN_STALKER_INITIATIVE, NIHILAN_STALKER_CRIT
  )
{
  setDiceMod(NIHILAN_STALKER_DICE);
}

/**
 * Takes damage to be inflicted as a parameter, rolls defense, then 
 * subtracts the roll and m_armor from damage. Subtracts the modified 
 * damage value from m_health. Then returns the modified damage 
 * value as an int >= 0
 */
int NihilanStalker::defend(int damage)
{
  int defenseStat = m_defense + m_defenseMod;
  int armorStat = m_armor + m_armorMod;

  int damageDealt;
  int totalDefense;
  int rollAfterImage;

  int roll = rollDice(defenseStat);
  totalDefense = roll + armorStat;

  cout << m_name << " rolled 1d" << defenseStat << " for a defense of: " 
    << roll << endl;
  cout << "Defense roll + armor: " 
    << roll << " + " << armorStat << " = " << totalDefense << endl;

  // Use corrupt ability. 25% success
  rollAfterImage = useAbility();

  if (rollAfterImage == NIHILAN_STALKER_AFTER_IMAGE_SUCCESS) {
    cout << m_name << " uses AFTER IMAGE! Defense +" 
      << NIHILAN_STALKER_AFTER_IMAGE << endl;

    totalDefense += NIHILAN_STALKER_AFTER_IMAGE;
  }

  damageDealt = calculateDamage(damage, totalDefense);

  // Update health
  setCurrentDefense(totalDefense);
  setHealth(m_health - damageDealt);

  return damageDealt;
}

/**
 * Nihilan Stalker ability
 * After Image: When defending, 33% chance to increase defense. 
 */
int NihilanStalker::useAbility()
{
  return rollDice(3);
}




/**
 * Destructor: Currently empty.
 */
NihilanStalker::~NihilanStalker()
{
}


