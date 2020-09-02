/*******************************************************************************
** Description:  Implementation of Game class.
*******************************************************************************/

#include <iostream>

#include "Game.hpp"
#include "Map.hpp"
#include "constants.hpp"
#include "util.hpp"
#include "menu.hpp"


using std::cout;
using std::endl;

/**
 * Default constructor initializes m_map and m_player.
 */
Game::Game() 
  : m_map(new Map)
  , m_player(new Player)
{
}

/**
 * Displays the introduction and objective of the game. Then calls 
 * handleGameLoop to continue the game.
 */
void Game::start()
{
  clearConsole();
  cout << "[ . . . ]" << endl << endl;
  pressEnterToContinue();
  
  cout << "[ . . . ]" << endl << endl;
  pressEnterToContinue();

  cout << "AURORA: \"Good evening, Employee 0162. I’ve awakened you " << endl;
  cout << "        from cryosleep to inform you that the SKTx86 Imperius " 
    << endl;
  cout << "        has sustained critical damage. Automatic self-destruct " 
    << endl; 
  cout << "        sequences have been activated.\"" << endl << endl;
  pressEnterToContinue();

  cout << "AURORA: \"Crew status: Presumed dead.\"" << endl << endl;
  pressEnterToContinue();

  cout << "AURORA: \"Critical failures found: " << endl;
  cout << "        Reactor, FTL Engine, Synapse Bridge.\"" << endl << endl;
  pressEnterToContinue();

  cout << "AURORA: \"Repair critical failures to override self-destruct.\"" 
    << endl << endl;
  pressEnterToContinue();

  clearConsole();
  cout << "AURORA: \"Initializing SKTx86 Imperius map module.\"" 
    << endl << endl;
  pressEnterToContinue();

  handleGameLoop();
}

/**
 * Calls displayMenu to start the game loop. Once win/loss conditions are 
 * met, loop will exit within displayMenu.
 */
void Game::handleGameLoop()
{
  m_map->displayMap();

  displayMenu(m_map, m_player); // Loop control within this function

  // Self destruct.
  if (m_map->getStepsRemaining() <= 0) {
    clearConsole();
    cout << "AURORA: \"Self-destruct timer expired. Self-destruct in 3... 2...";
    cout << " 1...\"" << endl << endl;
    pressEnterToContinue();
    cout << "[ . . . ]" << endl << endl;
    pressEnterToContinue();
    cout << "YOU DIED..." << endl << endl;
    pressEnterToContinue();

  // Died in combat.
  } else if (!(m_player->getIsAlive())) {
    clearConsole();

    // Print different message depending on if AURORA killed the player.
    if (m_map->getPlayerLoc() == MAP_EVENT_AURORA) {
      cout << "AURORA: \"Your infinitesimal life leaves you, lit-t-t-t-tle fleshling-g-gg€ƒ‡‰Æ¶®¥žš•Àç¶•.\""
        << endl << endl;

    } else {
      cout << "Covered in blood, you lay collapsed on the cold metal floor." 
        << endl;
      cout << "You notice a Nihilan Infestor approach your crippled body." 
        << endl;
      cout << "You feel its hand tightly grasp your head. As you struggle, you"
        << endl;
      cout << "realize you've lost control of your augments. Your body rises "
        << endl;
      cout << "from the floor, but not by your own will."
        << endl << endl;
    }
    pressEnterToContinue();

    cout << "[ . . . ]" << endl << endl;
    pressEnterToContinue();

    cout << "GAME OVER..." << endl << endl;
    pressEnterToContinue();

  // Defeated Aurora.
  } else if (m_map->getAuroraDefeated()) {
    displayWinMessage();
  }
}

/**
 * Informs the player they won.
 */
void Game::displayWinMessage()
{
  clearConsole();
  cout << "AURORA has been destroyed, and with her, your chances of returning \n";
  cout << "home. She was the only one who could reroute and pilot the \n";
  cout << "Imperius back to the UEF station.\n\n";
  pressEnterToContinue();

  cout << "With the mission failed and no resources to transport back, \n";
  cout << "you contemplate your existence, and the future of the human \n"; 
  cout << "race. You consider the option of drifting further into the void..\n\n";
  pressEnterToContinue();

  cout << "Entering an escape pod, you set the coordinates for the \n";
  cout << "Nihilan home planet, Osiris1024...\n\n";
  pressEnterToContinue();

  cout << "YOU WIN" << endl << endl;
  pressEnterToContinue();
}


/**
 * Destructor frees memory.
 */
Game::~Game()
{
  delete m_map;
  delete m_player;
}