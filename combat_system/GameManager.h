// Author: yuzhenxiang6-dotcom
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

// Include headers that will be implemented by other members
#include "../player/player.h"        // Member B
#include "EventManager.h"  // Member C
#include "../UI/ui.h"     // Member E
#include "../FileI:O/filei:o.h"        // Member D
#include "combat.h"        // Member B

// Define the linear progression of chapters
enum class Chapter {
    FOREST,
    MOUNTAIN,
    ABYSS,
    COMPLETED
};

class GameManager {
private:
    bool isHardMode;
    Player player;
    Chapter currentChapter;
    int eventCount;
    bool isGameOver;

    // Module managers implemented by teammates
    EventManager eventManager;
    UIManager uiManager;
    FileIO fileIO;

    // Core private flow control methods
    void initGame();
    void gameLoop();
    void processChapter();
    void triggerBoss();
    void advanceChapter();

public:
    GameManager();
    void start();
};

#endif