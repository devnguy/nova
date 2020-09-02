/*******************************************************************************
** Description:  Implementation of Map class.
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Map.hpp"
#include "Space.hpp"
#include "Wall.hpp"
#include "Floor.hpp"
#include "Doodad.hpp"
#include "Door.hpp"
#include "Event.hpp"
#include "SupplyCache.hpp"
#include "DataLog1.hpp"
#include "DataLog2.hpp"
#include "DataLog3.hpp"
#include "Enemy.hpp"

#include "Player.hpp"
#include "InfectedCrew.hpp"
#include "InfectedScientist.hpp"
#include "InfectedEngineer.hpp"
#include "NihilanInfestor.hpp"
#include "NihilanStalker.hpp"
#include "Aurora.hpp"

#include "AugmentCK.hpp"
#include "AugmentAtp.hpp"
#include "AugmentSda.hpp"
#include "AugmentOptik.hpp"
#include "Wrench.hpp"
#include "FissionDagger.hpp"
#include "WarpBlade.hpp"
#include "FusionCore.hpp"

#include "constants.hpp"
#include "util.hpp"


using std::cout;
using std::endl;
using std::string;
using std::vector;


/**
 * Default constructor 
 */
Map::Map() 
  : m_cols(MAP_COLS)
  , m_rows(MAP_ROWS)
  , m_event2Triggered(false)
  , m_event3Triggered(false)
  , m_auroraDefeated(false)
  , m_stepsRemaining(400)
{
  importMapFromFile();

  // Map must be imported before size can be set.
  setSize(m_map.size());
  connectMap();
  fillSupplyCaches();
  fillEnemySpaces();
}

/**
 * Imports the game's map from map.txt file. Initializes m_map Spaces 
 * and player location.
 */
void Map::importMapFromFile()
{
  char charFromFile;
  string inputFileName = "map.txt";
  int currentLocation = 0;
  int dataLogCount = 0;

  std::ifstream inputFile(inputFileName);

  if (inputFile) {
    
    while (!inputFile.eof()) {
      while ((inputFile >> std::noskipws >> charFromFile) 
        && charFromFile != '\n') {

        if (charFromFile == WALL_CHAR) {
          m_map.push_back(new Wall(currentLocation));

        } else if (charFromFile == FLOOR_CHAR) {
          m_map.push_back(new Floor(currentLocation));

        } else if (charFromFile == DOOR_CHAR) {
          m_map.push_back(new Door(currentLocation));

        } else if (charFromFile == EVENT_CHAR) {
          m_map.push_back(new Event(currentLocation));

        } else if (charFromFile == SUPPLY_CACHE_CHAR) {
          m_map.push_back(new SupplyCache(currentLocation));

        } else if (charFromFile == ENEMY_CHAR) {
          m_map.push_back(new Enemy(currentLocation));

        // There should only be 3 DataLogs on the map. FIXME: better imp.
        } else if (charFromFile == DATA_LOG_CHAR) {
          if (dataLogCount == 0) {
            m_map.push_back(new DataLog1(currentLocation));
          } else if (dataLogCount == 1) {
            m_map.push_back(new DataLog2(currentLocation));
          } else if (dataLogCount == 2) {
            m_map.push_back(new DataLog3(currentLocation));
          }
          ++dataLogCount;

        // Initialize player location.
        } else if (charFromFile == PLAYER_CHAR) {
          m_map.push_back(new Floor(currentLocation));
          setPlayerLoc(currentLocation);
          m_map[currentLocation]->updateSpace();

        } else {
          m_map.push_back(new Doodad(currentLocation, charFromFile));
        }
        ++currentLocation;
      }
    }

    clearConsole();
    cout << "AURORA: Initializing SKTx86 Imperius map module." << ".\n\n";
  } else {
    clearConsole();
    cout << "AURORA: An error occurred." << endl;
    cout << "AURORA: Unable to initialize map module." << ".\n\n";
  }
}

/**
 * Fills SupplyCache Spaces with Items. Called during Map construction.
 */
