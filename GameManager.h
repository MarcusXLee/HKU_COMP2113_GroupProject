#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

// Include headers that will be implemented by other members
#include "Player.h"        // Member B
#include "EventManager.h"  // Member C
#include "UIManager.h"     // Member E
#include "FileIO.h"        // Member D
#include "Combat.h"        // Member B

// Define the linear progression of chapters
enum class Chapter {
    FOREST,
    MOUNTAIN,
    ABYSS,
    COMPLETED
};

class GameManager {
private:
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