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
    // ── Step 1: title screen ────────────────────────────────────────────────
    uiManager.initScreen();
 
    // ── Step 2: pre-load any external resources ─────────────────────────────
    fileIO.loadGameData();
 
    // ── Step 3: New Game vs Load Save (Task 3) ───────────────────────────────
    int startChoice = uiManager.showStartMenu();   // 1 = New, 2 = Load
 
    if (startChoice == 2) {
        // ── Attempt to load a saved game ──────────────────────────────────
        int savedChapterIdx = 0;
        bool savedHard      = false;
 
        bool loaded = fileIO.loadGame(player, savedChapterIdx, savedHard);
 
        if (loaded) {
            // Restore chapter enum from its integer index
            switch (savedChapterIdx) {
                case 0:  currentChapter = Chapter::FOREST;    break;
                case 1:  currentChapter = Chapter::MOUNTAIN;  break;
                case 2:  currentChapter = Chapter::ABYSS;     break;
                default: currentChapter = Chapter::COMPLETED; break;
            }
            isHardMode = savedHard;
 
            uiManager.printMessage("Previous progress restored!");
            uiManager.initStats(player);   // Task 1 – show loaded stats
            return;                        // skip difficulty + createPlayer
        }
 
        // Save file missing or corrupt – fall through to new game
        uiManager.printMessage("No valid save found. Starting a new game.");
    }
 
    // ── New Game path ────────────────────────────────────────────────────────
    int difficulty = uiManager.showDifficultyMenu();
    isHardMode     = (difficulty == HARD_MODE);
    player         = createPlayer(difficulty);
 
    uiManager.initStats(player);           // Task 1 – show starting stats
    currentChapter = Chapter::FOREST;
}

// The core Game Loop
void GameManager::gameLoop() {
    while (!isGameOver && currentChapter != Chapter::COMPLETED) {
        processChapter();
        
        // Check death state after chapter finishes
        if (getPlayerHP(player) <= 0) {
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
    std::string chapterNames[] = { "Forest", "Mountain", "Abyss", "Completed" };
    int chIdx = static_cast<int>(currentChapter);
    fileIO.writeLog("Starting chapter: " + chapterNames[chIdx]
                    + " | HP=" + std::to_string(getPlayerHP(player))
                    + " ATK=" + std::to_string(getPlayerAttack(player))
                    + " DEF=" + std::to_string(getPlayerDefense(player))
                    + " Gold=" + std::to_string(getPlayerGold(player)));
 
    uiManager.showChapterIntro(chIdx);
    eventCount = 0;

    // Loop exactly 7 times for random events
    while (eventCount < 7 && getPlayerHP(player) > 0) {
        // OOP to POP
        // Generating random event ID.
        int randomEventId = rand() % 16 + 1; 

        // 调用 EventManager 执行对应的 procedural 函数
        // 这里把 enum Chapter 强转为 int (0=森林, 1=高山, 2=深渊)
        eventManager.triggerChapterEvent(static_cast<int>(currentChapter), randomEventId, player, isHardMode);
        
        eventCount++;
    }

    // Trigger chapter boss if player survived the 7 events
    if (getPlayerHP(player) > 0) 
    {
        triggerBoss();
        fileIO.writeLog("Boss battle ended. Chapter=" + chapterNames[chIdx]
                        + " | PlayerAlive=" + (isPlayerAlive(player) ? "yes" : "no")
                        + " HP=" + std::to_string(getPlayerHP(player)));
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