/*******************************************************************************
** Description:  Implementation of Enemy class derived from Unit.
*******************************************************************************/

#include <iostream>

#include "Enemy.hpp"
#include "Space.hpp"
#include "Item.hpp"
#include "constants.hpp"
#include "util.hpp"
#include "Combat.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor with no ID.
 */
Enemy::Enemy() 
  : Space(ENEMY_CHAR, true)
{
}

/**
 * Overloaded constructor initializes spaceID.
 */
Enemy::Enemy(int spaceID) 
  : Space(spaceID, ENEMY_CHAR, true)
{
}

/**
 * If Space contains an Enemy, initializes combat and removes the Enemy.
 */
void Enemy::triggerSpace(Player* playerPtr)
{
  Combat* combatInstance;
  Unit* spaceEnemy;

  if (!m_spaceTriggered) {
    setSpaceTriggered(true);
    setOriginalChar(FLOOR_CHAR);

    if (getContainedEnemy()) {

      spaceEnemy = getContainedEnemy();

      // Pickup message.
      clearConsole();
      cout << "Attacked by " << spaceEnemy->getName() << endl << endl;
      pressEnterToContinue();

      combatInstance = new Combat(playerPtr, spaceEnemy);
      combatInstance->run();

      // Delete allocated memory
      delete combatInstance;

      delete spaceEnemy;
      setContainedEnemy(nullptr);
    }
  }
}


/**
 * Destructor frees memory.
 */
Enemy::~Enemy()
{
  if (getContainedItem()) {
    delete m_containedItem;
    setContainedItem(nullptr);
  }
}