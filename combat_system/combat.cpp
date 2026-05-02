#include "combat.h"
#include <iostream>
#include <cmath>

using namespace std;

bool startBattle(Player &player, Enemy &enemy, UIManager &ui) 
{
    // Special Mechanism: Demon King's settings adjusted based on Kindness
    if (enemy.name == "DemonKing(BOSS)") 
    {
        int k = player.kindness; //get kindness
        enemy.atk -= k;
        enemy.def -= k;
    }

    // Main Loop for Battle
    while (player.hp > 0 && enemy.hp > 0) 
    {
        ui.displayBattleStatus(player, enemy);
        int choice = ui.getBattleChoice(); // 1.Fight 2.Flight

        if (choice == 2) { // Flee
            int penalty = player.maxHp / 5;
            player.hp -= penalty;
            cout << "You fled and lost " << penalty << " HP." << endl;
            //Reflecting current HP
            cout << "[!] Current HP: " << player.hp << " / " << player.maxHp << endl;
            cout << endl;
            return false; 
        }

        // Attack
        int dmgToEnemy = std::max(1, player.attack - enemy.def);
        enemy.hp -= dmgToEnemy;
        std::cout << "You caused " << dmgToEnemy << " points of damage to " << enemy.name << "." << std::endl;

        if (enemy.hp <= 0) {
            // Dryad's revival
            if (enemy.extraLives > 0) 
            {
                enemy.extraLives--;
                enemy.hp = enemy.maxHp;
                cout << enemy.name << " revived!" << endl;
                continue;
            }
            cout << "You defeated " << enemy.name << "!" << endl;
            cout << endl;
            //Dashboard for post-battle status
            cout << "=== POST-BATTLE STATUS ===" << endl;
            cout << " HP      : " << player.hp << " / " << player.maxHp << endl;
            cout << " Attack  : " << player.attack << endl;
            cout << " Defense : " << player.defense << endl;
            cout << " Gold    : " << player.gold << endl;
            cout << "==========================" << endl;
            cout << endl;
            return true;
        }

        // Enemy Attack
        int dmgToPlayer = max(1, enemy.atk - player.defense);
        player.hp -= dmgToPlayer;
        cout << enemy.name << " caused " << dmgToPlayer << " points of harm to you." << endl;
    }
    return player.hp > 0;
}

bool startBattle(Player &player, Enemy &enemy) {
    UIManager ui;
    return startBattle(player, enemy, ui);
}