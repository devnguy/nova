/*******************************************************************************
** Description:  Definition of the NihilanStalker class. This is one 
**               of the derived classes from Unit.
*******************************************************************************/

#ifndef NIHILAN_STALKER_HPP
#define NIHILAN_STALKER_HPP

#include "Unit.hpp"

class NihilanStalker : public Unit {
  public:
    NihilanStalker();
    ~NihilanStalker();
    // int rollAttack();
    int defend(int);
    int useAbility();
};

#endif