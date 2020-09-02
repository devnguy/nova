/*******************************************************************************
** Description:  Definition of Inventory class.
*******************************************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include "Item.hpp"
#include "Weapon.hpp"
#include "Augment.hpp"


class Inventory {
  private:
    Item* m_weapon;
    std::vector<Item*> m_augments;
    Item* m_fusionCore;
    bool m_hasAugmentCK;

  public:
    Inventory();
    ~Inventory();

    void addAugment(Item*);
    void printAugments();
    void printWeapon();
    void printFusionCore();
    
    void removeWeapon();

    // Setters
    void setWeapon(Item*);
    void setHasAugmentCK(bool);
    void setFusionCore(Item*);

    // Getters
    Item* getWeapon();
    bool getHasAugmentCK();
    Item* getFusionCore();

};

#endif


