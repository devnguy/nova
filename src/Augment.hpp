/*******************************************************************************
** Description:  Definition of Equipment derived from Item base class.
*******************************************************************************/

#ifndef AUGMENT_HPP
#define AUGMENT_HPP

#include "Item.hpp"
#include <string>


class Augment : public Item {
  protected:

  
  public:
    Augment();
    Augment(int, std::string, int, int, int, int, int, int);
    Augment(int, std::string, int, int, int, int, int, int, int);
    ~Augment();

    // Setters

    // Getters
};

#endif


