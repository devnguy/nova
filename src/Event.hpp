/*******************************************************************************
** Description:  Definition of Event class.
*******************************************************************************/

#ifndef EVENT_HPP
#define EVENT_HPP

#include "Space.hpp"


class Event : public Space {
  private:
    void handleNoFusionCoreMessage();
    void handleAuroraEvent(Player*);
    
  
  public:
    Event();
    Event(int);
    ~Event();

    void triggerSpace(Player*);
    

    // void setEventTriggered(bool);
    // bool getEventTriggered();


};

#endif


