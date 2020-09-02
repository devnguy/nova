/*******************************************************************************
** Description:  Definition of AugmentAtp class.
*******************************************************************************/

#ifndef AUGMENT_ATP_HPP
#define AUGMENT_ATP_HPP

#include "Augment.hpp"


class AugmentAtp : public Augment {
  private:
  
  public:
    AugmentAtp();
    ~AugmentAtp();

    void printInfo();
    void handlePickUpMessage();


};

#endif


