/*******************************************************************************
** Description:  Definition of Game class.
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Map.hpp"
#include "Player.hpp"


class Game {
  private:
    Map* m_map;
    Player* m_player;
    void displayWinMessage();

  
  public:
    Game();
    ~Game();
    void start();
    void handleGameLoop();




};

#endif


