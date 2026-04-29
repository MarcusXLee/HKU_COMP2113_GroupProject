#ifndef UI_H
#define UI_H

#include <string>
#include <vector>
#include "../player/player.h"
#include "../enemy/enemy.h"   

class UIManager 
{
public:
    UIManager() = default;
    int showMainMenu();
    int showDifficultyMenu();
    void showChapterIntro(int chapterId);
    void displayBattleStatus(const Player &p, const Enemy &e);
    int getBattleChoice();
    int showUpgradeMenu();
    void printMessage(const std::string &message);
    void showGameOver();
    void showVictory();

private:
    int getValidInput(int min, int max);
    void clearScreen();
};

#endif