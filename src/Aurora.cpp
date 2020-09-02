/*******************************************************************************
** Description:  Aurora implementation.
**
*******************************************************************************/

#include <iostream>

#include "Aurora.hpp"
#include "Unit.hpp"
#include "constants.hpp"
#include "util.hpp"

using std::cout;
using std::endl;


const int USE_ATTACK = 1;
const int USE_SHOCKWAVE = 2;
const int USE_OVERFLOW = 1;

/**
 * Default constructor calls base Character class constructor to initialize 
 * inherited data members.
 */
Aurora::Aurora() 
  : Unit(AURORA_ID, AURORA_NAME
  , AURORA_HEALTH, AURORA_ATTACK
  , AURORA_DEFENSE, AURORA_ARMOR
  , AURORA_INITIATIVE, AURORA_CRIT
  )
  , m_recurse(1)
{
  setDiceMod(AURORA_DICE);
}

/**
 * Simulates Aurora attack by rolling m_dice with m_attack + m_attackMod
 * sides. Outputs the rolls and returns the total.
 */
int Aurora::rollAttack()
{
  m_recurse += 1;

  cout << m_name << " uses RECURSE" << endl;
  cout << m_recurse << " damage will be added to attack" << endl;


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

  totalAttack = rollSum + m_recurse;

  cout << " + " << m_recurse << " = " << totalAttack << endl;

  totalAttack = rollCrit(totalAttack);


  // return rollSum;

  setCurrentAttack(totalAttack);
  return totalAttack;
}

/**
 * Destructor: Currently empty.
 */
Aurora::~Aurora()
{
}


