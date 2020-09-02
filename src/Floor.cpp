/*******************************************************************************
** Description:  Implementation of Floor class.
*******************************************************************************/

#include <iostream>

#include "Floor.hpp"
#include "Space.hpp"
#include "constants.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor 
 */
Floor::Floor() 
  : Space(FLOOR_CHAR, true)
{
}

/**
 * Default constructor 
 */
Floor::Floor(int spaceID) 
  : Space(spaceID, FLOOR_CHAR, true)
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

Floor::~Floor()
{
}