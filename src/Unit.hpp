/*******************************************************************************
** Description:  Header file for Unit.cpp
*******************************************************************************/

#ifndef UNIT_HPP
#define UNIT_HPP

#include <string>

class Unit {
  protected:
    int m_unitID;
    int m_attack;
    int m_defense;
    int m_armor;
    int m_initiative;
    int m_health;
    int m_crit;
    int m_dice;
    std::string m_name;

    int m_healthMod;
    int m_attackMod;
    int m_defenseMod;
    int m_armorMod;
    int m_initiativeMod;
    int m_critMod;
    int m_diceMod;

    int m_totalInitiative;
    int m_currentAttack;
    int m_currentDefense;
    int m_damageToDeal;
    bool m_isAlive;
    bool m_isAttacking;
    bool m_isDefending;

  public:
    Unit();
    Unit(int, std::string, int, int, int, int, int, int);
    virtual ~Unit();

    int rollInitiative();
    int calculateDamage(int, int);
    virtual int rollAttack();
    virtual int rollCrit(int);
    virtual int defend(int);
    virtual int useAbility();

    // Getter functions
    int getUnitID();
    std::string getName();
    int getHealth();
    int getAttack();
    int getDefense();
    int getArmor();
    int getInitiative();
    int getCrit();
    int getDice();

    int getHealthMod();
    int getAttackMod();
    int getDefenseMod();
    int getArmorMod();
    int getInitiativeMod();
    int getCritMod();
    int getDiceMod();

    int getTotalInitiative();
    int getCurrentAttack();
    int getCurrentDefense();
    int getDamageToDeal();
    bool getIsAlive();
    bool getIsAttacking();
    bool getIsDefending();

    // Setter functions
    void setUnitID(int);
    void setName(std::string);
    virtual void setHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setArmor(int);
    void setInitiative(int);
    void setCrit(int);
    void setDice(int);
    
    void setHealthMod(int);
    void setAttackMod(int);
    void setDefenseMod(int);
    void setArmorMod(int);
    void setInitiativeMod(int);
    void setCritMod(int);
    void setDiceMod(int);

    void setTotalInitiative(int);
    void setCurrentAttack(int);
    void setCurrentDefense(int);
    void setDamageToDeal(int);
    void setIsAlive(bool);
    void setIsAttacking(bool);
    void setIsDefending(bool);
};

#endif