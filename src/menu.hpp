/*******************************************************************************
** Description:  Definition of menu functions. Includes handler functions to 
**               facilitate simulating a buffer and creating a palindrome.
*******************************************************************************/ 

#ifndef MENU_HPP
#define MENU_HPP

#include "Map.hpp"
#include "Player.hpp"

void displayMenu(Map*, Player*);
void displayOptions();
void handleOpenInventory(Player*);
void displayInventoryOptions();

void displayPlayerStats(Player*);
void displayObjectives();


#endif