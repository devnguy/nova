/*******************************************************************************
** Description:  Definition of Enemy derived class from Space.
*******************************************************************************/

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Space.hpp"


class Enemy : public Space {
  private:
  
  public:
    Enemy();
    Enemy(int);
    ~Enemy();

    void triggerSpace(Player*);
};

#endif


