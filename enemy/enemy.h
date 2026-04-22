#pragma once
#include <string>

struct Enemy {
    std::string name;

    int maxHp;
    int hp;
    int atk;
    int def;

    // 树精：需要击败两次 => extraLives = 1
    // 普通敌人 => extraLives = 0
    int extraLives;
};

// 输出接口（按 GP 要求）
Enemy createGoblin();
Enemy createTiger();
Enemy createBoss(int stage);
