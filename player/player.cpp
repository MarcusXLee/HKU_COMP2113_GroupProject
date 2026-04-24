#include "player.h"

static int clampNonNegative(int value) {
    return (value < 0) ? 0 : value;
}

static int clampAtLeastOne(int value) {
    return (value < 1) ? 1 : value;
}

static void clampPlayerHP(Player &p) {
    if (p.hp < 0) p.hp = 0;
    if (p.hp > p.maxHp) p.hp = p.maxHp;
}

Player createPlayer(int difficulty) {
    Player p;

    if (difficulty == HARD_MODE) {
        p.maxHp = 20;
        p.hp = 20;
        p.attack = 7;
        p.defense = 2;
        p.gold = 10;
        p.kindness = 0;
    } else {
        p.maxHp = 24;
        p.hp = 24;
        p.attack = 8;
        p.defense = 3;
        p.gold = 10;
        p.kindness = 0;
    }

    p.savedHp = p.hp;
    p.savedAttack = p.attack;
    p.savedDefense = p.defense;
    p.combatStateSaved = false;

    return p;
}

int getPlayerHP(const Player &p) {
    return p.hp;
}

int getPlayerMaxHP(const Player &p) {
    return p.maxHp;
}

int getPlayerAttack(const Player &p) {
    return p.attack;
}

int getPlayerDefense(const Player &p) {
    return p.defense;
}

int getPlayerGold(const Player &p) {
    return p.gold;
}

int getPlayerKindness(const Player &p) {
    return p.kindness;
}

void setPlayerHP(Player &p, int hp) {
    p.hp = hp;
    clampPlayerHP(p);
}

void setPlayerMaxHP(Player &p, int maxHp) {
    p.maxHp = clampAtLeastOne(maxHp);
    clampPlayerHP(p);
}

void setPlayerAttack(Player &p, int attack) {
    p.attack = clampNonNegative(attack);
}

void setPlayerDefense(Player &p, int defense) {
    p.defense = clampNonNegative(defense);
}

void setPlayerGold(Player &p, int gold) {
    p.gold = clampNonNegative(gold);
}

void setPlayerKindness(Player &p, int kindness) {
    p.kindness = kindness;
}

void damagePlayer(Player &p, int dmg) {
    if (dmg <= 0) return;
    p.hp -= dmg;
    clampPlayerHP(p);
}

void healPlayer(Player &p, int amount) {
    if (amount <= 0) return;
    p.hp += amount;
    clampPlayerHP(p);
}

void healPlayerPercent(Player &p, int percent) {
    if (percent <= 0) return;
    int amount = p.maxHp * percent / 100;
    healPlayer(p, amount);
}

void fullHealPlayer(Player &p) {
    p.hp = p.maxHp;
}

void loseHpByMaxHpPercent(Player &p, int percent) {
    if (percent <= 0) return;
    int amount = p.maxHp * percent / 100;
    damagePlayer(p, amount);
}

void changePlayerMaxHP(Player &p, int amount) {
    p.maxHp = clampAtLeastOne(p.maxHp + amount);
    clampPlayerHP(p);
}

void changePlayerAttack(Player &p, int amount) {
    p.attack = clampNonNegative(p.attack + amount);
}

void changePlayerDefense(Player &p, int amount) {
    p.defense = clampNonNegative(p.defense + amount);
}

void changePlayerGold(Player &p, int amount) {
    p.gold = clampNonNegative(p.gold + amount);
}

void changePlayerKindness(Player &p, int amount) {
    p.kindness += amount;
}

bool isPlayerAlive(const Player &p) {
    return p.hp > 0;
}

void leavePlayerAtOneHP(Player &p) {
    p.hp = 1;
    clampPlayerHP(p);
}

void resetKindnessToZero(Player &p) {
    p.kindness = 0;
}

int getMissingHP(const Player &p) {
    return p.maxHp - p.hp;
}

void convertMissingHpToAttack(Player &p) {
    int missing = getMissingHP(p);
    if (missing > 0) {
        p.attack += missing;
    }
}

void upgradePlayer(Player &p, int choice, int amount) {
    if (amount <= 0) return;

    if (choice == UPGRADE_ATTACK) {
        changePlayerAttack(p, amount);
    } else if (choice == UPGRADE_DEFENSE) {
        changePlayerDefense(p, amount);
    } else if (choice == UPGRADE_MAX_HP) {
        changePlayerMaxHP(p, amount);
        fullHealPlayer(p);
    }
}

void saveCombatState(Player &p) {
    p.savedHp = p.hp;
    p.savedAttack = p.attack;
    p.savedDefense = p.defense;
    p.combatStateSaved = true;
}

void setCombatState(Player &p, int hp, int attack, int defense) {
    setPlayerHP(p, hp);
    setPlayerAttack(p, attack);
    setPlayerDefense(p, defense);
}

void restoreCombatState(Player &p) {
    if (!p.combatStateSaved) return;

    p.hp = p.savedHp;
    p.attack = p.savedAttack;
    p.defense = p.savedDefense;

    clampPlayerHP(p);
    p.attack = clampNonNegative(p.attack);
    p.defense = clampNonNegative(p.defense);

    p.combatStateSaved = false;
}
