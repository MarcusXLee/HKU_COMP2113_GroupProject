#include "enemy.h"
#include <stdexcept>

/*
  Source of combat stats:
  - Use the "table" you provided (Easy/Hard, hp/atk/def per region).
  Source of loot & special mechanics:
  - Use the "original text" below the table (revive, chain fights, shuffle, demon king scaling, rewards).
*/

static Difficulty gDifficulty = Difficulty::Easy;

void setGameDifficulty(Difficulty d) {
  gDifficulty = d;
}

Difficulty getGameDifficulty() {
  return gDifficulty;
}

static Enemy makeBaseEnemy(
    EnemyId id,
    const std::string &name,
    Region region,
    int maxHp,
    int atk,
    int def
) {
  Enemy e{};
  e.id = id;
  e.name = name;
  e.region = region;

  e.maxHp = maxHp;
  e.hp = maxHp;
  e.atk = atk;
  e.def = def;

  e.isBoss = false;
  e.requiredWins = 1;
  e.shufflePlayerStatsInBattle = false;
  e.demonKingGoodnessScaling = false;

  e.rewardGold = 0;
  e.rewardGoodness = 0;
  e.rewardAtk = 0;
  e.rewardDef = 0;
  e.rewardMaxHp = 0;
  e.rewardHealToFull = false;

  return e;
}

Enemy createEnemy(EnemyId id) {
  return createEnemy(id, gDifficulty);
}

