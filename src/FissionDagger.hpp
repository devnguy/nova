/*******************************************************************************
** Description:  Definition of FissionDagger weapon class.
*******************************************************************************/

#ifndef FISSION_DAGGER_HPP
#define FISSION_DAGGER_HPP


#include <string>
#include "Weapon.hpp"


class FissionDagger : public Weapon {
  protected:
  
  public:
    FissionDagger();
    ~FissionDagger();

    void printInfo();
    void handlePickUpMessage();

};

#endif


