/*******************************************************************************
** Description:  Implementation of DataLog1 class derived from Space.
*******************************************************************************/

#include <iostream>
#include <unistd.h>

#include "DataLog1.hpp"
#include "Space.hpp"
#include "Item.hpp"
#include "constants.hpp"
#include "util.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor with no ID.
 */
DataLog1::DataLog1() 
  : Space(DATA_LOG_CHAR, true)
{
}

/**
 * Overloaded constructor initializes spaceID.
 */
DataLog1::DataLog1(int spaceID) 
  : Space(spaceID, DATA_LOG_CHAR, true)
{
}

/**
 * Prints a message when the Space is triggered.
 */
void DataLog1::triggerSpace(Player* playerPtr)
{
  if (!m_spaceTriggered) {
    setSpaceTriggered(true);
    setOriginalChar(FLOOR_CHAR);

    // Datalog message.
    clearConsole();
    cout << "Found Data Log 1. [DECRYPTING . . .]" << endl << endl;
    pressEnterToContinue();
    
    cout << "August 9th, 2593" << endl;
    cout << "Day 2 of Operation 1024" << endl << endl;
    cout << "\"Mining of Osiris1024 is well under way. I've informed " << endl;
    cout << "the commander of our discovery and success so far on " << endl;
    cout << "this mission and the celebrations at home have already " << endl;
    cout << "begun! We will be known as the crew members who saved " << endl;
    cout << "the entire United Earth Federation. With these resources, " << endl;
    cout << "we've ensured the survival of humanity at the hour of our " << endl;
    cout << "extinction.\"" << endl << endl;
    cout << "- Cpt. Robert Cozart, Employee 0001" << endl << endl;
    pressEnterToContinue();

    cout << "[ENDING . . .]" << endl << endl;
    pressEnterToContinue();
  }
}



/**
 * Destructor frees memory.
 */
DataLog1::~DataLog1()
{
}