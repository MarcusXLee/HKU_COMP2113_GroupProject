#include <iostream>
#include <cstdlib>
#include "../player/player.h"
#include "../enemy/enemy.h"
#include "common.h"
#include <limits>
#include "../UI/ui.h"
// Note: startBattle() is declared in combat system/Combat.h.
// Add: #include "../combat system/Combat.h"  once that header is finalised.
// For now we forward-declare it so every event file compiles independently.
bool startBattle(Player &player, Enemy &enemy);

using namespace std;

// ---------------------------------------------------------------------------
// Blessing of the God of Battle
// ---------------------------------------------------------------------------
void runBattleGodBlessingEvent(Player &player)
{
    cout << "Blessing of the God of Battle" << endl;
    cout << "After wandering for a while, you discover a statue of the God of Battle." << endl;

    cout << "1. Pray sincerely" << endl;
    cout << "2. Reject the gods" << endl;

    int choice = getValidEventChoice(1, 2);

    if (choice == 1)
    {
        if (getPlayerGold(player) < 20) {
            cout << "The gods do not accept empty promises. You need 20 gold. Nothing happens." << endl;
        }
        else{
            cout << "You kneel and pray for strength to defeat your enemies and avenge the Demon King." << endl;
            cout << "The God of Battle admires your courage and offers power in exchange for gold." << endl;
            changePlayerGold(player, -20);      // Fixed: was changeGold
            changePlayerAttack(player, +1);     // Fixed: was changeAttack
            changePlayerDefense(player, +1);    // Fixed: was changeDefense
        }
    }
    else if (choice == 2)
    {
        cout << "You believe the gods are only illusions." << endl;
        cout << "Only your own strength can lead you to revenge." << endl;
        cout << "Nothing happens." << endl;
    }
}

// ---------------------------------------------------------------------------
// Judgment of Good and Evil
// ---------------------------------------------------------------------------
void runJudgmentEvent(Player &player) {

    cout << "Judgment of Good and Evil" << endl;
    cout << "A statue of the God of Good and Evil stands in the middle of the road." << endl;
    cout << "Every traveler must accept its judgment." << endl;

    int kindness = getPlayerKindness(player);   // Fixed: was [function: getKindness(player)]

    if (kindness >= 5) {
        cout << "Your kindness deserves a reward!" << endl;

        changePlayerMaxHP(player, +5);      // Fixed: was changeMaxHP
        changePlayerAttack(player, +1);     // Fixed: was changeAttack
        changePlayerDefense(player, +1);    // Fixed: was changeDefense
    }
    else if (kindness > 0 && kindness < 5) {
        cout << "Your kindness is worth encouraging!" << endl;

        changePlayerMaxHP(player, +3);      // Fixed: was changeMaxHP
    }
    else if (kindness < 0 && kindness > -5) {
        cout << "This is a warning!" << endl;

        int r = rand() % 2;

        if (r == 0)
        {
            cout << "You lost 1 Attack." << endl;
            changePlayerAttack(player, -1);     // Fixed
        }
        else {
            cout << "You lost 1 Defense." << endl;
            changePlayerDefense(player, -1);    // Fixed
        }
    }
    else if (kindness <= -5) {
        cout << "Your sins are unforgivable. Judgment must be carried out!" << endl;

        changePlayerMaxHP(player, -5);      // Fixed
    }
    else {
        cout << "Nothing happens." << endl;
    }
}

