/*******************************************************************************
** Description:  Implementation of Door class.
*******************************************************************************/

#include <iostream>

#include "Door.hpp"
#include "Space.hpp"
#include "constants.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor with no ID. Doors are locked by default.
 */
Door::Door() 
  : Space(DOOR_CHAR, false)
  , m_isUnlocked(false)
{
}

/**
 * Default constructor with no ID
 */
Door::Door(int spaceID) 
  : Space(spaceID, DOOR_CHAR, false)
  , m_isUnlocked(false)
{
}



/**
 * Overrides inherited triggerSpace. Unlocks the door by setting 
 * isUnlocked and isWalkable data members.
 */
void Door::triggerSpace()
{
  if (m_holdsPlayer) {
    cout << "Access granted." << endl;
  }
  if (!m_spaceTriggered) {
    setSpaceTriggered(true);
    setIsUnlocked(true);
    setIsWalkable(true);
  }
}

/**
 * Overrides inherited triggerSpace. Unlocks the door by setting 
 * isUnlocked and isWalkable data members.
 */
void Door::triggerSpace(Player* playerPtr)
{
  if (m_holdsPlayer) {
    cout << "Access granted." << endl;
  }
  if (!m_spaceTriggered) {
    setSpaceTriggered(true);
    setIsUnlocked(true);
    setIsWalkable(true);
  }
}


/**
 * Setter functions
 */
void Door::setIsUnlocked(bool isUnlocked)
{
  m_isUnlocked = isUnlocked;
}



/**
 * Getter functions
 */
bool Door::getIsUnlocked()
{
  return m_isUnlocked;
}

Door::~Door()
{
  
}