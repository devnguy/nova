/*******************************************************************************
** Description:  Definition of Weapon class.
*******************************************************************************/

#ifndef WEAPON_HPP
#define WEAPON_HPP


#include <string>
#include "Item.hpp"


class Weapon : public Item {
  protected:
  
  public:
    Weapon();
    Weapon(int, std::string, int, int, int, int, int, int);
    Weapon(int, std::string, int, int, int, int, int, int, int);
    ~Weapon();

    // Setters
    // virtual void printWeapon();


    // Getters

};

#endif


