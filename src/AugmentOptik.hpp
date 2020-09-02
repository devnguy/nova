/*******************************************************************************
** Description:  Definition of AugmentOPTIK class.
*******************************************************************************/

#ifndef AUGMENT_OPTIK_HPP
#define AUGMENT_OPTIK_HPP

#include "Augment.hpp"


class AugmentOptik : public Augment {
  private:
  
  public:
    AugmentOptik();
    ~AugmentOptik();

    void printInfo();
    void handlePickUpMessage();


};

#endif


