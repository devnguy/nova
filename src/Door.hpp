/*******************************************************************************
** Description:  Definition of Door class.
*******************************************************************************/

#ifndef DOOR_HPP
#define DOOR_HPP

#include "Space.hpp"


class Door : public Space {
  private:
    bool m_isUnlocked;
    
  
  public:
    Door();
    Door(int);
    ~Door();

    void triggerSpace();
    void triggerSpace(Player*);
    void setIsUnlocked(bool);
    bool getIsUnlocked();


};

#endif


