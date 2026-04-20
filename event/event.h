#ifndef EVENT_H
#define EVENT_H

#include "../player/player.h"

void runForestEvent(int eventId, Player &p);
void runMountainEvent(int eventId, Player &p);
void runAbyssEvent(int eventId, Player &p);
void runFoodCartEvent(Player &player);
void runRevengeGodBlessingEvent(Player &player);

#endif
