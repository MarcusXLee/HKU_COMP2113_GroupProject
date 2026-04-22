#pragma once
#include <string>

/**
 * @brief Game difficulty.
 */
enum class Difficulty {
  Easy = 0,
  Hard = 1
};

/**
 * @brief Region (stage) in the story.
 */
enum class Region {
  Forest = 1,
  Mountain = 2,
  Abyss = 3
};

/**
 * @brief Enemy identifiers. (You can ignore the ones you don't use yet.)
 */
enum class EnemyId {
  // Forest
  Goblin,
  WanderingMerchant_Forest,
  Tiger,
  Thief,
  Rabbit,
  Hellhound,
  BrownBear,
  TreantGuardian,  // Forest boss (Tree spirit)

  // Mountain
  Griffon,
  Bandit,
  FireSprite,
  Dragon,
  WanderingMerchant_Mountain,
  RockGiant,       // Mountain boss

  // Abyss
  EvilCreature,
  DragonkinSoldier,
  ArchDemon,
  WanderingMerchant_Abyss,
  DemonKing        // Final boss
};

/**
 * @brief Enemy data struct used by battle system.
 *
 * Fields are intentionally "plain" so you can easily save/load if needed later.
 */
struct Enemy {
  // Identity
  EnemyId id;
  std::string name;
  Region region;

  // Combat stats (battle uses these)
  int maxHp;
  int hp;
  int atk;
  int def;

  // Flags / mechanics
  bool isBoss;
  int requiredWins;                 // e.g. Treant=2, Bandit group=5
  bool shufflePlayerStatsInBattle;  // Abyss evil creature
  bool demonKingGoodnessScaling;    // Demon King modifies atk/def by player's goodness

  // Rewards (applied by your battle/event code after victory)
  int rewardGold;
  int rewardGoodness;
  int rewardAtk;
  int rewardDef;
  int rewardMaxHp;
  bool rewardHealToFull;
};

/**
 * @brief Set the current game difficulty used by createGoblin/createTiger/createBoss/createEnemy(id).
 * @param d Difficulty (Easy/Hard).
 * @return void.
 */
void setGameDifficulty(Difficulty d);

/**
 * @brief Get the current game difficulty.
 * @return Current difficulty.
 */
Difficulty getGameDifficulty();

/**
 * @brief Create a Goblin enemy (Forest).
 * @return Enemy object (hp initialized to maxHp).
 */
Enemy createGoblin();

/**
 * @brief Create a Tiger enemy (Forest).
 * @return Enemy object (hp initialized to maxHp).
 */
Enemy createTiger();

/**
 * @brief Create a boss by stage.
 *
 * stage mapping (recommended, consistent with your chapters):
 *  1 -> Forest boss: TreantGuardian (tree spirit, requiredWins=2)
 *  2 -> Mountain boss: RockGiant
 *  3 -> Abyss boss: DemonKing
 *
 * @param stage 1/2/3.
 * @return Enemy object.
 */
Enemy createBoss(int stage);

/**
 * @brief Generic factory: create any enemy by id using current difficulty.
 * @param id EnemyId.
 * @return Enemy object.
 */
Enemy createEnemy(EnemyId id);

/**
 * @brief Generic factory: create any enemy by id and explicit difficulty.
 * @param id EnemyId.
 * @param d Difficulty.
 * @return Enemy object.
 */
Enemy createEnemy(EnemyId id, Difficulty d);

/**
 * @brief Apply pre-battle modifiers that depend on player's goodness (used for Demon King).
 * If enemy.demonKingGoodnessScaling is true, this will adjust enemy.atk and enemy.def by -goodness.
 *
 * @param e Enemy (will be modified in-place).
 * @param playerGoodness Player's goodness value (can be negative).
 * @return void.
 */
void applyPreBattleModifiers(Enemy &e, int playerGoodness);
