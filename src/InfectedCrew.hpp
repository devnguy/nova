/*******************************************************************************
** Description:  Definition of the InfectedCrew class. This is one of the 
**               derived classes from Unit.
*******************************************************************************/

#ifndef INFECTED_CREW_HPP
#define INFECTED_CREW_HPP

#include "Unit.hpp"

class InfectedCrew : public Unit {
  public:
    InfectedCrew();
    ~InfectedCrew();
    // int rollAttack();
    // int defend(int);
    // int useAbility();
};

#endif