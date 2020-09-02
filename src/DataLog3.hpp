/*******************************************************************************
** Description:  Definition of DataLog3 derived class from Space.
*******************************************************************************/

#ifndef DATA_LOG_3_HPP
#define DATA_LOG_3_HPP

#include "Space.hpp"


class DataLog3 : public Space {
  private:
    void slowPrint();
  
  public:
    DataLog3();
    DataLog3(int);
    ~DataLog3();

    void triggerSpace(Player*);
};

#endif


