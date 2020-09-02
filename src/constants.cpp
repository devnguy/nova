/*******************************************************************************
** Description:  Constants for IO game.
*******************************************************************************/


#include <string>

#include "constants.hpp"

const char FLOOR_CHAR = ' ';
const char WALL_CHAR = '#';
const char DOOR_CHAR = '-';
const char EVENT_CHAR = '!';
const char PLAYER_CHAR = '@';
const char SUPPLY_CACHE_CHAR = '*';
const char DATA_LOG_CHAR = 'd';
const char ENEMY_CHAR = '$';

const int MOVE_UP = 1;
const int MOVE_LEFT = 2;
const int MOVE_RIGHT = 3;
const int MOVE_DOWN = 4;

const int MAP_COLS = 55;
const int MAP_ROWS = 18;
const int MAP_BOTTOM_LEFT = 935;
const int PLAYER_START_LOC = 498;

const int MAP_EVENT_1 = 448;
const int MAP_EVENT_2 = 170;

const int MAP_EVENT_REACTOR = 189;
const int MAP_EVENT_ENGINE = 794;
const int MAP_EVENT_AURORA = 324;

const int DOOR_1 = 333;
const int DOOR_2 = 449;
const int DOOR_3 = 786;
const int DOOR_4 = 802;

const int INFECTED_CREW_LOC = 223;
const int INFECTED_SCIENTIST_LOC_1 = 291;
const int INFECTED_SCIENTIST_LOC_2 = 307;
const int INFECTED_ENGINEER_LOC = 670;
const int NIHILAN_INFESTOR_LOC = 806;
const int NIHILAN_STALKER_LOC = 922;
const int FUSION_CORE_LOC = 776;

const int WRENCH_LOC = 446;
const int AUGMENT_CK_LOC = 170;
const int FISSION_DAGGER_LOC = 83;
const int WARP_BLADE_LOC = 684;
const int AUGMENT_ATP_LOC = 529;
const int AUGMENT_SDA_LOC = 787;
const int AUGMENT_OPTIK_LOC = 532;

const int AUGMENT_CK_ID = 1000;
const std::string AUGMENT_CK_NAME = "CK-372";

const int AUGMENT_ATP_ID = 1001;
const std::string AUGMENT_ATP_NAME = "ATP-325";
const int AUGMENT_ATP_ATK = 2;
const int AUGMENT_ATP_DEF = 2;
const int AUGMENT_ATP_INIT = 3;

const int AUGMENT_SDA_ID = 1003;
const std::string AUGMENT_SDA_NAME = "SDA-271";
const int AUGMENT_SDA_DEF = 2;
const int AUGMENT_SDA_ARMOR = 3;

const int AUGMENT_OPTIK_ID = 1004;
const std::string AUGMENT_OPTIK_NAME = "OPTIK-290";
const int AUGMENT_OPTIK_CRIT = 30;


const int WRENCH_ID = 2000;
const std::string WRENCH_NAME = "Wrench";
const int WRENCH_ATTACK_MOD = 5;

const int FISSION_DAGGER_ID = 2001;
const std::string FISSION_DAGGER_NAME = "Fission Dagger";
const int FISSION_DAGGER_ATTACK_MOD = 6;
const int FISSION_DAGGER_DICE_MOD = 1;

const int WARP_BLADE_ID = 2002;
const std::string WARP_BLADE_NAME = "Warp Blade";
const int WARP_BLADE_ATTACK_MOD = 8;
const int WARP_BLADE_DICE_MOD = 3;

const int FUSION_CORE_ID = 3000;
const std::string FUSION_CORE_NAME = "Reserve Fusion Core";


const int INITIATIVE_DIE = 20;

const int COMBATANT_1_ID = 1;
const int COMBATANT_2_ID = 2;

// Player
const int P1_ID = 1;
const int P1_BASE_ATTACK = 1;
const int P1_BASE_DEFENSE = 3;
const int P1_BASE_ARMOR = 1;
const int P1_BASE_INITIATIVE = 5;
const int P1_BASE_HEALTH = 50;
const int P1_BASE_CRIT = 15;
const int P1_CORRUPT_SUCCESS = 3;
const int P1_CORRUPT_BASE = 4;
const std::string P1_NAME = "Employee 0162";

// Infected Crew
const int INFECTED_CREW_ID = 2;
const int INFECTED_CREW_ATTACK = 4;
const int INFECTED_CREW_DEFENSE = 2;
const int INFECTED_CREW_ARMOR = 0;
const int INFECTED_CREW_INITIATIVE = 1;
const int INFECTED_CREW_HEALTH = 8;
const int INFECTED_CREW_CRIT = 0;
const std::string INFECTED_CREW_NAME = "Infected Crew Member";

// Infected Scientist
const int INFECTED_SCIENTIST_ID = 3;
const int INFECTED_SCIENTIST_ATTACK = 6;
const int INFECTED_SCIENTIST_DEFENSE = 2;
const int INFECTED_SCIENTIST_ARMOR = 0;
const int INFECTED_SCIENTIST_INITIATIVE = 2;
const int INFECTED_SCIENTIST_HEALTH = 12;
const int INFECTED_SCIENTIST_CRIT = 0;
const std::string INFECTED_SCIENTIST_NAME = "Infected Scientist";

// Infected Engineer
const int INFECTED_ENGINEER_ID = 4;
const int INFECTED_ENGINEER_ATTACK = 8;
const int INFECTED_ENGINEER_DEFENSE = 6;
const int INFECTED_ENGINEER_ARMOR = 1;
const int INFECTED_ENGINEER_INITIATIVE = 3;
const int INFECTED_ENGINEER_HEALTH = 18;
const int INFECTED_ENGINEER_CRIT = 0;
const int INFECTED_ENGINEER_TURRET_ATK = 2;
const std::string INFECTED_ENGINEER_NAME = "Infected Engineer";

// Nihilan Infestor
const int NIHILAN_INFESTOR_ID = 5;
const int NIHILAN_INFESTOR_ATTACK = 12;
const int NIHILAN_INFESTOR_DEFENSE = 8;
const int NIHILAN_INFESTOR_ARMOR = 3;
const int NIHILAN_INFESTOR_INITIATIVE = 8;
const int NIHILAN_INFESTOR_HEALTH = 24;
const int NIHILAN_INFESTOR_CRIT = 10;
const std::string NIHILAN_INFESTOR_NAME = "Nihilan Infestor";

// Nihilan Stalker
const int NIHILAN_STALKER_ID = 6;
const int NIHILAN_STALKER_ATTACK = 8;
const int NIHILAN_STALKER_DEFENSE = 8;
const int NIHILAN_STALKER_ARMOR = 4;
const int NIHILAN_STALKER_INITIATIVE = 14;
const int NIHILAN_STALKER_HEALTH = 28;
const int NIHILAN_STALKER_CRIT = 15;
const int NIHILAN_STALKER_DICE = 1;
const int NIHILAN_STALKER_AFTER_IMAGE_SUCCESS = 3;
const int NIHILAN_STALKER_AFTER_IMAGE = 8;
const std::string NIHILAN_STALKER_NAME = "Nihilan Stalker";

// AURORA
const int AURORA_ID = 7;
const int AURORA_ATTACK = 10;
const int AURORA_DEFENSE = 1;
const int AURORA_ARMOR = 6;
const int AURORA_INITIATIVE = 0;
const int AURORA_HEALTH = 60;
const int AURORA_CRIT = 25;
const int AURORA_DICE = 1;
const std::string AURORA_NAME = "AURORA";

