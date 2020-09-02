/*******************************************************************************
** Description:  Implementation of Doodad class, which represents a decorative 
**               Space.
*******************************************************************************/

#include <iostream>

#include "Doodad.hpp"
#include "Space.hpp"
#include "constants.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor 
 */
Doodad::Doodad(char mapChar) 
  : Space(mapChar, true)
{
}

/**
 * Default constructor 
 */
Doodad::Doodad(int spaceID, char mapChar) 
  : Space(spaceID, mapChar, false)
{
}









// /**
//  * Setter functions
//  */
// void Space::setTop(Space* top)
// {
//   m_top = top;
// }



// /**
//  * Getter functions
//  */
// Space* Space::getTop()
// {
//   return m_top;
// }

Doodad::~Doodad()
{
}