#include "enemy.h"

// 内部辅助函数，封装生成逻辑
static Enemy makeEnemy(const std::string& name, int baseHp, int baseAtk, int baseDef, bool isHard, int extraLives = 0) {
    Enemy e;
    e.name = name;
    
    // 难度加成算法：困难模式下数值提升
    float multiplier = isHard ? 1.5f : 1.0f; // 困难模式 1.5 倍
    
    e.maxHp = static_cast<int>(baseHp * multiplier);
    e.hp = e.maxHp;
    e.atk = static_cast<int>(baseAtk * (isHard ? 1.3f : 1.0f)); // 攻击力不宜加太多，否则容易暴死
    e.def = static_cast<int>(baseDef * (isHard ? 1.2f : 1.0f));
    e.extraLives = extraLives;
    return e;
}

Enemy createEnemy(EnemyType type, bool isHard) 
{
    switch (type) {
        // ===== 森林 =====
        case EnemyType::Goblin:                     return makeEnemy("Goblin", 6, 3, 0, isHard);
        case EnemyType::WanderingMerchant_Forest:   return makeEnemy("Merchant (Forest)", 10, 4, 6, isHard);
        case EnemyType::Tiger:                      return makeEnemy("Tiger", 9, 5, 1, isHard);
        case EnemyType::Thief:                      return makeEnemy("Thief", 6, 4, 1, isHard);
        case EnemyType::Rabbit:                     return makeEnemy("Rabbit", 3, 1, 0, isHard);
        case EnemyType::Hellhound:                  return makeEnemy("Hellhound", 6, 3, 0, isHard);
        case EnemyType::BrownBear:                  return makeEnemy("Brown Bear", 12, 6, 4, isHard);
        case EnemyType::TreantBoss:                 return makeEnemy("Dryad (BOSS)", 18, 7, 5, 1, isHard);

        // ===== 高山 =====
        case EnemyType::Griffon:                    return makeEnemy("Griffin", 10, 6, 2, isHard);
        case EnemyType::Bandit:                     return makeEnemy("Bandit", 6, 4, 1, isHard);
        case EnemyType::FireSprite:                 return makeEnemy("Fire Spirit", 12, 7, 0, isHard);
        case EnemyType::Dragon:                     return makeEnemy("Dragon", 14,8,6, isHard);
        case EnemyType::WanderingMerchant_Mountain: return makeEnemy("Merchant (Mountain)", 10, 4, 6, isHard);
        case EnemyType::RockGiantBoss:              return makeEnemy("Rock Giant (BOSS)", 22, 10, 7, isHard);

        // ===== 深渊 =====
        case EnemyType::EvilCreature:               return makeEnemy("Evil Creature", 14, 8, 6, isHard);
        case EnemyType::DragonkinSoldier:           return makeEnemy("Dragon Soldier", 14, 8, 7, isHard);
        case EnemyType::ArchDemon:                  return makeEnemy("Great Demon", 18, 9, 8, isHard);
        case EnemyType::WanderingMerchant_Abyss:    return makeEnemy("Merchant (Abyss)", 12, 6, 6, isHard);
        case EnemyType::DemonKingBoss:              return makeEnemy("Demon King (BOSS)", 24, 14, 10, isHard);
    }

    return makeEnemy("Unknown", 1, 0, 0, isHard);
}

Enemy createBoss(int stage, bool isHard) {
    if (stage == 1) return createEnemy(EnemyType::TreantBoss, isHard);
    if (stage == 2) return createEnemy(EnemyType::RockGiantBoss, isHard);
    if (stage == 3) return createEnemy(EnemyType::DemonKingBoss, isHard);
    return createEnemy(EnemyType::TreantBoss, isHard);
}