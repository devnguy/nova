/*******************************************************************************
** Description:  Definition of DataLog2 derived class from Space.
*******************************************************************************/

#ifndef DATA_LOG_2_HPP
#define DATA_LOG_2_HPP

#include "Space.hpp"


class DataLog2 : public Space {
  private:
    void slowPrint();
  
  public:
    DataLog2();
    DataLog2(int);
    ~DataLog2();

    void triggerSpace(Player*);
};

#endif


