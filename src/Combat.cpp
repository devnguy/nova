/*******************************************************************************
** Description:  Class that dictates the flow of combat in NOVA 
**
**               Because a Character's name is referenced often in this class, 
**               it contains a Combatant struct to more easily reference that
**               value.
**               When constructing Combat object, Player should always be the 
**               first Unit* parameter passed in.
*******************************************************************************/ 

#include <iostream>
#include <string>

#include "inputValidation.hpp"
#include "util.hpp"   // Included for clearConsole function
#include "constants.hpp"
#include "Unit.hpp"

#include "Combat.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/**
 * Constructs a Combat object.
 */
Combat::Combat(Unit* player, Unit* enemy)
  : m_c1(player)
  , m_c2(enemy)
  , m_inCombat(true)
  , m_turnCounter(0)
{
  clearConsole();
  setNames();
  decideWhoGoesFirst();
}

/**
 * Runs the entire Combat simulation until a winner is found.
 */
void Combat::run()
{
  clearConsole();
  Unit* attacker;
  Unit* defender;

  handleCombatStart();

  while(m_inCombat) {

    ++m_turnCounter;
    attacker = decideAttacker();
    defender = decideDefender();

    handlePrintAttackHeader();
    handleAttack(attacker, defender);
    displayCurrentSP();
    switchAttackers();
    checkIsAlive(); // While loop control within this function.

    // Prompt to continue if user chose not to skip combat.
    if (m_skipCombat == 1) {
      pressEnterToContinue();
    }
  }
  endCombat();
}

/**
 * Prints the start of combat header, and gives the user the option to 
 * pause after each attack or skip to the end of combat.
 */
void Combat::handleCombatStart()
{
  cout << "-----COMBAT START-----" << endl;
  cout << c1.name << " vs. " << c2.name << endl << endl;
  cout << "Would you like to pause after each attack or skip to ";
  cout << "the end of combat?" << endl;
  cout << "1. Pause after each attack" << endl;
  cout << "2. Skip to the end of combat" << endl << endl;
  m_skipCombat = validateChoice(1, 2); // FIXME: use constants?
}

/**
 * Prints the winner
 */
void Combat::endCombat()
{
  string winnerName;
  cout << "-----COMBAT END-----" << endl;

  if (m_winner == COMBATANT_1_ID) {
    // winnerName = c1.name;

    cout << "You defeated " << c2.name << " in " << m_turnCounter << " turns." 
      << endl << endl;

  } else if (m_winner == COMBATANT_2_ID) {
    // winnerName = c2.name;
    cout << "DEFEAT..." << endl << endl;
  }

  // cout << winnerName << " won in " 
  //   << m_turnCounter << " turns!" << endl << endl;

  // Reset attacker/defender at the end of Combat.
  m_c1->setIsAttacking(false);
  m_c1->setIsDefending(false);
  m_c2->setIsAttacking(false);
  m_c2->setIsDefending(false);

  pressEnterToContinue();
}

/**
 * Prints the appropriate header depending on the current attacker.
 */
void Combat::handlePrintAttackHeader()
{
  string attackerName;

  if (m_c1->getIsAttacking()) {
    attackerName = c1.name;
  } else if (m_c2->getIsAttacking()) {
    attackerName = c2.name;
  }
  cout << "-----" << attackerName << " Attack-----" << endl;
}

/**
 * Checks if either combatant has died. Then appropriately ends combat and 
 * assigns a winner. Called after each attack.
 */
void Combat::checkIsAlive()
{
  if (m_c1->getIsAlive() == false) {
    m_inCombat = false;
    m_winner = COMBATANT_2_ID;
  }
  if (m_c2->getIsAlive() == false) {
    m_inCombat = false;
    m_winner = COMBATANT_1_ID;
  }
}

/**
 * Displays each combatant's remaining strength points. Called after 
 * each attack.
 */
