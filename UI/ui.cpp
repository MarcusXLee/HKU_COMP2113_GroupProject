#include <iostream>
#include <string>
#include <limits>
#include "ui.h"
#include "../player/player.h"

using namespace std;

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

// 示例：在 GameManager 或 main 中调用
void initUIFlow(Player &p) {
    cout << "Welcome to Adventure Game!" <<  endl;
    int diff = showDifficultyMenu();
    
    // 调用队友写好的接口创建玩家
    p = createPlayer(diff); 
    
    cout << "\nInitialized successfully! Current HP: " << getPlayerHP(p) <<  endl;
}