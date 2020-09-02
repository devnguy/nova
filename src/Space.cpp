/*******************************************************************************
** Description:  Implementation of Space class.
*******************************************************************************/

#include <iostream>

#include "Item.hpp"
#include "Space.hpp"
#include "Player.hpp"
// #include "Enemy.hpp" FIXME: will implement later
#include "constants.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor sets 
 */
Space::Space() 
  : m_top(nullptr)
  , m_right(nullptr)
  , m_left(nullptr)
  , m_bottom(nullptr)
  , m_spaceTriggered(false)
{
}

/**
 * Default constructor sets 
 */
Space::Space(char mapChar, bool isWalkable) 
  : m_top(nullptr)
  , m_right(nullptr)
  , m_left(nullptr)
  , m_bottom(nullptr)
  , m_mapChar(mapChar)
  , m_orginalChar(mapChar)
  , m_isWalkable(isWalkable)
  , m_spaceTriggered(false)
{
}

/**
 * Default constructor sets 
 */
Space::Space(int spaceID, char mapChar, bool isWalkable) 
  : m_top(nullptr)
  , m_right(nullptr)
  , m_left(nullptr)
  , m_bottom(nullptr)
  , m_mapChar(mapChar)
  , m_orginalChar(mapChar)
  , m_isWalkable(isWalkable)
  , m_spaceID(spaceID)
  , m_spaceTriggered(false)
  , m_containedItem(nullptr)
  , m_containedEnemy(nullptr)
{
}



/**
 * Changes the space from holding the player to being empty and vice versa. 
 * This needs to be called on the Space the player moves from AND also on 
 * the Space the player moves to.
 */
void Space::updateSpace()
{
  // Toggle current value
  setHoldsPlayer(!m_holdsPlayer);
  
  // Show player has moved to this Space, triggers Space event
  if (m_holdsPlayer) {
    setMapChar(PLAYER_CHAR);
    triggerSpace();
  // Player has just moved off this Space, restore
  } else {
    setMapChar(m_orginalChar);
  }
}

/**
 * Overloaded updateSpace function. Functionality is identical except it 
 * takes a pointer to a Player object to allow modification within 
 * triggerSpace.
 */
void Space::updateSpace(Player* playerPtr)
{
  setHoldsPlayer(!m_holdsPlayer);
  
  if (m_holdsPlayer) {
    setMapChar(PLAYER_CHAR);
    triggerSpace(playerPtr);

  } else {
    setMapChar(m_orginalChar);
  }
}



/**
 * triggerSpace is a virtual function. Only runs if m_spaceTriggered is 
 * false. By default, updates the map character so that it no longer 
 * displays an untriggered event.
 */
void Space::triggerSpace()
{
  if (!m_spaceTriggered) {
    setSpaceTriggered(true);
    setOriginalChar(FLOOR_CHAR);
  }
}

/**
 * Overloaded triggerSPace virtual function. Functionality is identical 
 * except taking a playerPtr allows the trigger to modify the Player object.
 */
void Space::triggerSpace(Player* playerPtr)
{
  if (!m_spaceTriggered) {
    setSpaceTriggered(true);
    setOriginalChar(FLOOR_CHAR);
  }
}



/**
 * Setter functions
 */
void Space::setTop(Space* top)
{
  m_top = top;
}

void Space::setRight(Space* right)
{
  m_right = right;
}

void Space::setLeft(Space* left)
{
  m_left = left;
}

void Space::setBottom(Space* bottom)
{
  m_bottom = bottom;
}

void Space::setMapChar(char mapChar)
{
  m_mapChar = mapChar;
}

void Space::setIsWalkable(bool isWalkable)
{
  m_isWalkable = isWalkable;
}

void Space::setHoldsPlayer(bool holdsPlayer)
{
  m_holdsPlayer = holdsPlayer;
}

void Space::setSpaceID(int spaceID)
{
  m_spaceID = spaceID;
}

void Space::setSpaceTriggered(bool spaceTriggered)
{
  m_spaceTriggered = spaceTriggered;
}

void Space::setOriginalChar(char originalChar)
{
  m_orginalChar = originalChar;
}

void Space::setContainedItem(Item* containedItem)
{
  m_containedItem = containedItem;
}

void Space::setContainedEnemy(Unit* containedEnemy)
{
  m_containedEnemy = containedEnemy;
}


/**
 * Getter functions
 */
Space* Space::getTop()
{
  return m_top;
}

Space* Space::getRight()
{
  return m_right;
}

Space* Space::getLeft()
{
  return m_left;
}

Space* Space::getBottom()
{
  return m_bottom;
}

char Space::getMapChar()
{
  return m_mapChar;
}

bool Space::getIsWalkable()
{
  return m_isWalkable;
}

bool Space::getHoldsPlayer()
{
  return m_holdsPlayer;
}

int Space::getSpaceID()
{
  return m_spaceID;
}

bool Space::getSpaceTriggered()
{
  return m_spaceTriggered;
}

char Space::getOriginalChar()
{
  return m_orginalChar;
}

Item* Space::getContainedItem()
{
  return m_containedItem;
}

Unit* Space::getContainedEnemy()
{
  return m_containedEnemy;
}

Space::~Space()
{
  
}