// ---------------------------------------------------------------------------
// Wandering Merchant
// ---------------------------------------------------------------------------
void runMerchantEvent(Player &player, bool isHard) {

    cout << "Wandering Merchant" << endl;
    cout << "A wandering merchant offers many goods for sale." << endl;
    cout << "Use your gold to make a choice." << endl;

    cout << "1. Buy a weapon" << endl;
    cout << "2. Buy an armor" << endl;
    cout << "3. Rob the merchant" << endl;
    cout << "4. Leave peacefully" << endl;

    int choice = getValidEventChoice(1, 4);

    if (choice == 1) {
        cout << "Choose your weapon:" << endl;
        cout << "1. Cheap Weapon (-5 gold, +1 Attack)" << endl;
        cout << "2. Fine Weapon (-15 gold, +2 Attack)" << endl;
        cout << "3. Top Weapon (-25 gold, +3 Attack)" << endl;

        int subChoice = getValidEventChoice(1, 3);
        int cost = (subChoice == 1) ? 5 : (subChoice == 2) ? 15 : 25;
        if (getPlayerGold(player) < cost) {
            cout << "The merchant scoffs at you. 'You don't have enough gold!'" << endl;
        }
        else{
            if (subChoice == 1) {
                changePlayerGold(player, -5);       // Fixed
                changePlayerAttack(player, +1);     // Fixed
                cout << "You bought a cheap weapon." << endl;
            }
            else if (subChoice == 2) {
                changePlayerGold(player, -15);      // Fixed
                changePlayerAttack(player, +2);     // Fixed
                cout << "You bought a fine weapon." << endl;
            }
            else if (subChoice == 3) {
                changePlayerGold(player, -25);      // Fixed
                changePlayerAttack(player, +3);     // Fixed
                cout << "You bought a top weapon." << endl;
            }
        }
    }
    else if (choice == 2) {
        cout << "Choose your armor:" << endl;
        cout << "1. Cheap Armor (-5 gold, +1 Defense)" << endl;
        cout << "2. Fine Armor (-15 gold, +2 Defense)" << endl;
        cout << "3. Top Armor (-25 gold, +3 Defense)" << endl;

        int subChoice = getValidEventChoice(1, 3);
        int cost = (subChoice == 1) ? 5 : (subChoice == 2) ? 15 : 25;
        if (getPlayerGold(player) < cost) {
            cout << "The merchant scoffs at you. 'You don't have enough gold!'" << endl;
        }
        else
        {
            if (subChoice == 1) {
                changePlayerGold(player, -5);       // Fixed
                changePlayerDefense(player, +1);    // Fixed
                cout << "You bought a cheap armor." << endl;
            }
            else if (subChoice == 2) {
                changePlayerGold(player, -15);      // Fixed
                changePlayerDefense(player, +2);    // Fixed
                cout << "You bought a fine armor." << endl;
            }
            else if (subChoice == 3) {
                changePlayerGold(player, -25);      // Fixed
                changePlayerDefense(player, +3);    // Fixed
                cout << "You bought a top armor." << endl;
            }
        }
    }
    else if (choice == 3) {
        cout << "You decide to rob the merchant!" << endl;

        // Fixed: createEnemy takes an int stage; use stage 1 (weakest enemy) as a
        // stand-in for the merchant until a dedicated merchant enemy ID is defined.
        Enemy enemy = createEnemy(EnemyType::WanderingMerchant_Forest, isHard);
        startBattle(player, enemy);
    }
    else if (choice == 4) {
            cout << "You politely decline and continue your journey." << endl;
    }
}

// ---------------------------------------------------------------------------
// Gambling House
// ---------------------------------------------------------------------------
void runGamblingEvent(Player &player) {

    cout << "Gambling House" << endl;
    cout << "You accidentally enter a gambling house." << endl;
    cout << "Do you want to take a gamble?" << endl;

    cout << "1. Small bet" << endl;
    cout << "2. Big bet" << endl;
    cout << "3. All in" << endl;
    cout << "4. Walk away." << endl;

    int choice = getValidEventChoice(1, 4);

    if (choice == 1) {
        if (getPlayerGold(player) < 1) {
            cout << "You don't even have 1 gold to bet! The dealer kicks you out." << endl;
        }
        else{
            int r = rand() % 100;
            if (r < 25) {
                cout << "You lost 1 gold." << endl;
                changePlayerGold(player, -1);       // Fixed
            }
            else if (r < 75) {
                cout << "Nothing happens." << endl;
            }
            else {
                cout << "You won 1 gold!" << endl;
                changePlayerGold(player, +1);       // Fixed
            }
        }
    }
    else if (choice == 2) {
        if (getPlayerGold(player) < 5) {
            cout << "You need at least 5 gold for a big bet! The dealer kicks you out." << endl;
        }
        else{
            int r = rand() % 100;
            if (r < 25) {
                cout << "You lost 5 gold." << endl;
                changePlayerGold(player, -5);       // Fixed
            }
            else if (r < 75) {
                cout << "Nothing happens." << endl;
            }
            else {
                cout << "You won 5 gold!" << endl;
                changePlayerGold(player, +5);       // Fixed
            }
        }
    }
    else if (choice == 3) {
        int r = rand() % 100;
        if (r < 25) {
            cout << "You lost all your gold." << endl;
            setPlayerGold(player, 0);           // Fixed: was loseAllGold (no such function)
        }
        else if (r < 75) {
            cout << "Nothing happens." << endl;
        }
        else {
            cout << "You doubled your gold!" << endl;
            setPlayerGold(player, getPlayerGold(player) * 2); // Fixed: was doubleGold
        }
    }
    else if (choice == 4) {
        cout << "You resist the temptation and leave the gambling house." << endl;
    }
}

