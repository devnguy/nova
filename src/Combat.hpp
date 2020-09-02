/*******************************************************************************
** Description:  Definition of Combat class.
**               
**       Usage:  Constructor should be called with 2 pointers to Characters. 
**               It will assign the first attacker and defender.
**               After construction of Combat object, call Combat.run() to  
**               start combat.
*******************************************************************************/ 

#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "Unit.hpp"

class Combat {
  private:
    Unit* m_c1;
    Unit* m_c2;
    bool m_inCombat;
    int m_turnCounter;
    int m_winner;
    int m_skipCombat;

    struct Combatant {
      std::string name;
      int totalInitiative;
    } c1, c2;
    
    // Initialization
    void setNames();
    void decideWhoGoesFirst();

    // Attack
    void handleCombatStart();
    Unit* decideAttacker();
    Unit* decideDefender();
    void handlePrintAttackHeader();
    void handleAttack(Unit*, Unit*);
    void displayCurrentSP();
    void switchAttackers();
    void checkIsAlive();
    
    void endCombat();

  public:
    Combat();
    Combat(Unit*, Unit*);
    void run();
};

#endif