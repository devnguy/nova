/*******************************************************************************
** Description:  Functions that involve menus and displaying information to 
**               to the player.
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "inputValidation.hpp"
#include "menu.hpp"
#include "util.hpp"   // Included for clearConsole function
#include "Map.hpp"
#include "Player.hpp"
#include "constants.hpp"


using std::cout;
using std::endl;
using std::string;

// Movement
const int OPEN_INVENTORY = 5;
const int QUIT = 6;

// Inventory
const int VIEW_WEAPON = 1;
const int VIEW_AUGMENTS = 2;
const int VIEW_KEY_ITEMS = 3;
const int VIEW_STATS = 4;
const int VIEW_OBJECTIVES = 5;
const int INVENTORY_BACK = 6;

/**
 * Displays the main menu for the user. Options include movement 
 * and opening the inventory. When the user chooses an option, calls 
 * the corresponding function.
 */
void displayMenu(Map* mapPtr, Player* playerPtr) 
{
  int choice;

  do {
    displayOptions();
    choice = getInt(1, QUIT);

    if (choice == MOVE_UP) {
      mapPtr->handleMovement(playerPtr, MOVE_UP);
    } else if (choice == MOVE_LEFT) {
      mapPtr->handleMovement(playerPtr, MOVE_LEFT);
    } else if (choice == MOVE_RIGHT) {
      mapPtr->handleMovement(playerPtr, MOVE_RIGHT);
    } else if (choice == MOVE_DOWN) {
      mapPtr->handleMovement(playerPtr, MOVE_DOWN);
    } else if (choice == OPEN_INVENTORY) {
      handleOpenInventory(playerPtr);
      mapPtr->displayMap();
    }
  } while (choice != QUIT
      && playerPtr->getIsAlive()
      && !(mapPtr->getAuroraDefeated()) 
      && (mapPtr->getStepsRemaining() > 0));

  if (choice == QUIT) {
    cout << "Quitting game." << endl;
  }
}

/**
 * Displays the menu options.
 */
void displayOptions()
{
  cout << "Please choose from one of the following:" << endl;
  cout << "1. Move Up" << endl;
  cout << "2. Move Left" << endl;
  cout << "3. Move Right" << endl;
  cout << "4. Move Down" << endl;
  cout << "5. Menu" << endl;
  cout << "6. Quit" << endl;
}

/**
 * Displays a menu so that the user can choose which items they currently 
 * have in possession to view.
 */
void handleOpenInventory(Player* playerPtr)
{
  clearConsole();
  int choice;

  do {
    displayInventoryOptions();
    choice = getInt(1, INVENTORY_BACK);

    if (choice == VIEW_WEAPON) {
      playerPtr->displayWeapon();

    } else if (choice == VIEW_AUGMENTS) {
      playerPtr->displayAugments();

    } else if (choice == VIEW_KEY_ITEMS) {
      playerPtr->displayKeyItems();

    } else if (choice == VIEW_STATS) {
      displayPlayerStats(playerPtr);

    } else if (choice == VIEW_OBJECTIVES) {
      displayObjectives();
    }
  } while (choice != INVENTORY_BACK);
}

/**
 * Displays the the inventory menu options.
 */
void displayInventoryOptions()
{
  cout << "Menu:" << endl;
  cout << "1. View weapon" << endl;
  cout << "2. View Nano-Augments" << endl;
  cout << "3. View Key Items" << endl;
  cout << "4. Stats" << endl;
  cout << "5. Objectives" << endl;
  cout << "6. Back" << endl;
}

/**
 * Displays player stats. Called when viewing the inventory menu.
 */
void displayPlayerStats(Player* playerPtr)
{
  clearConsole();
  cout << "-----EMPLOYEE 0162-----" << endl;
  cout << "Class: Netrunner" << endl;
  cout << "Ability: 33\% chance when attacked to corrupt the attacker's \n";
  cout << "   neural systems, reducing the damage they deal. Scales \n";
  cout << "   with armor.\n";
  cout << "Health: " 
    << playerPtr->getHealth() << " + " << playerPtr->getHealthMod() << endl;
  cout << "Attack: " 
    << playerPtr->getAttack() << " + " << playerPtr->getAttackMod() << endl;
  cout << "Defense: " 
    << playerPtr->getDefense() << " + " << playerPtr->getDefenseMod() << endl;
  cout << "Armor: " 
    << playerPtr->getArmor() << " + " << playerPtr->getArmorMod() << endl;
  cout << "Initiative: " 
    << playerPtr->getInitiative() << " + " << playerPtr->getInitiativeMod() 
    << endl;
  cout << "Crit chance: " 
    << playerPtr->getCrit() << " + " << playerPtr->getCritMod() 
    << endl;
  cout << "Attacks/turn: " 
    << playerPtr->getDice() << " + " << playerPtr->getDiceMod() 
    << endl << endl;
}

/**
 * Displays game objectives.
 */
void displayObjectives()
{
  clearConsole();
  cout << "-----OBJECTIVES-----" << endl;
  cout << "1. Find the CK-372 Augment that allows you to override ship " << endl;
  cout << "   security and open doors." << endl << endl;
  cout << "2. Find the Reserve Fusion Core. Place it in the Reactor to " << endl;
  cout << "   restore main power to the Imperius." << endl << endl;
  cout << "3. Use main power to activate the automated FTL Engine " << endl;
  cout << "   repair system in the Engine Room" << endl << endl;
  cout << "4. Board the Synapse Bridge to override self-destruct " << endl;
  cout << "   sequences and return home." << endl << endl;
}
