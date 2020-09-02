/*******************************************************************************
** Description:  Definition of constants.
*******************************************************************************/

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

extern const char FLOOR_CHAR;
extern const char WALL_CHAR;
extern const char DOOR_CHAR;
extern const char EVENT_CHAR;
extern const char PLAYER_CHAR;
extern const char SUPPLY_CACHE_CHAR;
extern const char DATA_LOG_CHAR;
extern const char ENEMY_CHAR;

extern const int MOVE_UP;
extern const int MOVE_LEFT;
extern const int MOVE_RIGHT;
extern const int MOVE_DOWN;

extern const int MAP_COLS;
extern const int MAP_ROWS;
extern const int MAP_BOTTOM_LEFT;
extern const int PLAYER_START_LOC;

extern const int MAP_EVENT_1;
extern const int MAP_EVENT_2;
extern const int MAP_EVENT_REACTOR;
extern const int MAP_EVENT_REACTOR;
extern const int MAP_EVENT_ENGINE;
extern const int MAP_EVENT_AURORA;

extern const int DOOR_1;
extern const int DOOR_2;
extern const int DOOR_3;
extern const int DOOR_4;


extern const int INFECTED_CREW_LOC;
extern const int INFECTED_SCIENTIST_LOC_1;
extern const int INFECTED_SCIENTIST_LOC_2;
extern const int INFECTED_ENGINEER_LOC;
extern const int NIHILAN_INFESTOR_LOC;
extern const int NIHILAN_STALKER_LOC;
extern const int FUSION_CORE_LOC;


extern const int WRENCH_LOC;
extern const int AUGMENT_CK_LOC;


extern const int FISSION_DAGGER_LOC;
extern const int WARP_BLADE_LOC;

extern const int AUGMENT_ATP_LOC;
extern const int AUGMENT_SDA_LOC;
extern const int AUGMENT_OPTIK_LOC;

// Augments
extern const int AUGMENT_CK_ID;
extern const std::string AUGMENT_CK_NAME;

extern const int AUGMENT_ATP_ID;
extern const std::string AUGMENT_ATP_NAME;
extern const int AUGMENT_ATP_ATK;
extern const int AUGMENT_ATP_DEF;
extern const int AUGMENT_ATP_INIT;

extern const int AUGMENT_SDA_ID;
extern const std::string AUGMENT_SDA_NAME;
extern const int AUGMENT_SDA_DEF;
extern const int AUGMENT_SDA_ARMOR;

extern const int AUGMENT_OPTIK_ID;
extern const std::string AUGMENT_OPTIK_NAME;
extern const int AUGMENT_OPTIK_CRIT;

// Weapons
extern const int WRENCH_ID;
extern const std::string WRENCH_NAME;
extern const int WRENCH_ATTACK_MOD;

extern const int FISSION_DAGGER_ID;
extern const std::string FISSION_DAGGER_NAME;
extern const int FISSION_DAGGER_ATTACK_MOD;
extern const int FISSION_DAGGER_DICE_MOD;

extern const int WARP_BLADE_ID;
extern const std::string WARP_BLADE_NAME;
extern const int WARP_BLADE_ATTACK_MOD;
extern const int WARP_BLADE_DICE_MOD;

extern const int FUSION_CORE_ID;
extern const std::string FUSION_CORE_NAME;


extern const int INITIATIVE_DIE;

extern const int COMBATANT_1_ID;
extern const int COMBATANT_2_ID;

extern const int P1_ID;
extern const int P1_BASE_ATTACK;
extern const int P1_BASE_DEFENSE;
extern const int P1_BASE_ARMOR;
extern const int P1_BASE_INITIATIVE;
extern const int P1_BASE_HEALTH;
extern const int P1_BASE_CRIT;
extern const int P1_CORRUPT_SUCCESS;
extern const int P1_CORRUPT_BASE;
extern const std::string P1_NAME;

extern const int INFECTED_CREW_ID;
extern const int INFECTED_CREW_ATTACK;
extern const int INFECTED_CREW_DEFENSE;
extern const int INFECTED_CREW_ARMOR;
extern const int INFECTED_CREW_INITIATIVE;
extern const int INFECTED_CREW_HEALTH;
extern const int INFECTED_CREW_CRIT;
extern const std::string INFECTED_CREW_NAME;

// Infected Scientist
extern const int INFECTED_SCIENTIST_ID;
extern const int INFECTED_SCIENTIST_ATTACK;
extern const int INFECTED_SCIENTIST_DEFENSE;
extern const int INFECTED_SCIENTIST_ARMOR;
extern const int INFECTED_SCIENTIST_INITIATIVE;
extern const int INFECTED_SCIENTIST_HEALTH ;
extern const int INFECTED_SCIENTIST_CRIT;
extern const std::string INFECTED_SCIENTIST_NAME;

// Infected Engineer
extern const int INFECTED_ENGINEER_ID;
extern const int INFECTED_ENGINEER_ATTACK;
extern const int INFECTED_ENGINEER_DEFENSE;
extern const int INFECTED_ENGINEER_ARMOR;
extern const int INFECTED_ENGINEER_INITIATIVE;
extern const int INFECTED_ENGINEER_HEALTH;
extern const int INFECTED_ENGINEER_CRIT;
extern const int INFECTED_ENGINEER_TURRET_ATK;
extern const std::string INFECTED_ENGINEER_NAME;

// Nihilan Infestor
extern const int NIHILAN_INFESTOR_ID;
extern const int NIHILAN_INFESTOR_ATTACK ;
extern const int NIHILAN_INFESTOR_DEFENSE;
extern const int NIHILAN_INFESTOR_ARMOR;
extern const int NIHILAN_INFESTOR_INITIATIVE;
extern const int NIHILAN_INFESTOR_HEALTH;
extern const int NIHILAN_INFESTOR_CRIT;
extern const std::string NIHILAN_INFESTOR_NAME;

// Nihilan Stalker
extern const int NIHILAN_STALKER_ID;
extern const int NIHILAN_STALKER_ATTACK;
extern const int NIHILAN_STALKER_DEFENSE;
extern const int NIHILAN_STALKER_ARMOR;
extern const int NIHILAN_STALKER_INITIATIVE;
extern const int NIHILAN_STALKER_HEALTH;
extern const int NIHILAN_STALKER_CRIT;
extern const int NIHILAN_STALKER_DICE;
extern const int NIHILAN_STALKER_AFTER_IMAGE_SUCCESS;
extern const int NIHILAN_STALKER_AFTER_IMAGE;
extern const std::string NIHILAN_STALKER_NAME;

// AURORA
extern const int AURORA_ID;
extern const int AURORA_ATTACK;
extern const int AURORA_DEFENSE;
extern const int AURORA_ARMOR;
extern const int AURORA_INITIATIVE;
extern const int AURORA_HEALTH;
extern const int AURORA_CRIT;
extern const int AURORA_DICE;
extern const std::string AURORA_NAME;



#endif