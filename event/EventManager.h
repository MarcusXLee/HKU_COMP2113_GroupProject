#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "event.h"
#include "common.h"

using namespace std;

class EventManager {
public:
    void triggerChapterEvent(int chapter, int eventId, Player &p) {
        if (chapter == 0) runForestEvent(eventId, p);
        else if (chapter == 1) runMountainEvent(eventId, p);
        else if (chapter == 2) runAbyssEvent(eventId, p);
    }
    
    void triggerRandomEvent(Player &p) {
        // 这里可以写逻辑随机调用 common.h 里的商人或赌博事件
        runMerchantEvent(p); 
    }
};
#endif