/*******************************************************************************
** Description:  Definition of the Aurora class. This is one 
**               of the derived classes from Unit.
*******************************************************************************/

#ifndef AURORA_HPP
#define AURORA_HPP

#include "Unit.hpp"

class Aurora : public Unit {
  private:
    int m_recurse;

  public:
    Aurora();
    ~Aurora();
    int rollAttack();
    // int defend(int);
    // int useAbility();
};

#endif