Enemy createEnemy(EnemyId id, Difficulty d) {
  const bool hard = (d == Difficulty::Hard);

  switch (id) {
    // =========================
    // Forest
    // =========================
    case EnemyId::Goblin: {
      // Table:
      // Easy: hp4 atk2 def0
      // Hard: hp5 atk2 def0
      Enemy e = makeBaseEnemy(
        id, "哥布林", Region::Forest,
        hard ? 5 : 4,
        2,
        0
      );
      // Loot: +3 gold
      e.rewardGold = 3;
      return e;
    }

    case EnemyId::WanderingMerchant_Forest: {
      // Table:
      // Easy: hp8 atk6 def5
      // Hard: hp10 atk7 def5
      Enemy e = makeBaseEnemy(
        id, "流浪商人", Region::Forest,
        hard ? 10 : 8,
        hard ? 7 : 6,
        5
      );
      // Loot: +60 gold
      e.rewardGold = 60;
      return e;
    }

    case EnemyId::Tiger: {
      // Table:
      // Easy: hp7 atk4 def1
      // Hard: hp8 atk5 def2
      Enemy e = makeBaseEnemy(
        id, "猛虎", Region::Forest,
        hard ? 8 : 7,
        hard ? 5 : 4,
        hard ? 2 : 1
      );
      // Loot: +15 gold, +2 goodness
      e.rewardGold = 15;
      e.rewardGoodness = 2;
      return e;
    }

    case EnemyId::Thief: {
      // Table:
      // Easy: hp5 atk3 def1
      // Hard: hp6 atk4 def1
      Enemy e = makeBaseEnemy(
        id, "恶贼", Region::Forest,
        hard ? 6 : 5,
        hard ? 4 : 3,
        1
      );
      // Loot: +10 gold
      e.rewardGold = 10;
      return e;
    }

    case EnemyId::Rabbit: {
      // Table:
      // Easy: hp1 atk0 def0
      // Hard: hp2 atk0 def0
      Enemy e = makeBaseEnemy(
        id, "兔子", Region::Forest,
        hard ? 2 : 1,
        0,
        0
      );
      // Loot: +1 gold
      e.rewardGold = 1;
      return e;
    }

    case EnemyId::Hellhound: {
      // Table:
      // Easy: hp4 atk2 def0
      // Hard: hp5 atk3 def0
      Enemy e = makeBaseEnemy(
        id, "魔犬", Region::Forest,
        hard ? 5 : 4,
        hard ? 3 : 2,
        0
      );
      // Loot: +3 gold
      e.rewardGold = 3;
      return e;
    }

    case EnemyId::BrownBear: {
      // Table:
      // Easy: hp8 atk4 def2
      // Hard: hp10 atk5 def2
      Enemy e = makeBaseEnemy(
        id, "棕熊", Region::Forest,
        hard ? 10 : 8,
        hard ? 5 : 4,
        2
      );
      // Loot: +10 gold
      e.rewardGold = 10;
      return e;
    }

    case EnemyId::TreantGuardian: {
      // Table:
      // Easy: hp10 atk5 def3
      // Hard: hp12 atk6 def4
      Enemy e = makeBaseEnemy(
        id, "树精（森林的守护者）", Region::Forest,
        hard ? 12 : 10,
        hard ? 6 : 5,
        hard ? 4 : 3
      );
      e.isBoss = true;
      // Special: must defeat twice
      e.requiredWins = 2;

      // Loot:
      // +20 gold, heal to full, +2 atk, +3 def
      e.rewardGold = 20;
      e.rewardHealToFull = true;
      e.rewardAtk = 2;
      e.rewardDef = 3;
      return e;
    }

    // =========================
    // Mountain
    // =========================
    case EnemyId::Griffon: {
      // Table:
      // Easy: hp10 atk5 def2
      // Hard: hp12 atk6 def3
      Enemy e = makeBaseEnemy(
        id, "狮鹫", Region::Mountain,
        hard ? 12 : 10,
        hard ? 6 : 5,
        hard ? 3 : 2
      );
      e.rewardGold = 20;
      return e;
    }

    case EnemyId::Bandit: {
      // Table:
      // Easy: hp4 atk3 def1
      // Hard: hp5 atk4 def1
      Enemy e = makeBaseEnemy(
        id, "山贼", Region::Mountain,
        hard ? 5 : 4,
        hard ? 4 : 3,
        1
      );
      // Special: 连战5次（战斗层按 requiredWins 处理）
      e.requiredWins = 5;

      // Loot: +20 gold, +3 goodness
      e.rewardGold = 20;
      e.rewardGoodness = 3;
      return e;
    }

    case EnemyId::FireSprite: {
      // Table:
      // Easy: hp8 atk7 def0
      // Hard: hp9 atk8 def0
      Enemy e = makeBaseEnemy(
        id, "火焰精灵", Region::Mountain,
        hard ? 9 : 8,
        hard ? 8 : 7,
        0
      );
      // Loot in your text is empty -> keep 0
      return e;
    }

    case EnemyId::Dragon: {
      // Table:
      // Easy: hp12 atk7 def4
      // Hard: hp14 atk8 def5
      Enemy e = makeBaseEnemy(
        id, "飞龙", Region::Mountain,
        hard ? 14 : 12,
        hard ? 8 : 7,
        hard ? 5 : 4
      );
      // Loot: +100 gold, -2 goodness
      e.rewardGold = 100;
      e.rewardGoodness = -2;
      return e;
    }

    case EnemyId::WanderingMerchant_Mountain: {
      // Table:
      // Easy: hp10 atk7 def5
      // Hard: hp12 atk8 def6
      Enemy e = makeBaseEnemy(
        id, "流浪商人", Region::Mountain,
        hard ? 12 : 10,
        hard ? 8 : 7,
        hard ? 6 : 5
      );
      e.rewardGold = 60;
      return e;
    }

    case EnemyId::RockGiant: {
      // Table:
      // Easy: hp16 atk8 def7
      // Hard: hp18 atk9 def8
      Enemy e = makeBaseEnemy(
        id, "岩石巨人", Region::Mountain,
        hard ? 18 : 16,
        hard ? 9 : 8,
        hard ? 8 : 7
      );
      e.isBoss = true;
      e.rewardGold = 150;
      return e;
    }

    // =========================
    // Abyss
    // =========================
    case EnemyId::EvilCreature: {
      // Table:
      // Easy: hp14 atk8 def6
      // Hard: hp16 atk9 def7
      Enemy e = makeBaseEnemy(
        id, "邪恶生物", Region::Abyss,
        hard ? 16 : 14,
        hard ? 9 : 8,
        hard ? 7 : 6
      );
      // Special: battle shuffles player stats (restore after)
      e.shufflePlayerStatsInBattle = true;

      // Loot: +40 gold, +2 goodness
      e.rewardGold = 40;
      e.rewardGoodness = 2;
      return e;
    }

    case EnemyId::DragonkinSoldier: {
      // Table:
      // Easy: hp14 atk8 def7
      // Hard: hp16 atk9 def8
      Enemy e = makeBaseEnemy(
        id, "龙人士兵", Region::Abyss,
        hard ? 16 : 14,
        hard ? 9 : 8,
        hard ? 8 : 7
      );
      // Loot: +30 gold, +2 goodness
      e.rewardGold = 30;
      e.rewardGoodness = 2;
      return e;
    }

    case EnemyId::ArchDemon: {
      // Table:
      // Easy: hp18 atk9 def8
      // Hard: hp22 atk10 def9
      Enemy e = makeBaseEnemy(
        id, "大恶魔", Region::Abyss,
        hard ? 22 : 18,
        hard ? 10 : 9,
        hard ? 9 : 8
      );
      // Loot: +50 gold, +3 goodness, +2 atk, +2 def
      e.rewardGold = 50;
      e.rewardGoodness = 3;
      e.rewardAtk = 2;
      e.rewardDef = 2;
      return e;
    }

    case EnemyId::WanderingMerchant_Abyss: {
      // Table:
      // Easy: hp12 atk7 def6
      // Hard: hp14 atk8 def7
      Enemy e = makeBaseEnemy(
        id, "流浪商人", Region::Abyss,
        hard ? 14 : 12,
        hard ? 8 : 7,
        hard ? 7 : 6
      );
      e.rewardGold = 60;
      return e;
    }

    case EnemyId::DemonKing: {
      // Table:
      // Easy: hp24 atk12 def10
      // Hard: hp28 atk13 def11
      Enemy e = makeBaseEnemy(
        id, "魔王", Region::Abyss,
        hard ? 28 : 24,
        hard ? 13 : 12,
        hard ? 11 : 10
      );
      e.isBoss = true;
      // Special: atk/def modified by player goodness at battle start
      e.demonKingGoodnessScaling = true;
      // Loot: 通关（由主流程处理）
      return e;
    }

    default:
      throw std::invalid_argument("createEnemy: unsupported EnemyId");
  }
}

Enemy createGoblin() {
  return createEnemy(EnemyId::Goblin);
}

Enemy createTiger() {
  return createEnemy(EnemyId::Tiger);
}

Enemy createBoss(int stage) {
  // stage mapping per header doc
  if (stage == 1) return createEnemy(EnemyId::TreantGuardian);
  if (stage == 2) return createEnemy(EnemyId::RockGiant);
  if (stage == 3) return createEnemy(EnemyId::DemonKing);
  throw std::invalid_argument("createBoss(stage): stage must be 1(Forest) / 2(Mountain) / 3(Abyss)");
}

void applyPreBattleModifiers(Enemy &e, int playerGoodness) {
  // Only Demon King uses goodness scaling in your spec:
  // "atk and def reduce by goodness; if goodness negative, they increase."
  if (!e.demonKingGoodnessScaling) return;

  e.atk -= playerGoodness;
  e.def -= playerGoodness;

  // Optional safety clamp (can remove if you want extreme values):
  if (e.atk < 0) e.atk = 0;
  if (e.def < 0) e.def = 0;
}