void Map::fillSupplyCaches()
{
  for (int i = 0; i < m_size; ++i) {
    if (dynamic_cast<SupplyCache*>(m_map[i])) {
      if (i == AUGMENT_CK_LOC) {
        m_map[i]->setContainedItem(new AugmentCK);

      } else if (i == WRENCH_LOC) {
        m_map[i]->setContainedItem(new Wrench);
        
      } else if (i == AUGMENT_SDA_LOC) {
        m_map[i]->setContainedItem(new AugmentSda);
        
      } else if (i == FUSION_CORE_LOC) {
        m_map[i]->setContainedItem(new FusionCore);

      } else if (i == AUGMENT_ATP_LOC) {
        m_map[i]->setContainedItem(new AugmentAtp);

      } else if (i == AUGMENT_OPTIK_LOC) {
        m_map[i]->setContainedItem(new AugmentOptik);
        
      } else if (i == FISSION_DAGGER_LOC) {
        m_map[i]->setContainedItem(new FissionDagger);

      } else if (i == WARP_BLADE_LOC) {
        m_map[i]->setContainedItem(new WarpBlade);
      }
    }
  }
}

/**
 * Fills SupplyCache Spaces with Items. Called during Map construction.
 */
void Map::fillEnemySpaces()
{
  for (int i = 0; i < m_size; ++i) {
    if (dynamic_cast<Enemy*>(m_map[i])) {
      if (i == INFECTED_CREW_LOC) {
        m_map[i]->setContainedEnemy(new InfectedCrew);

      } else if (i == INFECTED_SCIENTIST_LOC_1) {
        m_map[i]->setContainedEnemy(new InfectedScientist);

      } else if (i == INFECTED_SCIENTIST_LOC_2) {
        m_map[i]->setContainedEnemy(new InfectedScientist);

      } else if (i == INFECTED_ENGINEER_LOC) {
        m_map[i]->setContainedEnemy(new InfectedEngineer);

      } else if (i == NIHILAN_INFESTOR_LOC) {
        m_map[i]->setContainedEnemy(new NihilanInfestor);

      } else if (i == NIHILAN_STALKER_LOC) {
        m_map[i]->setContainedEnemy(new NihilanStalker);
      }
    }

    if (i == MAP_EVENT_AURORA) {
      m_map[i]->setContainedEnemy(new Aurora);
      
    }
  }
}




/**
 * Displays the map by calling getMapChar.
 */
void Map::displayMap()
{
  cout << "Self destruct in: " << m_stepsRemaining << endl;
  for (int i = 0; i < m_size; ++i) {
    cout << m_map[i]->getMapChar();

    // if (m_map[i]->getHoldsPlayer()) {
    //   cout << "ID: " << m_map[i]->getSpaceID() << endl; // FIXME TESTING
    // }

    if ((i + 1) % m_cols == 0) {
      cout << endl;
    }
  }
}

/**
 * Connects each space's top, right, left, bottom data members.
 * FIXME: This function needs to be cleaned/broken up
 */
void Map::connectMap()
{
  Space* currentSpace;
  for (int i = 0; i < m_size; ++i) {
    currentSpace = m_map[i];
      
    // Top left corner
    if (i == 0) {
      m_map[i]->setRight(m_map[i + 1]);
      m_map[i]->setBottom(m_map[i + m_cols]);

    // Top side, excluding corners
    } else if (i < m_cols && i != 0 && i != m_cols) {
      m_map[i]->setLeft(m_map[i - 1]);
      m_map[i]->setRight(m_map[i + 1]);
      m_map[i]->setBottom(m_map[i + m_cols]);

    // Top right corner
    } else if (i == m_cols) {
      m_map[i]->setLeft(m_map[i - 1]);
      m_map[i]->setBottom(m_map[i + m_cols]);

    // Left side, excluding corners
    } else if ((i + 1) % m_cols == 1 && i != 0 && i != MAP_BOTTOM_LEFT) {
      m_map[i]->setTop(m_map[i - m_cols]);
      m_map[i]->setRight(m_map[i + 1]);
      m_map[i]->setBottom(m_map[i + m_cols]);

    // Right side, excluding corners
    } else if ((i + 1) % m_cols == 0 && i != m_cols && i != m_size - 1) {
      m_map[i]->setTop(m_map[i - m_cols]);
      m_map[i]->setLeft(m_map[i - 1]);
      m_map[i]->setBottom(m_map[i + m_cols]);

    // Bottom left corner
    } else if (i == MAP_BOTTOM_LEFT) {
      m_map[i]->setRight(m_map[i + 1]);
      m_map[i]->setTop(m_map[i - m_cols]);

    // Bottom side, excluding corners
    } else if (i > MAP_BOTTOM_LEFT && i < m_size - 1) {
      m_map[i]->setLeft(m_map[i - 1]);
      m_map[i]->setRight(m_map[i + 1]);
      m_map[i]->setTop(m_map[i - m_cols]);

    // Bottom right corner
    } else if (i == m_size - 1) {
      m_map[i]->setLeft(m_map[i - 1]);
      m_map[i]->setTop(m_map[i - m_cols]);

    // Middle
    } else {
      m_map[i]->setTop(m_map[i - m_cols]);
      m_map[i]->setLeft(m_map[i - 1]);
      m_map[i]->setRight(m_map[i + 1]);
      m_map[i]->setBottom(m_map[i + m_cols]);
    }
  }
}


