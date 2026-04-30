#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>
#include "ui.h"
#include "../player/player.h"

using namespace std;

void UIManager::clearScreen() 
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int UIManager::getValidInput(int min, int max) {
    int choice;
    while (true) {
        if (cin >> choice && choice >= min && choice <= max) {
            return choice;
        }
        cout << "Invalid input. Please enter a number between "
             << min << " and " << max << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void UIManager::initScreen() {
    clearScreen();
    cout << "=============================================" << endl;
    cout << "        WELCOME TO THE ADVENTURE GAME        " << endl;
    cout << "=============================================" << endl;
    cout << "   Face the forest, mountain, and abyss...   " << endl;
    cout << "         Defeat the Demon King!               " << endl;
    cout << "=============================================" << endl;
    cout << endl;
}

void UIManager::initStats(const Player &p) {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "             YOUR STARTING STATS             " << endl;
    cout << "=============================================" << endl;
    cout << "  HP      : " << getPlayerHP(p)      << " / " << getPlayerMaxHP(p) << endl;
    cout << "  Attack  : " << getPlayerAttack(p)  << endl;
    cout << "  Defense : " << getPlayerDefense(p) << endl;
    cout << "  Gold    : " << getPlayerGold(p)    << endl;
    cout << "=============================================" << endl;
    cout << endl;
}

int UIManager::showStartMenu() {
    int choice;
    while (true) {
        cout << "=============================================" << endl;
        cout << "                  MAIN MENU                  " << endl;
        cout << "       1. New Game                           " << endl;
        cout << "       2. Load Previous Progress             " << endl;
        cout << "=============================================" << endl;
        cout << "Please enter your option (1 or 2): ";
 
        if (cin >> choice) {
            if (choice == 1 || choice == 2) {
                return choice;
            }
        }
 
        cout << "\nInvalid input, please enter 1 or 2." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

//Choosing Difficulty level
int showDifficultyMenu() 
{
    int choice;
    while (true) 
    {
        cout << "==============================" << endl;
        cout << "       Please select your difficulty level        " << endl;
        cout << "       1. Simple      " << endl;
        cout << "       2. Challenging      " << endl;
        cout << "==============================" << endl;
        cout << "Please enter your option(1 or 2):  ";

        if (cin >> choice) 
        {
            if (choice == EASY_MODE || choice == HARD_MODE) 
            {
                return choice;
            }
        }

        //Invalid input
        cout << "\nInvalid input, please enter 1 or 2." <<  endl;
        
        //Remove error note
        cin.clear(); 
        //Ignore invalid characters
        cin.ignore( numeric_limits< streamsize>::max(), '\n');
    }
}

int UIManager::showMainMenu() {
    cout << "=============================================" << endl;
    cout << "           ADVENTURE GAME — v1.0             " << endl;
    cout << "=============================================" << endl;
    return 0;
}

void UIManager::showChapterIntro(int chapterId) {
    cout << endl;
    cout << "=============================================" << endl;
    switch (chapterId) {
        case 0:
            cout << "          CHAPTER 1 — THE FOREST             " << endl;
            cout << "  Dark trees close around you as you venture  " << endl;
            cout << "  deeper into the ancient forest...           " << endl;
            break;
        case 1:
            cout << "          CHAPTER 2 — THE MOUNTAIN           " << endl;
            cout << "  The air grows thin as you begin your        " << endl;
            cout << "  treacherous climb toward the summit...      " << endl;
            break;
        case 2:
            cout << "          CHAPTER 3 — THE ABYSS              " << endl;
            cout << "  You descend into darkness. The Demon King   " << endl;
            cout << "  awaits at the bottom...                     " << endl;
            break;
        default:
            cout << "           UNKNOWN CHAPTER                   " << endl;
            break;
    }
    cout << "=============================================" << endl;
    cout << endl;
}

void UIManager::displayBattleStatus(const Player &p, const Enemy &e) {
    cout << endl;
    cout << "---------------------------------------------" << endl;
    cout << "  [YOU]   HP: " << getPlayerHP(p)
         << "/" << getPlayerMaxHP(p)
         << "  ATK: " << getPlayerAttack(p)
         << "  DEF: " << getPlayerDefense(p) << endl;
    cout << "  [" << e.name << "]"
         << "  HP: " << e.hp
         << "  ATK: " << e.atk
         << "  DEF: " << e.def << endl;
    cout << "---------------------------------------------" << endl;
}

int UIManager::getBattleChoice() {
    cout << "  1. Fight   2. Flee" << endl;
    cout << "Your choice: ";
    return getValidInput(1, 2);
}

int UIManager::showUpgradeMenu() {
    cout << "=============================================" << endl;
    cout << "              UPGRADE YOUR STATS             " << endl;
    cout << "  1. Attack                                  " << endl;
    cout << "  2. Defense                                 " << endl;
    cout << "  3. Max HP                                  " << endl;
    cout << "=============================================" << endl;
    cout << "Your choice: ";
    return getValidInput(1, 3);
}

void UIManager::printMessage(const std::string &message) {
    cout << "[!] " << message << endl;
}

void UIManager::showGameOver() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "                 GAME  OVER                  " << endl;
    cout << "       You have fallen on your journey.      " << endl;
    cout << "=============================================" << endl;
}

void UIManager::showVictory() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "               CONGRATULATIONS!              " << endl;
    cout << "       You have defeated the Demon King!     " << endl;
    cout << "       Your revenge is complete.             " << endl;
    cout << "=============================================" << endl;
}

void UIManager::printRandomRoast() {
    vector<string> roasts;
    ifstream file("roast.txt");
 
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            // Skip blank lines so we never print an empty roast
            if (!line.empty()) {
                roasts.push_back(line);
            }
        }
        file.close();
    }
 
    if (roasts.empty()) {
        // Fallback: roast.txt missing or empty
        cout << "[!] That's not a valid choice. Did you even read the options?" << endl;
        return;
    }
 
    // Pick a uniformly random line (rand() is seeded in main.cpp)
    int idx = rand() % static_cast<int>(roasts.size());
    cout << "[!] " << roasts[idx] << endl;
}