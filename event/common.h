#ifndef COMMON_H
#define COMMON_H
 
#include "../player/player.h"   // Fixed: Player type must be included before it is used
 
void runBattleGodBlessingEvent(Player &player);
void runJudgmentEvent(Player &player);
void runMerchantEvent(Player &player, bool isHard);
void runGamblingEvent(Player &player);
void runFoodCartEvent(Player &player);
void runRevengeGodBlessingEvent(Player &player);
void runMasterHermitEvent(Player &player);
 
#endif