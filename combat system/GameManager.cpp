// Author: yuzhenxiang6-dotcom
#include "../combat system/GameManager.h"

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
    // Member E: Setup terminal settings
    uiManager.initScreen();
    
    // Member D: Load event texts from .txt/.json
    fileIO.loadGameData();
    
    uiManager.displayIntro();
    
    // Member B & E: Prompt difficulty and init player stats
    int difficulty = uiManager.promptDifficulty();
    player.initStats(difficulty); 
}

// The core Game Loop
void GameManager::gameLoop() {
    while (!isGameOver && currentChapter != Chapter::COMPLETED) {
        processChapter();
        
        // Check death state after chapter finishes
        if (player.getHP() <= 0) {
            isGameOver = true;
            uiManager.displayGameOver();
        } else {
            advanceChapter();
        }
    }
    
    // Win condition
    if (!isGameOver && currentChapter == Chapter::COMPLETED) {
        uiManager.displayVictory();
    }
}

// Handle the "7 random events + 1 Boss" logic
void GameManager::processChapter() {
    uiManager.displayChapterTitle(currentChapter);
    eventCount = 0;

    // Loop exactly 7 times for random events
    while (eventCount < 7 && player.getHP() > 0) {
        // Member C: Dynamically allocate a random event
        Event* currentEvent = eventManager.drawEvent(currentChapter);
        
        // Member E: Render the event text and choices
        uiManager.renderEvent(currentEvent);
        int choice = uiManager.getPlayerChoice();
        
        // Member C: Resolve the outcome based on player's choice
        currentEvent->resolve(player, choice);
        
        // Crucial: Free dynamic memory to prevent memory leaks
        delete currentEvent; 
        
        eventCount++;
    }

    // Trigger chapter boss if player survived the 7 events
    if (player.getHP() > 0) {
        triggerBoss();
    }
}

// Spawn and fight the chapter boss
void GameManager::triggerBoss() {
    uiManager.displayBossWarning();
    
    // Member C: Generate specific boss based on chapter
    Enemy boss = eventManager.generateBoss(currentChapter);
    
    // Member B: Execute combat system logic
    Combat combatSystem;
    combatSystem.startCombat(player, boss);
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