/**
 * Takes a pointer to the Player so that their location can be updated, and 
 * a direction in the from of an int.
 * Checks if the Space isWalkable and moves the player or prints a message.
 */
void Map::handleMovement(Player* playerPtr, int direction)
{
  Space* nextSpace;
  int newPlayerLoc;

  // Set nextSpace and newPlayerLoc depending on desired movement.
  if (direction == MOVE_UP) {
    nextSpace = m_map[m_playerLoc]->getTop();
    newPlayerLoc = m_playerLoc - m_cols;

  } else if (direction == MOVE_LEFT) {
    nextSpace = m_map[m_playerLoc]->getLeft();
    newPlayerLoc = m_playerLoc - 1;

  } else if (direction == MOVE_RIGHT) {
    nextSpace = m_map[m_playerLoc]->getRight();
    newPlayerLoc = m_playerLoc + 1;

  } else if (direction == MOVE_DOWN) {
    nextSpace = m_map[m_playerLoc]->getBottom();
    newPlayerLoc = m_playerLoc + m_cols;
  }

  // nextSpace must be properly assigned and isWalkable.
  if (nextSpace && nextSpace->getIsWalkable()) {
    --m_stepsRemaining;
    updatePlayerLoc(playerPtr, nextSpace, newPlayerLoc);

    cout << m_playerLoc << endl;  //FIXME testing

    handleMapEvent(playerPtr, newPlayerLoc);

  } else {
    handleNoMovementMessage(nextSpace);
  }
  displayMap();
}

/**
 * Takes a pointer to a Player and sets their location as the int passed in.
 */
void Map::updatePlayerLoc(Player* playerPtr, Space* nextSpace, int newLoc)
{
  // Update old Space
  m_map[m_playerLoc]->updateSpace(playerPtr);
  // Update new space
  nextSpace->updateSpace(playerPtr);
  // Update playerLoc
  setPlayerLoc(newLoc);
  playerPtr->setLocation(newLoc);
}


/**
 * Prints a message depending on if the attempted move was into a locked 
 * Door or a Wall/Doodad.
 */
void Map::handleNoMovementMessage(Space* unwalkableSpace)
{
  if (dynamic_cast<Door*>(unwalkableSpace)) {
    if (unwalkableSpace->getSpaceID() == DOOR_1) {
      cout << "Access denied. That door is locked." << endl;
    } else if (unwalkableSpace->getSpaceID() == DOOR_2) {
      cout << "Access denied. Authentication key required." << endl;
    } else if (unwalkableSpace->getSpaceID() == DOOR_3) {
      cout << "Access denied. Reactor must be repaired." << endl;
    } else if (unwalkableSpace->getSpaceID() == DOOR_4) {
      cout << "Access denied. FTL Engine must be repaired." << endl;
    }
  } else {
    cout << "Can't move there." << endl;
  }
}

/**
 * Triggers the appropriate map event based on the Player's location.
 */
void Map::handleMapEvent(Player* playerPtr, int playerLoc)
{
  // Aurora opens supply room door
  if (playerLoc == MAP_EVENT_1) {
    triggerMapEventOpenDoor1();
  }
  // Having the CK Augment opens main deck door
  if (playerPtr->getHasAugmentCK() && !m_event2Triggered) {
    triggerMapEventOpenDoor2();
  }

  // Repairing reactor opens engine room door
  if (playerPtr->getHasRepairedReactor() && !m_event3Triggered) {
    triggerMapEventOpenDoor3();
  }

  // Repairing engine opens synapse bridge door    
  if (playerLoc == MAP_EVENT_ENGINE) {
    triggerMapEventOpenDoor4();

  // Stepping onto Aurora space triggers combat
  } else if (playerLoc == MAP_EVENT_AURORA) {
    m_map[MAP_EVENT_AURORA]->triggerSpace(playerPtr);
    triggerMapEventAurora(playerPtr);
  }
}

