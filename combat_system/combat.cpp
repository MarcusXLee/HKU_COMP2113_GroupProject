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
            if (enemy.name.find("(BOSS)") != std::string::npos) {
                cout << "[!] The sheer presence of " << enemy.name << " freezes you in place. There is nowhere to run!" << endl;
                continue; // No flight in BOSS fight!
            }
            int penalty = player.maxHp / 5;
            player.hp = std::max(0, player.hp - penalty);
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
            //Loot system
            int goldDrop = 0;
            if (enemy.name.find("(BOSS)") != std::string::npos) {
                goldDrop = rand() % 11 + 10; // BOSS gives 10-20 coins if defeated
                cout << "🌟 EPIC VICTORY! You found a massive chest containing " << goldDrop << " gold!" << endl;
                cout << "💪 Absorbing the boss's core increases your HP by 2, Attack and Defense by 1!" << endl;
                player.hp = std::min(player.hp + 2, player.maxHp);
                player.attack += 1;
                player.defense += 1;
            } 
            else {
                goldDrop = rand() % 4 ; // Others give 0-3 coins if defeated
                cout << "🪙 You looted " << goldDrop << " gold from the enemy's remains." << endl;
            }
            player.gold += goldDrop;
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
        player.hp = std::max(0, player.hp - dmgToPlayer);
        cout << enemy.name << " caused " << dmgToPlayer << " points of harm to you." << endl;
    }
    return player.hp > 0;
}

bool startBattle(Player &player, Enemy &enemy) {
    UIManager ui;
    return startBattle(player, enemy, ui);
}