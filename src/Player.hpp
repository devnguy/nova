/*******************************************************************************
** Description:  Definition of the Player
*******************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>

#include "Unit.hpp"
#include "Inventory.hpp"

class Player : public Unit {
  private:
    int m_location;
    Inventory* m_inventory;
    bool m_hasAugmentCK;
    bool m_hasFusionCore;
    bool m_hasRepairedReactor;

  public:
    Player();
    ~Player();
    int rollAttack();
    // int rollCrit();
    int defend(int);
    int useAbility();

    void addToInventory(Item*);

    void handleStatMods(Item*);
    void handleRemoveWeapon(Item*);

    void displayAugments();
    void displayWeapon();
    void displayKeyItems();

    void setLocation(int);
    void setHasAugmentCK(bool);
    void setHasFusionCore(bool);
    void setHasRepairedReactor(bool);
    int getLocation();
    bool getHasAugmentCK();
    bool getHasFusionCore();
    bool getHasRepairedReactor();
};

#endif