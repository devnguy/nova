/*******************************************************************************
** Description:  Definition of Doodad class.
*******************************************************************************/

#ifndef DOODAD_HPP
#define DOODAD_HPP

#include "Space.hpp"


class Doodad : public Space {
  protected:
    
  
  public:
    Doodad(char);
    Doodad(int, char);
    ~Doodad();


};

#endif


