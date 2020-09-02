/*******************************************************************************
** Description:  Definition of DataLog1 derived class from Space.
*******************************************************************************/

#ifndef DATA_LOG_1_HPP
#define DATA_LOG_1_HPP

#include "Space.hpp"


class DataLog1 : public Space {
  private:
    void slowPrint();
  
  public:
    DataLog1();
    DataLog1(int);
    ~DataLog1();

    void triggerSpace(Player*);
};

#endif


