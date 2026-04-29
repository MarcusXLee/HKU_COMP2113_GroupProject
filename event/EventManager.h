#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "event.h"
#include "common.h"
#include "../enemy/enemy.h"
#include <cstdlib>

using namespace std;

class EventManager {
public:
    void triggerChapterEvent(int chapter, int eventId, Player &p, bool isHard) {
        if (chapter == 0) {
            runForestEvent(eventId, p, isHard);
        }
        else if (chapter == 1){
            runMountainEvent(eventId, p, isHard);
        }
        else if (chapter == 2){
            runAbyssEvent(eventId, p, isHard);
        }
    }
    
    void triggerRandomEvent(Player &p) {
        // 固定调用商人事件，或增加随机逻辑
        runMerchantEvent(p, false); 
    }

    Enemy generateBoss(int chapter, bool isHard) {
        // 章节 0=森林, 1=高山, 2=深渊
        return createBoss(chapter + 1, isHard);
    }
};
#endif