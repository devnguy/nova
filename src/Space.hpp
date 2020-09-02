/*******************************************************************************
** Description:  Definition of Space class.
*******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Item.hpp"
#include "Player.hpp"


class Space {
  protected:
    int m_spaceID;
    Space* m_top;
    Space* m_right;
    Space* m_left;
    Space* m_bottom;
    Item* m_containedItem;
    Unit* m_containedEnemy;

    char m_mapChar;
    char m_orginalChar;
    bool m_isWalkable;
    bool m_holdsPlayer;
    bool m_spaceTriggered;
  
  public:
    Space();
    Space(char, bool);
    Space(int, char, bool);
    ~Space();

    void updateSpace();

    // Event is unique to the derived class
    virtual void triggerSpace();

    // testing overloaded FIXME
    void updateSpace(Player*);
    virtual void triggerSpace(Player*);

    // Setters
    void setTop(Space*);
    void setRight(Space*);
    void setLeft(Space*);
    void setBottom(Space*);
    void setMapChar(char);
    void setIsWalkable(bool);
    void setHoldsPlayer(bool);
    void setSpaceID(int);
    void setSpaceTriggered(bool);
    void setOriginalChar(char);
    void setContainedItem(Item*);
    void setContainedEnemy(Unit*);

    // Getters
    Space* getTop();
    Space* getRight();
    Space* getLeft();
    Space* getBottom();
    char getMapChar();
    bool getIsWalkable();
    bool getHoldsPlayer();
    int getSpaceID();
    bool getSpaceTriggered();
    char getOriginalChar();
    Item* getContainedItem();
    Unit* getContainedEnemy();

};

#endif