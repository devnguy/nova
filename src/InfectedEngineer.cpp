/*******************************************************************************
** Description:  InfectedEngineer implementation.
**
*******************************************************************************/

#include <iostream>

#include "InfectedEngineer.hpp"
#include "Unit.hpp"
#include "constants.hpp"
#include "util.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor calls base Character class constructor to initialize 
 * inherited data members.
 */
InfectedEngineer::InfectedEngineer() 
  : Unit(INFECTED_ENGINEER_ID, INFECTED_ENGINEER_NAME
  , INFECTED_ENGINEER_HEALTH, INFECTED_ENGINEER_ATTACK
  , INFECTED_ENGINEER_DEFENSE, INFECTED_ENGINEER_ARMOR
  , INFECTED_ENGINEER_INITIATIVE, INFECTED_ENGINEER_CRIT
  )
  , m_turretDeployed(false)
{
}

/**
 * Simulates a Player attack by rolling m_dice with m_attack + m_attackMod
 * sides. Outputs the rolls and returns the total.
 */
int InfectedEngineer::rollAttack()
{
  // Deploy turret at start of combat.
  if (!m_turretDeployed) {
    useAbility();
  }

  int roll = rollDice(m_attack);
  int totalAttack = roll + INFECTED_ENGINEER_TURRET_ATK;

  cout << m_name << " rolled " 
    << m_dice << "d" << m_attack << " for an attack of: " << roll << endl;

  cout << m_name << "'s TURRET attacks for " << INFECTED_ENGINEER_TURRET_ATK 
    << endl;


  totalAttack = roll + INFECTED_ENGINEER_TURRET_ATK;

  // return rollSum;

  setCurrentAttack(totalAttack);
  return totalAttack;
}

/**
 * Infected Engineer ability
 * Deploy Turret: Turret attacks with the Engineer each turn.
 */
int InfectedEngineer::useAbility()
{
  m_turretDeployed = true;
  cout << m_name << " deploys a TURRET." << endl;
  return 0;
}



/**
 * Destructor: Currently empty.
 */
InfectedEngineer::~InfectedEngineer()
{
}


