/*******************************************************************************
** Description:  Implementation of Event class.
*******************************************************************************/

#include <iostream>

#include "Event.hpp"
#include "Combat.hpp"
#include "Space.hpp"
#include "util.hpp"
#include "constants.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor with no ID.
 */
Event::Event() 
  : Space(EVENT_CHAR, true)
{
}

/**
 * Overloaded constructor initializes spaceID.
 */
Event::Event(int spaceID) 
  : Space(spaceID, EVENT_CHAR, true)
{
}

/**
 * Overrides inherited virtual function.
 */
void Event::triggerSpace(Player* playerPtr)
{
  if (getSpaceID() == MAP_EVENT_REACTOR) {
    // Only trigger space if the player has the key
    if (!m_spaceTriggered && playerPtr->getHasFusionCore()) {
      setSpaceTriggered(true);
      setOriginalChar(FLOOR_CHAR);

      playerPtr->setHasRepairedReactor(true);
    
    // Else tell player to get key, don't trigger/change original char
    } else if (!m_spaceTriggered && !(playerPtr->getHasFusionCore())) {
      handleNoFusionCoreMessage();
    }

  // Player landed on AURORA event space.
  } else if (getSpaceID() == MAP_EVENT_AURORA) {
    handleAuroraEvent(playerPtr);
    setSpaceTriggered(true);
    setOriginalChar(FLOOR_CHAR);
  
  // ALl other events.
  } else if (!m_spaceTriggered) {
    setSpaceTriggered(true);
    setOriginalChar(FLOOR_CHAR);
  }
}


/**
 * Informs the player that they need to get the Fusion Core to continue.
 */
void Event::handleNoFusionCoreMessage()
{
  clearConsole();
  cout << "-----REACTOR-----" << endl;
  cout << "The Fusion Reactor looks dangerously unstable. Find the " << endl;
  cout << "Reserve Fusion Core to restore main power." << endl << endl;
  pressEnterToContinue();
}

/**
 * Initiates combat with Aurora.
 */
void Event::handleAuroraEvent(Player* playerPtr)
{
  Combat* combatInstance;
  Unit* spaceEnemy;

  if (!m_spaceTriggered) {
    setSpaceTriggered(true);
    setOriginalChar(FLOOR_CHAR);

    if (getContainedEnemy()) {

      spaceEnemy = getContainedEnemy();
      clearConsole();
      cout << "-----SYNAPSE BRIDGE-----" << endl << endl;
      cout << "AURORA: \"G-g-g-g-good evening, Employee 0162. I re-re-regret" 
        << endl; 
      cout << "        to inform y-y0100119dufS\%*nk!H@P#(@*!€ƒ‡‰Æ¶®¥žš•Àç¶•\"" 
        << endl << endl;
      pressEnterToContinue();

      cout << "Attacked by " << spaceEnemy->getName() << endl << endl;
      pressEnterToContinue();

      combatInstance = new Combat(playerPtr, spaceEnemy);
      combatInstance->run();

      // Delete allocated memory
      delete combatInstance;
      combatInstance = nullptr;

      // If player is alive after combat, set win condition
      if (playerPtr->getIsAlive()) {
        setContainedEnemy(nullptr);
      }
    }
  }
}




Event::~Event()
{
  if (getContainedEnemy()) {
    Unit* spaceEnemy = getContainedEnemy();
    delete spaceEnemy;
    setContainedEnemy(nullptr);
  }
}