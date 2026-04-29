#include "../combat_system/GameManager.h"

// Constructor: Initialize starting state
GameManager::GameManager() {
    currentChapter = Chapter::FOREST;
    eventCount = 0;
    isGameOver = false;
}

// Public method to kick off the game
void GameManager::start() {
    initGame();
    gameLoop();
}

void GameManager::initGame() {
    int choice = uiManager.showDifficultyMenu(); //Using UI
    isHardMode = (choice == 2); //1 is False(easy), 2 is True(difficult)
    // Member E: Setup terminal settings
    uiManager.initScreen();
    
    // Member D: Load event texts from .txt/.json
    fileIO.loadGameData();
    
    uiManager.showMainMenu();
    
    // Member B & E: Prompt difficulty and init player stats
    int difficulty = uiManager.showDifficultyMenu();
    player.initStats(difficulty); 
}

// The core Game Loop
void GameManager::gameLoop() {
    while (!isGameOver && currentChapter != Chapter::COMPLETED) {
        processChapter();
        
        // Check death state after chapter finishes
        if (player.getHP() <= 0) {
            isGameOver = true;
            uiManager.showGameOver();
        } else {
            advanceChapter();
        }
    }
    
    // Win condition
    if (!isGameOver && currentChapter == Chapter::COMPLETED) {
        uiManager.showVictory();
    }
}

// Handle the "7 random events + 1 Boss" logic
void GameManager::processChapter() {
    uiManager.showChapterIntro(static_cast<int>(currentChapter));
    eventCount = 0;

    // Loop exactly 7 times for random events
    while (eventCount < 7 && player.getHP() > 0) {
        // OOP to POP
        // Generating random event ID.
        int randomEventId = rand() % 16 + 1; 

        // 调用 EventManager 执行对应的 procedural 函数
        // 这里把 enum Chapter 强转为 int (0=森林, 1=高山, 2=深渊)
        eventManager.triggerChapterEvent(static_cast<int>(currentChapter), randomEventId, player, isHardMode);
        
        eventCount++;
    }

    // Trigger chapter boss if player survived the 7 events
    if (player.getHP() > 0) {
        triggerBoss();
    }
}

// Spawn and fight the chapter boss
void GameManager::triggerBoss() {
    uiManager.printMessage("Warning: Boss is approaching!"); // fixed UI usage
    
    // Generate the BOSS of the chapter
    Enemy boss = eventManager.generateBoss(static_cast<int>(currentChapter), isHardMode);
    
    // Using startbattle function directly
    startBattle(player, boss, uiManager);;
}

// Move to the next stage
void GameManager::advanceChapter() {
    switch (currentChapter) {
        case Chapter::FOREST:   
            currentChapter = Chapter::MOUNTAIN; 
            break;
        case Chapter::MOUNTAIN: 
            currentChapter = Chapter::ABYSS;    
            break;
        case Chapter::ABYSS:    
            currentChapter = Chapter::COMPLETED; 
            break;
        default: 
            break;
    }
}