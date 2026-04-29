// Combat.cpp 实现
#include "Combat.h"
#include <iostream>
#include <cmath>

bool Combat::startBattle(Player &player, Enemy &enemy, UIManager &ui) {
    // 特殊机制：如果是魔王，根据善良值修正属性
    if (enemy.name == "魔王") {
        int k = player.kindness; // 假设有这个 getter
        enemy.atk -= k;
        enemy.def -= k;
    }

    // 战斗主循环
    while (player.hp > 0 && enemy.hp > 0) {
        ui.displayBattleStatus(player, enemy);
        int choice = ui.getBattleChoice(); // 1.攻击 2.逃跑

        if (choice == 2) { // 逃跑
            int penalty = player.maxHp * 0.2;
            player.hp -= penalty;
            std::cout << "你逃跑了，损失了 " << penalty << " 点生命值。" << std::endl;
            return false; 
        }

        // 玩家攻击
        int dmgToEnemy = std::max(1, player.attack - enemy.def);
        enemy.hp -= dmgToEnemy;
        std::cout << "你对 " << enemy.name << " 造成了 " << dmgToEnemy << " 点伤害。" << std::endl;

        if (enemy.hp <= 0) {
            // 树精复活机制
            if (enemy.extraLives > 0) {
                enemy.extraLives--;
                enemy.hp = enemy.maxHp;
                std::cout << enemy.name << " 复活了！" << std::endl;
                continue;
            }
            std::cout << "你击败了 " << enemy.name << "！" << std::endl;
            return true;
        }

        // 敌人攻击
        int dmgToPlayer = std::max(1, enemy.atk - player.defense);
        player.hp -= dmgToPlayer;
        std::cout << enemy.name << " 对你造成了 " << dmgToPlayer << " 点伤害。" << std::endl;
    }
    return player.hp > 0;
}