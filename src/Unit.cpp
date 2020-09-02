/*******************************************************************************
** Description:  Unit class 
*******************************************************************************/ 

#include <iostream>

#include "Unit.hpp"
#include "constants.hpp"
#include "util.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor
 */
Unit::Unit() 
  : m_unitID(0)
  , m_attack(1)
  , m_defense(1)
  , m_armor(1)
  , m_initiative(1)
  , m_health(1)
  , m_name(" ")
{
}

/**
 * Overloaded constructor that instantiates a  Unit.
 * Must be called with arguments specific to the type of  Unit.
 */
Unit::Unit(int unitID, std::string name, int health, int attack
  , int defense, int armor, int initiative, int crit) 
    : m_unitID(unitID)
    , m_name(name)
    , m_health(health)
    , m_attack(attack)
    , m_defense(defense)
    , m_armor(armor)
    , m_initiative(initiative)
    , m_crit(crit)
    , m_dice(1)
    , m_healthMod(0)
    , m_attackMod(0)
    , m_defenseMod(0)
    , m_armorMod(0)
    , m_initiativeMod(0)
    , m_critMod(0)
    , m_diceMod(0)
    , m_isAlive(true)
    , m_isAttacking(false)
    , m_isDefending(false)
{
}

/**
 * Rolls 1 d20, adds m_initiative, and outputs the results.
 */
int Unit::rollInitiative()
{
  int initiativeRoll = rollDice(INITIATIVE_DIE);
  int initiativeStat = m_initiative + m_initiativeMod;
  int totalInititative = initiativeRoll + initiativeStat;

  cout << m_name << " rolled 1d" << INITIATIVE_DIE 
    << " for an initiative of: " << initiativeRoll << " + " << initiativeStat
    << " = " << totalInititative << endl;

  setTotalInitiative(totalInititative);
  return totalInititative;
}



/**
 * Simulates a Unit attack by rolling their number of dice with m_attack 
 * sides. Outputs the rolls and returns the total.
 */
int Unit::rollAttack()
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

  // Roll for crit if the Unit is capable.
  if (m_crit + m_critMod) {
    totalAttack = rollCrit(rollSum);
  } else {
    totalAttack = rollSum;
  }

  setCurrentAttack(totalAttack);
  return totalAttack;
}


/**
 * Takes damage to be inflicted as a parameter, rolls defense, then 
 * subtracts the roll and m_armor from damage. Subtracts the modified 
 * damage value from m_strengthPoints. Then returns the modified damage 
 * value as an int >= 0
 */
int Unit::defend(int damage)
{
  int damageDealt;
  int totalDefense;
  int defenseStat = m_defense + m_defenseMod;
  int armorStat = m_armor + m_armorMod;

  int roll = rollDice(defenseStat);
  totalDefense = roll + armorStat;

  damageDealt = calculateDamage(damage, totalDefense);

  cout << m_name << " rolled 1d" << defenseStat << " for a defense of: " 
    << roll << endl;
  cout << "Defense roll + armor: " 
    << roll << " + " << armorStat << " = " << totalDefense << endl;

  // Update health
  setCurrentDefense(totalDefense);
  setHealth(m_health - damageDealt);

  return damageDealt;
}

/**
 * Returns the calculated damage and ensures that it is always >= 0
 */
int Unit::calculateDamage(int damage, int defense)
{
  int calculatedDamage = damage - defense;

  if (calculatedDamage >= 0) {
    setDamageToDeal(calculatedDamage);
    return calculatedDamage;

  } else {
    setDamageToDeal(0);
    return 0;
  }
}

/**
 * This is a virtual function that allows Units to use their own abilities.
 */
int Unit::useAbility()
{
  return 0;
}

/**
 * Generates a random number between 1-100. If the generated number is 
 * less than the Unit's crit chance, then a crit occurs.
 */
int Unit::rollCrit(int baseAttack)
{
  int critChance = m_crit + m_critMod;
  int generatedInt = generateRandInt(1, 100);
  int totalDamage = baseAttack;

  if (generatedInt < critChance) {
    totalDamage *= 1.5;
    totalDamage = static_cast<int>(totalDamage);
    cout << m_name << " lands a CRIT! Damage increased to " 
      << totalDamage << endl;
  }
  return totalDamage;
}


