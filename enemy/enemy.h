#ifndef ENEMY_H
#define ENEMY_H
#include <string>

using namespace std;

struct Enemy {
    string name;
    int maxHp;
    int hp;
    int atk;
    int def;
    // 树精：需要击败两次 => extraLives = 1
    // 普通敌人 => extraLives = 0
    int extraLives;
};

enum class EnemyType {
    // 森林敌人
    Goblin, WanderingMerchant_Forest, Tiger, Thief, Rabbit, Hellhound, BrownBear, TreantBoss,
    // 高山敌人
    Griffon, Bandit, FireSprite, Dragon, WanderingMerchant_Mountain, RockGiantBoss,
    // 深渊敌人
    EvilCreature, DragonkinSoldier, ArchDemon, WanderingMerchant_Abyss, DemonKingBoss
};

// 核心工厂接口
Enemy createEnemy(EnemyType type, bool isHard);
Enemy createBoss(int stage, bool isHard);

#endif