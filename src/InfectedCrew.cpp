/*******************************************************************************
** Description:  InfectedCrew implementation.
**
*******************************************************************************/

#include <iostream>

#include "InfectedCrew.hpp"
#include "Unit.hpp"
#include "constants.hpp"
#include "util.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor calls base Character class constructor to initialize 
 * inherited data members.
 */
InfectedCrew::InfectedCrew() 
  : Unit(INFECTED_CREW_ID, INFECTED_CREW_NAME, INFECTED_CREW_HEALTH
  , INFECTED_CREW_ATTACK, INFECTED_CREW_DEFENSE, INFECTED_CREW_ARMOR
  , INFECTED_CREW_INITIATIVE, INFECTED_CREW_CRIT
  )
{
}


/**
 * Destructor: Currently empty.
 */
InfectedCrew::~InfectedCrew()
{
}


