/*******************************************************************************
** Description:  Definition of Map class.
*******************************************************************************/

#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include "Space.hpp"
#include "Player.hpp"

class Map {
  private:
    int m_cols;
    int m_rows;
    int m_size;
    int m_playerLoc;

    bool m_event2Triggered;
    bool m_event3Triggered;

    bool m_auroraDefeated;
    int m_stepsRemaining;

    std::vector<Space*> m_map;
    void importMapFromFile();
    void connectMap();
    void fillSupplyCaches();
    void fillEnemySpaces();
  
  public:
    Map();
    ~Map();
    void displayMap();

    // Movement
    void handleMovement(Player*, int);
    void updatePlayerLoc(Player*, Space*, int);
    void handleNoMovementMessage(Space*);

    void handleMapEvent(Player*, int);
    void triggerMapEventOpenDoor1();
    void triggerMapEventOpenDoor2();
    void triggerMapEventOpenDoor3();
    void triggerMapEventOpenDoor4();
    void triggerMapEventAurora(Player*);

    void setSize(int);
    void setPlayerLoc(int);
    void setAuroraDefeated(bool);
    void setStepsRemaining(int);
    int getSize();
    int getPlayerLoc();
    bool getAuroraDefeated();
    int getStepsRemaining();


};

#endif

