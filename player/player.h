#ifndef PLAYER_H
#define PLAYER_H

struct Player {
    int hp;
    int maxHp;
    int attack;
    int defense;
    int gold;
    int kindness;

    int savedHp;
    int savedAttack;
    int savedDefense;
    bool combatStateSaved;
};

const int EASY_MODE = 1;
const int HARD_MODE = 2;

const int UPGRADE_ATTACK = 1;
const int UPGRADE_DEFENSE = 2;
const int UPGRADE_MAX_HP = 3;

// Create player with easy or hard initial stats.
Player createPlayer(int difficulty);

// Basic getters.
int getPlayerHP(const Player &p);
int getPlayerMaxHP(const Player &p);
int getPlayerAttack(const Player &p);
int getPlayerDefense(const Player &p);
int getPlayerGold(const Player &p);
int getPlayerKindness(const Player &p);

// Basic setters.
void setPlayerHP(Player &p, int hp);
void setPlayerMaxHP(Player &p, int maxHp);
void setPlayerAttack(Player &p, int attack);
void setPlayerDefense(Player &p, int defense);
void setPlayerGold(Player &p, int gold);
void setPlayerKindness(Player &p, int kindness);

// HP-related changes.
void damagePlayer(Player &p, int dmg);
void healPlayer(Player &p, int amount);
void healPlayerPercent(Player &p, int percent);
void fullHealPlayer(Player &p);
void loseHpByMaxHpPercent(Player &p, int percent);

// Stat changes.
void changePlayerMaxHP(Player &p, int amount);
void changePlayerAttack(Player &p, int amount);
void changePlayerDefense(Player &p, int amount);
void changePlayerGold(Player &p, int amount);
void changePlayerKindness(Player &p, int amount);

// Status checks and special effects.
bool isPlayerAlive(const Player &p);
void leavePlayerAtOneHP(Player &p);
void resetKindnessToZero(Player &p);
int getMissingHP(const Player &p);
void convertMissingHpToAttack(Player &p);

// Apply one post-battle upgrade.
void upgradePlayer(Player &p, int choice, int amount);

// Save and restore temporary combat state.
void saveCombatState(Player &p);
void setCombatState(Player &p, int hp, int attack, int defense);
void restoreCombatState(Player &p);

#endif
