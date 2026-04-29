#include "enemy.h"

// 难度开关：false=简单，true=困难
static const bool HARD_MODE = false;

// 内部辅助函数，封装生成逻辑
static Enemy makeEnemy(const std::string& name, int hp, int atk, int def, int extraLives = 0) {
    Enemy e;
    e.name = name;
    e.maxHp = hp;
    e.hp = hp;
    e.atk = atk;
    e.def = def;
    e.extraLives = extraLives;
    return e;
}

Enemy createEnemy(EnemyType type) {
    const bool H = HARD_MODE;

    switch (type) {
        // ===== 森林 =====
        case EnemyType::Goblin:                     return makeEnemy("Goblin", H ? 5 : 4, 2, 0);
        case EnemyType::WanderingMerchant_Forest:   return makeEnemy("Merchant (Forest)", H ? 10 : 8, H ? 7 : 6, 5);
        case EnemyType::Tiger:                      return makeEnemy("Tiger", H ? 8 : 7, H ? 5 : 4, H ? 2 : 1);
        case EnemyType::Thief:                      return makeEnemy("Thief", H ? 6 : 5, H ? 4 : 3, 1);
        case EnemyType::Rabbit:                     return makeEnemy("Rabbit", H ? 2 : 1, 0, 0);
        case EnemyType::Hellhound:                  return makeEnemy("Hellhound", H ? 5 : 4, H ? 3 : 2, 0);
        case EnemyType::BrownBear:                  return makeEnemy("Brown Bear", H ? 10 : 8, H ? 5 : 4, 2);
        case EnemyType::TreantBoss:                 return makeEnemy("Dryad (BOSS)", H ? 12 : 10, H ? 6 : 5, H ? 4 : 3, 1);

        // ===== 高山 =====
        case EnemyType::Griffon:                    return makeEnemy("Griffin", H ? 12 : 10, H ? 6 : 5, H ? 3 : 2);
        case EnemyType::Bandit:                     return makeEnemy("Bandit", H ? 5 : 4, H ? 4 : 3, 1);
        case EnemyType::FireSprite:                 return makeEnemy("Fire Spirit", H ? 9 : 8, H ? 8 : 7, 0);
        case EnemyType::Dragon:                     return makeEnemy("Dragon", H ? 14 : 12, H ? 8 : 7, H ? 5 : 4);
        case EnemyType::WanderingMerchant_Mountain: return makeEnemy("Merchant (Mountain)", H ? 12 : 10, H ? 8 : 7, H ? 6 : 5);
        case EnemyType::RockGiantBoss:              return makeEnemy("Rock Giant (BOSS)", H ? 18 : 16, H ? 9 : 8, H ? 8 : 7);

        // ===== 深渊 =====
        case EnemyType::EvilCreature:               return makeEnemy("Evil Creature", H ? 16 : 14, H ? 9 : 8, H ? 7 : 6);
        case EnemyType::DragonkinSoldier:           return makeEnemy("Dragon Soldier", H ? 16 : 14, H ? 9 : 8, H ? 8 : 7);
        case EnemyType::ArchDemon:                  return makeEnemy("Great Demon", H ? 22 : 18, H ? 10 : 9, H ? 9 : 8);
        case EnemyType::WanderingMerchant_Abyss:    return makeEnemy("Merchant (Abyss)", H ? 14 : 12, H ? 8 : 7, H ? 7 : 6);
        case EnemyType::DemonKingBoss:              return makeEnemy("Demon King (BOSS)", H ? 28 : 24, H ? 13 : 12, H ? 11 : 10);
    }

    return makeEnemy("Unknown", 1, 0, 0);
}

Enemy createGoblin() { return createEnemy(EnemyType::Goblin); }
Enemy createTiger()  { return createEnemy(EnemyType::Tiger); }
Enemy createBoss(int stage) {
    if (stage == 1) return createEnemy(EnemyType::TreantBoss);
    if (stage == 2) return createEnemy(EnemyType::RockGiantBoss);
    if (stage == 3) return createEnemy(EnemyType::DemonKingBoss);
    return createEnemy(EnemyType::TreantBoss);
}