#ifndef COMBAT_H
#define COMBAT_H

#include "../player/player.h"
#include "../enemy/enemy.h"
#include "../UI/ui.h"

// 统一采用全局函数的写法，与你的 combat.cpp 以及各路事件中的调用保持一致
bool startBattle(Player &player, Enemy &enemy, UIManager &ui);

// 重载版本，供 event/xxx.cpp 中的旧代码调用（如果他们在内部不传 ui 对象）
// 你可以在 combat.cpp 中给 UIManager 一个默认行为，或者要求所有 startBattle 必须传入 UIManager。
bool startBattle(Player &player, Enemy &enemy);

#endif