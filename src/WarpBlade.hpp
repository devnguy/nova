/*******************************************************************************
** Description:  Definition of WarpBlade weapon class.
*******************************************************************************/

#ifndef WARP_BLADE_HPP
#define WARP_BLADE_HPP


#include <string>
#include "Weapon.hpp"


class WarpBlade : public Weapon {
  protected:
  
  public:
    WarpBlade();
    ~WarpBlade();

    void printInfo();
    void handlePickUpMessage();

};

#endif


