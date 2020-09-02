/*******************************************************************************
** Description:  InfectedScientist implementation.
**
*******************************************************************************/

#include <iostream>

#include "InfectedScientist.hpp"
#include "Unit.hpp"
#include "constants.hpp"
#include "util.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor calls base Character class constructor to initialize 
 * inherited data members.
 */
InfectedScientist::InfectedScientist() 
  : Unit(INFECTED_SCIENTIST_ID, INFECTED_SCIENTIST_NAME
  , INFECTED_SCIENTIST_HEALTH, INFECTED_SCIENTIST_ATTACK
  , INFECTED_SCIENTIST_DEFENSE, INFECTED_SCIENTIST_ARMOR
  , INFECTED_SCIENTIST_INITIATIVE, INFECTED_SCIENTIST_CRIT
  )
{
}


/**
 * Destructor: Currently empty.
 */
InfectedScientist::~InfectedScientist()
{
}