// ---------------------------------------------------------------------------
// Food Cart
// ---------------------------------------------------------------------------
void runFoodCartEvent(Player &player) {

    cout << "Food Cart" << endl;
    cout << "The food cart arrives. Spend your gold to enjoy some perfect meals!" << endl;

    cout << "1. Have a snack (-2 gold, restore 10% HP)" << endl;
    cout << "2. Have a full meal (-5 gold, restore 30% HP)" << endl;
    cout << "3. Try magical food (-15 gold)" << endl;
    cout << "4. Not hungry, leave" << endl;


    int choice = getValidEventChoice(1, 4);

    if (choice == 1) {
        if (getPlayerGold(player) < 2) {
            cout << "'No money, no food!' The vendor ignores you." << endl;
        }
        else{
            cout << "You enjoy a small snack." << endl;
            changePlayerGold(player, -2);                                  
            healPlayer(player, getPlayerMaxHP(player) * 10 / 100);   
        }
    }
    else if (choice == 2) {
        if (getPlayerGold(player) < 5) {
            cout << "'No money, no food!' The vendor ignores you." << endl;
        }
        else{
            cout << "You enjoy a full meal." << endl;
            changePlayerGold(player, -5);                                   // Fixed
            healPlayer(player, getPlayerMaxHP(player) * 30 / 100);
        }
    }
    else if (choice == 3) {
        if (getPlayerGold(player) < 15) {
            cout << "'No money, no food!' The vendor ignores you." << endl;
        }
        else{
            cout << "You try the magical food..." << endl;
            changePlayerGold(player, -15);
            
            int r = rand() % 2;
            if (r == 0) {
                cout << "You lost some Attack but gained great Defense!" << endl;
                int loss = rand() % 4 + 1;
                changePlayerAttack(player, -loss);
                changePlayerDefense(player, 2 * loss);
            } 
            else {
                cout << "You lost some Defense but gained great Attack!" << endl;
                int loss = rand() % 4 + 1;
                changePlayerDefense(player, -loss);
                changePlayerAttack(player, 2 * loss);
            }
        }
    }
    else if (choice == 4) {
        cout << "You are not hungry right now and walk away." << endl;
    }
}

// ---------------------------------------------------------------------------
// Blessing of the God of Revenge
// ---------------------------------------------------------------------------
void runRevengeGodBlessingEvent(Player &player) {

    cout << "Blessing of the God of Revenge" << endl;
    cout << "Guided by the God of Revenge, you arrive before the statue." << endl;
    cout << "Your hatred toward the Demon King pleases the god." << endl;

    cout << "1. Rational revenge" << endl;
    cout << "2. Aggressive revenge" << endl;
    cout << "3. Mad revenge" << endl;

    int choice = getValidEventChoice(1, 3);

    if (choice == 1) {
        cout << "The God of Revenge is disappointed, but still grants you power." << endl;

        changePlayerAttack(player, +1);     // Fixed
    }
    else if (choice == 2) {
        cout << "The god approves your determination and demands a price." << endl;

        damagePlayer(player, 5);            // Fixed
        changePlayerAttack(player, +3);     // Fixed
    }
    else if (choice == 3) {
        cout << "The God of Revenge is finally satisfied." << endl;
        cout << "You give up everything for ultimate power." << endl;

        leavePlayerAtOneHP(player);                                     // Fixed: was setHPToOne
        int currentAtk = getPlayerAttack(player);
        setPlayerAttack(player, currentAtk * 2);
    }
}

// ---------------------------------------------------------------------------
// Master Hermit
// ---------------------------------------------------------------------------
void runMasterHermitEvent(Player &player) {

    cout << "Master Hermit" << endl;
    cout << "You encounter a reclusive master and seek guidance in martial arts." << endl;

    cout << "1. Follow the balanced path" << endl;
    cout << "2. Take an unconventional approach" << endl;

    int choice = getValidEventChoice(1, 2);

    if (choice == 1) {
        cout << "The master teaches you a balanced style." << endl;

        changePlayerAttack(player, +1);     // Fixed
        changePlayerDefense(player, +1);    // Fixed
    }
    else if (choice == 2) {
        cout << "The master reshapes your abilities in an unpredictable way..." << endl;

        int hp  = getPlayerHP(player);          // Fixed: was getHP
        int atk = getPlayerAttack(player);      // Fixed: was getAttack
        int def = getPlayerDefense(player);     // Fixed: was getDefense

        int stats[3] = {hp, atk, def};

        for (int i = 0; i < 3; i++) {
            int j = rand() % 3;
            int temp = stats[i];
            stats[i] = stats[j];
            stats[j] = temp;
        }

        setPlayerHP(player, stats[0]);          // Fixed: was setHP
        setPlayerAttack(player, stats[1]);      // Fixed: was setAttack
        setPlayerDefense(player, stats[2]);     // Fixed: was setDefense

        cout << "Your stats have been reshuffled!" << endl;
    }
    else {
        cout << "Invalid choice. Nothing happens." << endl;
    }
}

int getValidEventChoice(int min, int max) {
    UIManager ui; // 实例化 UI 对象用来调用 roast
    int choice;
    while (true) {
        // 如果输入合法，直接返回
        if (cin >> choice && choice >= min && choice <= max) {
            return choice;
        }
        // 如果输入不合法（如字母或越界数字），触发嘲讽！
        ui.printRandomRoast(); 
        cout << "Your choice (" << min << " - " << max << "): ";

        // 清除输入流的错误状态并清空缓冲区
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}