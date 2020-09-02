/*******************************************************************************
** Description:  NihilanInfestor implementation.
**
*******************************************************************************/

#include <iostream>

#include "NihilanInfestor.hpp"
#include "Unit.hpp"
#include "constants.hpp"
#include "util.hpp"

using std::cout;
using std::endl;

/**
 * Default constructor calls base Character class constructor to initialize 
 * inherited data members.
 */
NihilanInfestor::NihilanInfestor() 
  : Unit(NIHILAN_INFESTOR_ID, NIHILAN_INFESTOR_NAME
  , NIHILAN_INFESTOR_HEALTH, NIHILAN_INFESTOR_ATTACK
  , NIHILAN_INFESTOR_DEFENSE, NIHILAN_INFESTOR_ARMOR
  , NIHILAN_INFESTOR_INITIATIVE, NIHILAN_INFESTOR_CRIT
  )
{
}


/**
 * Destructor: Currently empty.
 */
NihilanInfestor::~NihilanInfestor()
{
}


