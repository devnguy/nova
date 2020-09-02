/*******************************************************************************
** Description:  Definition of SupplyCache derived class.
*******************************************************************************/

#ifndef SUPPLY_CACHE_HPP
#define SUPPLY_CACHE_HPP

#include "Space.hpp"


class SupplyCache : public Space {
  private:
  
  public:
    SupplyCache();
    SupplyCache(int);
    ~SupplyCache();

    void triggerSpace(Player*);
};

#endif


