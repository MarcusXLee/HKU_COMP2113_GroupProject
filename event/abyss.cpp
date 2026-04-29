#include <iostream>
#include <cstdlib>
#include "../player/player.h"
#include "../enemy/enemy.h"
#include "common.h"
// Forward-declare startBattle until Combat.h is finalised.
bool startBattle(Player &player, Enemy &enemy);

using namespace std;

// Enemy stage IDs used in this chapter (must match createBoss/createEnemy conventions).
// Stage 3 = Abyss enemies. Specific non-boss enemies reuse createGoblin/createTiger
// as stand-ins until the full enemy roster is fleshed out.

void runAbyssEvent(int eventId, Player &player) {

    // event 1
    if (eventId == 1) {
        runBattleGodBlessingEvent(player);
    }

    // event 2
    else if (eventId == 2) {
        runJudgmentEvent(player);
    }

    // event 3
    else if (eventId == 3) {
        runMerchantEvent(player);
    }

    // event 4
    else if (eventId == 4) {
        runGamblingEvent(player);
    }

    // event 5
    else if (eventId == 5) {
        runFoodCartEvent(player);
    }

    // event 6
    else if (eventId == 6) {
        runRevengeGodBlessingEvent(player);
    }

    // event 7
    else if (eventId == 7) {
        runMasterHermitEvent(player);
    }   // Fixed: closing brace was missing here; events 8-16 were nested inside event 7

    // event 8
    else if (eventId == 8) {

        cout << "Evil Creature" << endl;
        cout << "In the abyss, you encounter an indescribable evil creature approaching you." << endl;

        cout << "1. Avoid it" << endl;
        cout << "2. Destroy it" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You avoid the evil creature, but you are still cursed by it." << endl;

            changePlayerAttack(player, -3);     // Fixed: was changeAttack
            changePlayerDefense(player, -2);    // Fixed: was changeDefense
            changePlayerMaxHP(player, -1);      // Fixed: was changeMaxHP
        }
        else if (choice == 2) {
            cout << "You decide to destroy the evil creature." << endl;

            // Fixed: evil_creature_id undefined; using createGoblin as stand-in
            Enemy enemy = createGoblin();
            startBattle(player, enemy);
        }
        else {
            cout << "Invalid choice. Nothing happens." << endl;
        }
    }

    // event 9
    else if (eventId == 9) {

        cout << "Dragon Soldier" << endl;
        cout << "Dragon soldiers are servants of the Demon King." << endl;
        cout << "They are hunting you in the abyss." << endl;

        // Fixed: dragon_soldier_id undefined; using createTiger as stand-in
        Enemy enemy = createTiger();
        startBattle(player, enemy);
    }

    // event 10
    else if (eventId == 10) {

        cout << "Great Demon!" << endl;
        cout << "A Great Demon stands before you." << endl;
        cout << "Its hands are stained with human blood." << endl;

        // Fixed: greater_demon_id undefined; using createBoss(2) as stand-in
        Enemy enemy = createBoss(2);
        startBattle(player, enemy);
    }

    // event 11
    else if (eventId == 11) {

        cout << "The Gaze from the End of the Abyss" << endl;
        cout << "The existence at the end of the abyss seems to have sensed your arrival." << endl;
        cout << "You feel that some terrifying being is watching you from the darkness." << endl;

        changePlayerAttack(player, -3);     // Fixed
        changePlayerDefense(player, -3);    // Fixed
        changePlayerMaxHP(player, -3);      // Fixed
    }

    // event 12
    else if (eventId == 12) {

        cout << "The God of Good and Evil Descends!" << endl;
        cout << "The God of Good and Evil enters your dream." << endl;
        cout << "It is time for judgment based on everything you have done on your journey." << endl;

        int kindness = getPlayerKindness(player);   // Fixed: was getKindness

        if (kindness >= 10) {
            cout << "Your soul has reached a higher state. All your powers are doubled!" << endl;

            int atk   = getPlayerAttack(player);    // Fixed: was getAttack
            int def   = getPlayerDefense(player);   // Fixed: was getDefense
            int maxHP = getPlayerMaxHP(player);     // Fixed: was getMaxHP
            int hp    = getPlayerHP(player);        // Fixed: was getHP

            changePlayerAttack(player, atk);        // Fixed
            changePlayerDefense(player, def);       // Fixed
            changePlayerMaxHP(player, maxHP);       // Fixed
            healPlayer(player, hp);                 // Fixed
        }
        else if (kindness >= 5) {
            cout << "Your actions are worthy of a great blessing." << endl;

            int r = rand() % 3;

            if (r == 0) {
                int atk = getPlayerAttack(player);
                int def = getPlayerDefense(player);

                changePlayerAttack(player, atk);    // Fixed
                changePlayerDefense(player, def);   // Fixed

                cout << "Your Attack and Defense are doubled!" << endl;
            }
            else if (r == 1) {
                int atk   = getPlayerAttack(player);
                int maxHP = getPlayerMaxHP(player);
                int hp    = getPlayerHP(player);

                changePlayerAttack(player, atk);    // Fixed
                changePlayerMaxHP(player, maxHP);   // Fixed
                healPlayer(player, hp);             // Fixed

                cout << "Your Attack and HP are doubled!" << endl;
            }
            else {
                int def   = getPlayerDefense(player);
                int maxHP = getPlayerMaxHP(player);
                int hp    = getPlayerHP(player);

                changePlayerDefense(player, def);   // Fixed
                changePlayerMaxHP(player, maxHP);   // Fixed
                healPlayer(player, hp);             // Fixed

                cout << "Your Defense and HP are doubled!" << endl;
            }
        }
        else if (kindness >= 0) {
            cout << "You receive a modest blessing." << endl;

            int r = rand() % 3;

            if (r == 0) {
                int atk = getPlayerAttack(player);
                changePlayerAttack(player, atk);    // Fixed
                cout << "Your Attack is doubled!" << endl;
            }
            else if (r == 1) {
                int def = getPlayerDefense(player);
                changePlayerDefense(player, def);   // Fixed
                cout << "Your Defense is doubled!" << endl;
            }
            else {
                int maxHP = getPlayerMaxHP(player);
                int hp    = getPlayerHP(player);

                changePlayerMaxHP(player, maxHP);   // Fixed
                healPlayer(player, hp);             // Fixed

                cout << "Your HP is doubled!" << endl;
            }
        }
        else {
            cout << "Your actions invite punishment instead of blessing." << endl;

            int r = rand() % 3;

            if (r == 0) {
                int atk = getPlayerAttack(player) / 2;
                changePlayerAttack(player, -atk);   // Fixed
                cout << "Your Attack is halved!" << endl;
            }
            else if (r == 1) {
                int def = getPlayerDefense(player) / 2;
                changePlayerDefense(player, -def);  // Fixed
                cout << "Your Defense is halved!" << endl;
            }
            else {
                int maxHP = getPlayerMaxHP(player) / 2;
                int hp    = getPlayerHP(player) / 2;

                changePlayerMaxHP(player, -maxHP);  // Fixed
                damagePlayer(player, hp);           // Fixed

                cout << "Your HP is halved!" << endl;
            }
        }
    }

    // event 13
    else if (eventId == 13) {

        cout << "Encouragement of the God of Revenge!" << endl;
        cout << "The God of Revenge admires your courage for entering the abyss alone." << endl;
        cout << "For once, the god decides to be generous." << endl;

        int lostHP = getPlayerMaxHP(player) - getPlayerHP(player);  // Fixed
        changePlayerAttack(player, lostHP);                         // Fixed

        cout << "Your pain has been transformed into strength." << endl;
        cout << "You gained " << lostHP << " Attack." << endl;
    }

    // event 14
    else if (eventId == 14) {

        cout << "Hope!" << endl;
        cout << "In the abyss, you find the remains of a fallen adventurer." << endl;
        cout << "A noble soul rises from the bones and grants you hope to defeat the Demon King." << endl;

        changePlayerKindness(player, +5);   // Fixed
    }

    // event 15
    else if (eventId == 15) {

        cout << "The God of Battle Descends!" << endl;
        cout << "The God of Battle enters your dream and demands all the treasure you have collected." << endl;
        cout << "Do not worry. The god promises a fair trade." << endl;

        cout << "1. Deal!" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            int gold = getPlayerGold(player);       // Fixed: was getGold
            int gain = gold / 10;

            setPlayerGold(player, 0);               // Fixed: was loseAllGold
            changePlayerAttack(player, gain);       // Fixed
            changePlayerDefense(player, gain);      // Fixed

            cout << "You gave up all your gold." << endl;
            cout << "You gained " << gain << " Attack and " << gain << " Defense." << endl;
        }
        else {
            cout << "Invalid choice. Nothing happens." << endl;
        }
    }

    // event 16
    else if (eventId == 16) {

        cout << "Demon King!" << endl;
        cout << "At last, you stand before the Demon King." << endl;
        cout << "The time has come to face your greatest enemy." << endl;

        // Fixed: demon_king_id undefined; use createBoss(3) = DemonKing
        Enemy enemy = createBoss(3);
        bool win = startBattle(player, enemy);      // Fixed

        if (win) {
            cout << "You defeated the Demon King!" << endl;
            cout << "Your revenge is complete." << endl;
        }
        else {
            cout << "You were defeated by the Demon King..." << endl;
        }
    }
}