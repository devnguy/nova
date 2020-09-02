/*******************************************************************************
** Description:  Implementation of DataLog2 class derived from Space.
*******************************************************************************/

#include <iostream>
#include <unistd.h>

#include "DataLog2.hpp"
#include "Space.hpp"
#include "Item.hpp"
#include "constants.hpp"
#include "util.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor with no ID.
 */
DataLog2::DataLog2() 
  : Space(DATA_LOG_CHAR, true)
{
}

/**
 * Overloaded constructor initializes spaceID.
 */
DataLog2::DataLog2(int spaceID) 
  : Space(spaceID, DATA_LOG_CHAR, true)
{
}

/**
 * Prints a message when the Space is triggered.
 */
void DataLog2::triggerSpace(Player* playerPtr)
{
  if (!m_spaceTriggered) {
    setSpaceTriggered(true);
    setOriginalChar(FLOOR_CHAR);

    // Datalog message.
    clearConsole();
    cout << "Found Data Log 2. [DECRYPTING . . .]" << endl << endl;
    pressEnterToContinue();
    
    cout << "August 13th, 2593" << endl;
    cout << "Day 6 of Operation 1024" << endl << endl;
    cout << "\"This marks the 8th crew member returning from the " << endl;
    cout << "Osiris1024 surface who seems to have been infected with " << endl;
    cout << "the Nova Virus. Reports show that the cyborg inhabitants " << endl;
    cout << "of the planet, known as the Nihilan, have the ability to " << endl;
    cout << "override the security of our installed Nano-Augmentation. "<< endl;
    cout << "Once the human neural system has been hijacked, the virus " << endl; cout << "is installed, and the host is used as a vessel. I've " << endl;
    cout << "attached the medical report.\"" << endl << endl;
    pressEnterToContinue();

    cout << "MEDICAL REPORT" << endl;
    cout << "Name and ID: Isaac Benavidez, Employee 0038" << endl;
    cout << "Occupation: Engineer" << endl;
    cout << "Symptoms: Patient remains in a hostile, zombie-like state." << endl;
    cout << "Eyes are pitch black, mouth-agape, and exhibits non-stop " << endl;
    cout << "violent spasms due to Nano-Augmentation malfunctions. " << endl;
    cout << "Growls and screams are incomprehensible. Patient passes " << endl;
    cout << "consciousness tests." << endl << endl;
    cout << "- Dr. Luis Villarreal, Employee 0242" << endl << endl;
    pressEnterToContinue();

    cout << "[ENDING . . .]" << endl << endl;
    pressEnterToContinue();
  }
}


/**
 * Destructor frees memory.
 */
DataLog2::~DataLog2()
{
}