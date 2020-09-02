/*******************************************************************************
** Description:  Implementation of SupplyCache class derived from Space.
*******************************************************************************/

#include <iostream>

#include "SupplyCache.hpp"
#include "Space.hpp"
#include "Item.hpp"
#include "constants.hpp"
#include "util.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor with no ID.
 */
SupplyCache::SupplyCache() 
  : Space(SUPPLY_CACHE_CHAR, true)
{
}

/**
 * Overloaded constructor initializes spaceID.
 */
SupplyCache::SupplyCache(int spaceID) 
  : Space(spaceID, SUPPLY_CACHE_CHAR, true)
{
}

/**
 * If SupplyCache contains an item, adds the item to Player Inventory 
 * and removes the item from SupplyCache.
 */
void SupplyCache::triggerSpace(Player* playerPtr)
{
  Item* supplyCacheItem;

  if (!m_spaceTriggered) {
    setSpaceTriggered(true);
    setOriginalChar(FLOOR_CHAR);

    if (getContainedItem()) {

      supplyCacheItem = getContainedItem();

      // Pickup message.
      clearConsole();
      cout << "Opened a Supply Cache." << endl << endl;
      pressEnterToContinue();
      supplyCacheItem->handlePickUpMessage();

      // Add item to Player Inventory.
      playerPtr->addToInventory(supplyCacheItem);
      // Remove item from SupplyCache.
      setContainedItem(nullptr);
    }
  }
}


/**
 * Destructor frees memory.
 */
SupplyCache::~SupplyCache()
{
  if (getContainedItem()) {
    delete m_containedItem;
    setContainedItem(nullptr);
  }
}