/**
 * Unlocks the Door1 at 333 if it is locked.
 */
void Map::triggerMapEventOpenDoor1()
{

  if (!(m_map[DOOR_1]->getSpaceTriggered())) {
    clearConsole();

    cout << "Security protocol " << DOOR_1 
      << ": Access denied. Authentication key required." << endl << endl;

    pressEnterToContinue();

    m_map[DOOR_1]->triggerSpace();

    cout << "AURORA: \"Good evening, Employee 0162. Backup power has " << endl; 
    cout << "        allowed me to open the door to the northwestern " << endl;
    cout << "        supply room. I detect nano-augmentation found in " << endl;
    cout << "        that room may help.\"" << endl << endl;

    pressEnterToContinue();

    displayMap();
  }
}

/**
 * Unlocks the Door2 at 449 if it is locked.
 */
void Map::triggerMapEventOpenDoor2()
{
  m_event2Triggered = true;

  if (!(m_map[DOOR_2]->getSpaceTriggered())) {
    m_map[DOOR_2]->triggerSpace();
  }
}

/**
 * Unlocks the Door3 at 786 after main power is restored. FIXME
 */
void Map::triggerMapEventOpenDoor3()
{
  m_event3Triggered = true;

  if (!(m_map[DOOR_3]->getSpaceTriggered())) {

    // Unlock door.
    m_map[DOOR_3]->triggerSpace();

    // Print the message.
    clearConsole();

    cout << "You carefully place the Reserve Fusion Core in the Reactor." 
      << endl << endl;
    pressEnterToContinue();

    cout << "AURORA: \"Good evening, Employee 0162. Power has been fully " 
      << endl;
    cout << "        restored to the SKTx86 Imperius. Access has been granted " 
      << endl;
    cout << "        to the FTL Engine Room.\"" << endl << endl;
    pressEnterToContinue();

    displayMap();
  }
}

/**
 * Unlocks the Door3 at 802 after engine has been repaired.
 */
void Map::triggerMapEventOpenDoor4()
{
  if (!(m_map[DOOR_4]->getSpaceTriggered())) {
    // Unlock door.
    m_map[DOOR_4]->triggerSpace();
  
    // Print the message.
    clearConsole();

    cout << "-----FTL ENGINE ROOM-----" << endl;
    cout << "You activate the automated FTL engine repair system." 
      << endl << endl;
    pressEnterToContinue();

    cout << "You hear mechanical whirring and the collision of heavy metals." 
      << endl;
    cout << "You see a symphony of large robotic arms dart across the room "
      << endl;
    cout << "in uniformity." 
      << endl << endl;
    pressEnterToContinue();

    cout << "AURORA: \"Good evening, Employee 0162. The FTL Engine has been " 
      << endl;
    cout << "        been fully repaired and access has been granted to the " 
      << endl;
    cout << "        Synapse Bridge.\"" << endl << endl;
    pressEnterToContinue();

    displayMap();
  }
}


/**
 * Triggers the AURORA map event.
 */
void Map::triggerMapEventAurora(Player* playerPtr)
{
  if (playerPtr->getIsAlive() 
    && m_map[MAP_EVENT_AURORA]->getContainedEnemy() == nullptr) {
      setAuroraDefeated(true);
  }
}


/**
 * Setter functions
 */
void Map::setSize(int size)
{
  m_size = size;
}

void Map::setPlayerLoc(int playerLoc)
{
  m_playerLoc = playerLoc;
}

void Map::setAuroraDefeated(bool auroraDefeated)
{
  m_auroraDefeated = auroraDefeated;
}

void Map::setStepsRemaining(int stepsRemaining)
{
  m_stepsRemaining = stepsRemaining;
}


/**
 * Getter functions
 */
int Map::getSize()
{
  return m_size;
}

int Map::getPlayerLoc()
{
  return m_playerLoc;
}

int Map::getStepsRemaining()
{
  return m_stepsRemaining;
}

bool Map::getAuroraDefeated()
{
  return m_auroraDefeated;
}

/**
 * Destructor frees allocated memory.
 */
Map::~Map()
{
  for (int i = 0; i < m_size; ++i) {
    delete m_map[i];
  }
  m_map.clear();
}