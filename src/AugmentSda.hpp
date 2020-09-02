/*******************************************************************************
** Description:  Definition of AugmentSda class.
*******************************************************************************/

#ifndef AUGMENT_SDA_HPP
#define AUGMENT_SDA_HPP

#include "Augment.hpp"


class AugmentSda : public Augment {
  private:
  
  public:
    AugmentSda();
    ~AugmentSda();

    void printInfo();
    void handlePickUpMessage();


};

#endif


