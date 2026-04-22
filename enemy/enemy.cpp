#include "enemy.h"

// 难度开关：false=简单，true=困难（按你表格）
static const bool HARD_MODE = false;

Enemy createGoblin() {
    Enemy e;
    e.name = "哥布林";
    e.maxHp = HARD_MODE ? 5 : 4;
    e.hp    = e.maxHp;
    e.atk   = 2;
    e.def   = 0;
    e.extraLives = 0;
    return e;
}

Enemy createTiger() {
    Enemy e;
    e.name = "猛虎";
    e.maxHp = HARD_MODE ? 8 : 7;
    e.hp    = e.maxHp;
    e.atk   = HARD_MODE ? 5 : 4;
    e.def   = HARD_MODE ? 2 : 1;
    e.extraLives = 0;
    return e;
}

Enemy createBoss(int stage) {
    Enemy e;

    // stage 建议按章节：
    // 1=森林Boss(树精，需击败两次)
    // 2=高山Boss(岩石巨人)
    // 3=深渊Boss(魔王)
    if (stage == 1) {
        e.name  = "树精（BOSS）";
        e.maxHp = HARD_MODE ? 12 : 10;
        e.hp    = e.maxHp;
        e.atk   = HARD_MODE ? 6 : 5;
        e.def   = HARD_MODE ? 4 : 3;
        e.extraLives = 1; // 需击败两次
        return e;
    }

    if (stage == 2) {
        e.name  = "岩石巨人（BOSS）";
        e.maxHp = HARD_MODE ? 18 : 16;
        e.hp    = e.maxHp;
        e.atk   = HARD_MODE ? 9 : 8;
        e.def   = HARD_MODE ? 8 : 7;
        e.extraLives = 0;
        return e;
    }

    if (stage == 3) {
        e.name  = "魔王（BOSS）";
        e.maxHp = HARD_MODE ? 28 : 24;
        e.hp    = e.maxHp;
        e.atk   = HARD_MODE ? 13 : 12;
        e.def   = HARD_MODE ? 11 : 10;
        e.extraLives = 0;
        return e;
    }

    // 非法 stage：给一个默认的森林Boss，避免程序崩（也方便调试）
    return createBoss(1);
}
