#ifndef EVENT_H
#define EVENT_H

#include "../player/player.h"

void runForestEvent(int eventId, Player &p, bool isHard);
void runMountainEvent(int eventId, Player &p, bool isHard);
void runAbyssEvent(int eventId, Player &p, bool isHard);

#endif