/**
 * Getter functions
 */
int Unit::getUnitID()
{
  return m_unitID;
}

int Unit::getAttack()
{
  return m_attack;
}

int Unit::getDefense()
{
  return m_defense;
}

int Unit::getArmor()
{
  return m_armor;
}

int Unit::getInitiative()
{
  return m_initiative;
}

int Unit::getHealth()
{
  return m_health;
}

int Unit::getCrit()
{
  return m_crit;
}

std::string Unit::getName()
{
  return m_name;
}

int Unit::getTotalInitiative()
{
  return m_totalInitiative;
}

int Unit::getCurrentAttack()
{
  return m_currentAttack;
}

int Unit::getCurrentDefense()
{
  return m_currentDefense;
}

int Unit::getDamageToDeal()
{
  return m_damageToDeal;
}

bool Unit::getIsAlive()
{
  return m_isAlive;
}

bool Unit::getIsAttacking()
{
  return m_isAttacking;
}

bool Unit::getIsDefending()
{
  return m_isDefending;
}

int Unit::getHealthMod()
{
  return m_healthMod;
}

int Unit::getAttackMod()
{
  return m_attackMod;
}

int Unit::getDefenseMod()
{
  return m_defenseMod;
}

int Unit::getArmorMod()
{
  return m_armorMod;
}

int Unit::getInitiativeMod()
{
  return m_initiativeMod;
}

int Unit::getCritMod()
{
  return m_critMod;
}

int Unit::getDiceMod()
{
  return m_diceMod;
}

int Unit::getDice()
{
  return m_dice;
}

/**
 * Setter functions
 */
void Unit::setUnitID(int unitID)
{
  m_unitID = unitID;
}

void Unit::setAttack(int attack)
{
  m_attack = attack;
}

void Unit::setDefense(int defense)
{
  m_defense = defense;
}

void Unit::setArmor(int armor)
{
  m_armor = armor;
}

void Unit::setInitiative(int initiative)
{
  m_initiative = initiative;
}

/**
 * Sets m_health as the int passed in. The Unit has died when 
 * m_health <= 0
 */
void Unit::setHealth(int health)
{
  m_health = health;
  if (m_health <= 0) {
    setIsAlive(false);
  }
}

void Unit::setCrit(int crit)
{
  m_crit = crit;
}

void Unit::setDice(int dice)
{
  m_dice = dice;
}

void Unit::setHealthMod(int healthMod)
{
  m_healthMod = healthMod;
}

void Unit::setAttackMod(int attackMod)
{
  m_attackMod = attackMod;
}

void Unit::setDefenseMod(int defenseMod)
{
  m_defenseMod = defenseMod;
}

void Unit::setArmorMod(int armorMod)
{
  m_armorMod = armorMod;
}

void Unit::setInitiativeMod(int initiativeMod)
{
  m_initiativeMod = initiativeMod;
}

void Unit::setCritMod(int critMod)
{
  m_critMod = critMod;
}

void Unit::setDiceMod(int diceMod)
{
  m_diceMod = diceMod;
}

void Unit::setName(std::string name)
{
  m_name = name;
}

void Unit::setTotalInitiative(int totalInitiative)
{
  m_totalInitiative = totalInitiative;
}

void Unit::setCurrentAttack(int currentAttack)
{
  m_currentAttack = currentAttack;
}

void Unit::setCurrentDefense(int currentDefense)
{
  m_currentDefense = currentDefense;
}

void Unit::setDamageToDeal(int damageToDeal)
{
  m_damageToDeal = damageToDeal;
}

void Unit::setIsAlive(bool isAlive)
{
  m_isAlive = isAlive;
}

void Unit::setIsAttacking(bool isAttacking)
{
  m_isAttacking = isAttacking;
}

void Unit::setIsDefending(bool isDefending)
{
  m_isDefending = isDefending;
}


/**
 * Destructor
 */
Unit::~Unit()
{

}