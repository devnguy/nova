/*******************************************************************************
** Description:  Definition of AugmentCK class.
*******************************************************************************/

#ifndef AUGMENT_CK_HPP
#define AUGMENT_CK_HPP

#include "Augment.hpp"


class AugmentCK : public Augment {
  private:
  
  public:
    AugmentCK();
    ~AugmentCK();

    void printInfo();
    void handlePickUpMessage();


};

#endif


