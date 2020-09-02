/*******************************************************************************
** Description:  Definition of FusionCore class derived from Item.
*******************************************************************************/

#ifndef FUSION_CORE_HPP
#define FUSION_CORE_HPP


#include <string>
#include "Item.hpp"


class FusionCore : public Item {
  protected:
  
  public:
    FusionCore();
    ~FusionCore();

    void printInfo();
    void handlePickUpMessage();

};

#endif


