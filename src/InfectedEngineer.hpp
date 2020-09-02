/*******************************************************************************
** Description:  Definition of the InfectedEngineer class. This is one 
**               of the derived classes from Unit.
*******************************************************************************/

#ifndef INFECTED_ENGINEER_HPP
#define INFECTED_ENGINEER_HPP

#include "Unit.hpp"

class InfectedEngineer : public Unit {
  private:
    bool m_turretDeployed;

  public:
    InfectedEngineer();
    ~InfectedEngineer();
    int rollAttack();
    // int defend(int);
    int useAbility();
};

#endif