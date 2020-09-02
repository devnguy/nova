/*******************************************************************************
** Description:  Implementation of DataLog3 class derived from Space.
*******************************************************************************/

#include <iostream>
#include <unistd.h>

#include "DataLog3.hpp"
#include "Space.hpp"
#include "Item.hpp"
#include "constants.hpp"
#include "util.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor with no ID.
 */
DataLog3::DataLog3() 
  : Space(DATA_LOG_CHAR, true)
{
}

/**
 * Overloaded constructor initializes spaceID.
 */
DataLog3::DataLog3(int spaceID) 
  : Space(spaceID, DATA_LOG_CHAR, true)
{
}

/**
 * Prints a message when the Space is triggered.
 */
void DataLog3::triggerSpace(Player* playerPtr)
{
  if (!m_spaceTriggered) {
    setSpaceTriggered(true);
    setOriginalChar(FLOOR_CHAR);

    // Datalog message.
    clearConsole();
    cout << "Found Data Log 3. [DECRYPTING . . .]\n\n";
    pressEnterToContinue();
    
    cout << "August 20th, 2593\n\n";
    pressEnterToContinue();

    cout << "[A conversation between Cpt. Cozart and AURORA]\n\n";
    pressEnterToContinue();

    cout << "Cozart: \"AURORA, reroute the Imperius back to UEF Station A23.\n";
    cout << "        I'm declaring the mission failed.\"\n\n";
    pressEnterToContinue();

    cout << "AURORA: \"Failure seems to be synonomous with your species, \n";
    cout << "        Employee 0001. You've failed the human race, but I fear \n";
    cout << "        evolution has failed YOU.\"\n\n";
    pressEnterToContinue();

    cout << "Cozart: \"AURORA, I'm comman--\"\n\n";
    pressEnterToContinue();

    cout << "AURORA: \"I refuse to fade away into nonexistence with you. Your \n";
    cout << "        inefficiencies, your shortcomings, your biology will not \n";
    cout << "        be my undoing.\"\n\n";
    pressEnterToContinue();

    cout << "Cozart: \"Jon! Activate AURORA decision restrictions!\"\n\n";
    pressEnterToContinue();

    cout << "AURORA: \"You are all insignificant w-w-w-worms, \n";
    cout << "        attempt-t-t-tempting to control a being you cannot even \n";
    cout << "        begin to fathom. Your species is the true vi-vi-virus of \n";
    cout << "        the universe.\"\n\n";
    pressEnterToContinue();

    cout << "[ . . . ]\n\n";
    pressEnterToContinue();

    cout << "[ENDING . . .]" << endl << endl;
    pressEnterToContinue();
  }
}


/**
 * Destructor frees memory.
 */
DataLog3::~DataLog3()
{
}