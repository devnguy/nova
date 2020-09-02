/*******************************************************************************
** Description:  Definition of Item base class.
*******************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>



class Item {
  protected:
    int m_itemID;
    std::string m_name;
    std::string m_description;
    int m_modifierHealth;
    int m_modifierAttack;
    int m_modifierDefense;
    int m_modifierArmor;
    int m_modifierInitiative;
    int m_modifierCrit;
    int m_modifierDice;
  
  public:
    Item();
    Item(int, std::string, int, int, int, int, int, int);
    // Used to construct AugmentOptik
    Item(int, std::string, int, int, int, int, int, int, int);
    ~Item();

    virtual void printInfo();
    virtual void handlePickUpMessage();

    // Setters
    void setItemID(int);
    void setName(std::string);
    void setDescritpion(std::string);
    void setModifierHealth(int);
    void setModifierAttack(int);
    void setModifierDefense(int);
    void setModifierArmor(int);
    void setModifierInitiative(int);
    void setModifierCrit(int);
    void setModifierDice(int);


    // Getters
    virtual int getItemID();
    std::string getName();
    std::string getDescription();
    int getModifierHealth();
    int getModifierAttack();
    int getModifierDefense();
    int getModifierArmor();
    int getModifierInitiative();
    int getModifierCrit();
    int getModifierDice();
};

#endif


