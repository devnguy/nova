/*******************************************************************************
** Description:  Implementation of Wall class.
*******************************************************************************/

#include <iostream>

#include "Wall.hpp"
#include "Space.hpp"
#include "constants.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor with no ID
 */
Wall::Wall() 
  : Space(WALL_CHAR, false)
{
}

/**
 * Default constructor with no ID
 */
Wall::Wall(int spaceID) 
  : Space(spaceID, WALL_CHAR, false)
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

Wall::~Wall()
{
  
}