void Combat::displayCurrentSP()
{
  cout << "Health remaining: " << endl;
  cout << c1.name << ": " << m_c1->getHealth() << endl;
  cout << c2.name << ": " << m_c2->getHealth() << endl << endl;
}

/**
 * Takes 2 pointers to Characters so that their member variables can 
 * be modified as combat is carried out. The first acts as the attacker, 
 * the second acts as the defender. Handles damage dealt output.
 */
void Combat::handleAttack(Unit* attacker, Unit* defender)
{
  int attackRoll = attacker->rollAttack();
  int damageDealt = defender->defend(attackRoll);

  // Output results
  cout << endl;
  cout << attacker->getName() << " deals " 
    << attacker->getCurrentAttack() << " - " << defender->getCurrentDefense() 
    << " = " << damageDealt << " damage!" << endl << endl;
}


/**
 * Decides an attacker based on isAttacking bool variables, then returns
 * a pointer to the attacking Character.
 * NOTE: Only 1 Character's isAttacking member variable should be true at 
 * a time.
 */
Unit* Combat::decideAttacker()
{
  Unit* attacker;

  if (m_c1->getIsAttacking()) {
    attacker = m_c1;
  } else if (m_c2->getIsAttacking()) {
    attacker = m_c2;
  }
  return attacker;
}

/**
 * Decides a defender based on isDefending bool variable, then returns 
 * a pointer to the defending Combatant.
 * NOTE: Only 1 Character's isDefending member variable should be true at 
 * a time.
 */
Unit* Combat::decideDefender()
{
  Unit* defender;

  if (m_c1->getIsDefending()) {
    defender = m_c1;
  } else if (m_c2->getIsDefending()) {
    defender = m_c2;
  }
  return defender;
}

/**
 * Toggles isAttacking and isDefending bool values of m_c1 and m_c2.
 * If a Combatant was attacking, it should now be defending and vice versa.
 * 
 * NOTE: isAttacking and isDefending should never be the same bool value.
 */
void Combat::switchAttackers()
{
  m_c1->setIsAttacking( !(m_c1->getIsAttacking()) );
  m_c2->setIsAttacking( !(m_c2->getIsAttacking()) );
  m_c1->setIsDefending( !(m_c1->getIsDefending()) );
  m_c2->setIsDefending( !(m_c2->getIsDefending()) );
}

/**
 * Provides a way to differentiate the Characters if they're the same class.
 */
void Combat::setNames()
{
  if (m_c1->getUnitID() == m_c2->getUnitID()) {
    m_c1->setName(m_c1->getName() + "(1)");
    m_c2->setName(m_c2->getName() + "(2)");
  }
  c1.name = m_c1->getName();
  c2.name = m_c2->getName();
}

/**
 * Determines which Character attacks first by rolling for initiative. 
 * This function is called in the Combat constructor because and MUST 
 * be called prior to run() to properly assign attacker and defender.
 * 
 * setNames needs to have been called prior to calling this function.
 */
void Combat::decideWhoGoesFirst()
{
  cout << "-----INITIATING COMBAT-----" << endl << endl;

  do {
    c1.totalInitiative = m_c1->rollInitiative();
    c2.totalInitiative = m_c2->rollInitiative();
    cout << endl;

    if (c1.totalInitiative > c2.totalInitiative) {
      cout << c1.name << " attacks first!" << endl << endl;
      m_c1->setIsAttacking(true);
      m_c2->setIsDefending(true);

    } else if (c2.totalInitiative > c1.totalInitiative) {
      cout << c2.name << " attacks first!" << endl << endl;
      m_c2->setIsAttacking(true);
      m_c1->setIsDefending(true);

    } else {
      cout << "Tied initiative. Rolling again..." << endl << endl;
    }
  // Will not accept a tied initiative.
  } while (c1.totalInitiative == c2.totalInitiative);

  pressEnterToContinue();
}

/**
 * Requires the user enter 1 to move on to next section.
 */
// void Combat::pressEnterToContinue()
// {
//   m_continue = validateChoice(YES);
// }
