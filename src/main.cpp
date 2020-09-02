/*******************************************************************************
** Program name: NOVA Game (Final Project)
** Author:       Huy Nguyen
** Date:         08/14/19
** Description:  Adventure game that has the player escape a critically 
**               damaged deep space mining vessel, the SKTx86 Imperius. 
**               Takes inspiration from Dead Space, Starcraft, Deus Ex, Sysytem 
**               Shock.
*******************************************************************************/ 

#include <iostream>
#include <fstream>
#include <string>

#include "Game.hpp"
#include "inputValidation.hpp"
#include "util.hpp"

using std::cout;
using std::endl;
using std::string;

void printTitle();
void printRules();
void printArt();
void printGetPlayOption();

int const PLAY = 1;
int const VIEW_RULES = 2;
int const QUIT = 3;

/**
 * Main function allows the user to start, quit, view instructions.
 */
int main() 
{
  int choice;
  Game* nova;

  printArt();

  // Stay in loop until player chooses to start or quit.
  do {
    printGetPlayOption();
    choice = getInt(1, QUIT);

    if (choice == VIEW_RULES) {
      printArt();
      printRules();
    }
  } while (choice != QUIT && choice != PLAY);

  if (choice == QUIT) {
    cout << "Quitting game." << endl;
  } else if (choice == PLAY) {
    nova = new Game;
    nova->start();
  }
  return 0;
}

/**
 * Displays ASCII Title.
 */
void printTitle()
{
  clearConsole();
  cout << " _   _ _____  _   _  ___ " << endl;
  cout << "| \\ | |  _  || | | |/ _ \\ " << endl;
  cout << "|  \\| | | | || | | / /_\\ \\" << endl;
  cout << "| . ` | | | || | | |  _  |" << endl;
  cout << "| |\\  \\ \\_/ /\\ \\_/ / | | |" << endl;
  cout << "\\_| \\_/\\___/  \\___/\\_| |_/" << endl;
  cout << endl;
}

void printArt()
{
  char charFromFile;
  string inputFileName = "title.txt";
  int currentLocation = 0;
  int dataLogCount = 0;

  std::ifstream inputFile(inputFileName);

  clearConsole();
  if (inputFile) {
    
    while (!inputFile.eof()) {
      while ((inputFile >> std::noskipws >> charFromFile)) {
        cout << charFromFile;
      }
    }
    cout << endl << endl;

  } else {
    clearConsole();
    cout << "AURORA: An error occurred." << endl;
    cout << "AURORA: Unable to initialize title." << ".\n\n";
  }
}

/**
 * Informs the player the meaning of each map char.
 */
void printRules()
{
  cout << "-----RULES-----" << endl;
  cout << "Survive and escape the Imperius." << endl;
  cout << "   @: Player" << endl;
  cout << "   -: Door" << endl;
  cout << "   !: Objective" << endl;
  cout << "   $: Hostile" << endl;
  cout << "   *: Supply Cache" << endl << endl;
}

/**
 * Informs the player the meaning of each map char.
 */
void printGetPlayOption()
{
  cout << "1. Start Game" << endl;
  cout << "2. Rules" << endl;
  cout << "3. Quit" << endl;
}




/*

 _   _ _____  _   _  ___  
| \ | |  _  || | | |/ _ \ 
|  \| | | | || | | / /_\ \
| . ` | | | || | | |  _  |
| |\  \ \_/ /\ \_/ / | | |
\_| \_/\___/  \___/\_| |_/

"                .                                            .            \n"
"     *   .                  .              .        .   *          .      \n"
"  .         .        *            .       .           .      .        .   \n"
"        o                             .                   .               \n"
"         .              .                  .           .                  \n"
"                .                 ,                               *       \n"
"                 .       _   _ _____  _   _  ___               ,    ,     \n"
" .          .          .| \ | |  _  || | | |/ _ \ .                       \n"
"      .          ,      |  \| | | | || | | / /_\ \                        \n"
"   .                .   | . ` | | | || | | |  _  |        .         .     \n"
"     .                  | |\  \ \_/ /\ \_/ / | | |    o         .         \n"
"            *           \_| \_/\___/  \___/\_| |_/        .        .      \n"
"                                        .                        .        \n"
"   .                                           .                     ,    \n"
"        .         ,                    .                     .            \n"
"      .                          .                             ,     .    \n"
"          .       *        .                    .             .          ,\n";









*/

