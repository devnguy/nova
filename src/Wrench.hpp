/*******************************************************************************
** Description:  Definition of Wrench weapon class.
*******************************************************************************/

#ifndef WRENCH_HPP
#define WRENCH_HPP


#include <string>
#include "Weapon.hpp"


class Wrench : public Weapon {
  protected:
  
  public:
    Wrench();
    ~Wrench();

    void printInfo();
    void handlePickUpMessage();

};

#endif


