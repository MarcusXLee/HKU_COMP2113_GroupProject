#include <iostream>
#include "../player/player.h"
using namespace std;

void runAbyssEvent(int eventId, Player &player) {

  //event 1
  if (eventId == 1) {
    runBattleGodBlessingEvent(player);
  }


    
  //event 2
  else if (eventId == 2) {
    runJudgmentEvent(player);
  }


  //event 3
  else if (eventId == 3) {
    runMerchantEvent(player);
  }

    
  //event 4
  else if (eventId == 4) {
    runGamblingEvent(player);
  }


  //event 5
  else if (eventId == 5) {
    runFoodCartEvent(player);
  }


  //event 6
  else if (eventId == 6) {
    runRevengeGodBlessingEvent(player);  
  }


  //event 7
  else if (eventId == 7) {
    runMasterHermitEvent(player);


  //event 8
    else if (eventId == 8) {

        cout << "Evil Creature" << endl;
        cout << "In the abyss, you encounter an indescribable evil creature approaching you." << endl;

        cout << "1. Avoid it" << endl;
        cout << "2. Destroy it" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You avoid the evil creature, but you are still cursed by it." << endl;

            changeAttack(player, -3);    // F
            changeDefense(player, -2);   // F
            changeMaxHP(player, -1);     //F
        }
        else if (choice == 2) {
            cout << "You decide to destroy the evil creature." << endl;

            Enemy enemy = createEnemy(evil_creature_id);   // F
            startBattle(player, enemy);                    // F
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

        Enemy enemy = createEnemy(dragon_soldier_id);   // F
        startBattle(player, enemy);                     // F
    }

      

    // event 10
    else if (eventId == 10) {

        cout << "Great Demon!" << endl;
        cout << "A Great Demon stands before you." << endl;
        cout << "Its hands are stained with human blood." << endl;

        Enemy enemy = createEnemy(greater_demon_id);   // F
        startBattle(player, enemy);                    // F
    }

    // event 11
    else if (eventId == 11) {

        cout << "The Gaze from the End of the Abyss" << endl;
        cout << "The existence at the end of the abyss seems to have sensed your arrival." << endl;
        cout << "You feel that some terrifying being is watching you from the darkness." << endl;

        changeAttack(player, -3);    // F
        changeDefense(player, -3);   // F
        changeMaxHP(player, -3);     // F
    }



    // event 12
    else if (eventId == 12) {

        cout << "The God of Good and Evil Descends!" << endl;
        cout << "The God of Good and Evil enters your dream." << endl;
        cout << "It is time for judgment based on everything you have done on your journey." << endl;

        int kindness = getKindness(player);   // F

        if (kindness >= 10) {
            cout << "Your soul has reached a higher state. All your powers are doubled!" << endl;

            int atk = getAttack(player);      // F
            int def = getDefense(player);     //F
            int maxHP = getMaxHP(player);     //F
            int hp = getHP(player);           // F

            changeAttack(player, atk);        // F
            changeDefense(player, def);       // F
            changeMaxHP(player, maxHP);       //F
            healPlayer(player, hp);           // F
        }
        else if (kindness >= 5) {
            cout << "Your actions are worthy of a great blessing." << endl;

            int r = rand() % 3;

            if (r == 0) {
                int atk = getAttack(player);
                int def = getDefense(player);

                changeAttack(player, atk);    // F
                changeDefense(player, def);   // F

                cout << "Your Attack and Defense are doubled!" << endl;
            }
            else if (r == 1) {
                int atk = getAttack(player);
                int maxHP = getMaxHP(player);
                int hp = getHP(player);

                changeAttack(player, atk);    // F
                changeMaxHP(player, maxHP);   // F
                healPlayer(player, hp);       // F

                cout << "Your Attack and HP are doubled!" << endl;
            }
            else {
                int def = getDefense(player);
                int maxHP = getMaxHP(player);
                int hp = getHP(player);

                changeDefense(player, def);   // F
                changeMaxHP(player, maxHP);   // F
                healPlayer(player, hp);       // F

                cout << "Your Defense and HP are doubled!" << endl;
            }
        }
        else if (kindness >= 0) {
            cout << "You receive a modest blessing." << endl;

            int r = rand() % 3;

            if (r == 0) {
                int atk = getAttack(player);
                changeAttack(player, atk);    // F
                cout << "Your Attack is doubled!" << endl;
            }
            else if (r == 1) {
                int def = getDefense(player);
                changeDefense(player, def);   // F
                cout << "Your Defense is doubled!" << endl;
            }
            else {
                int maxHP = getMaxHP(player);
                int hp = getHP(player);

                changeMaxHP(player, maxHP);   // F
                healPlayer(player, hp);       // F

                cout << "Your HP is doubled!" << endl;
            }
        }
        else {
            cout << "Your actions invite punishment instead of blessing." << endl;

            int r = rand() % 3;

            if (r == 0) {
                int atk = getAttack(player) / 2;
                changeAttack(player, -atk);   // F
                cout << "Your Attack is halved!" << endl;
            }
            else if (r == 1) {
                int def = getDefense(player) / 2;
                changeDefense(player, -def);  // F
                cout << "Your Defense is halved!" << endl;
            }
            else {
                int maxHP = getMaxHP(player) / 2;
                int hp = getHP(player) / 2;

                changeMaxHP(player, -maxHP);  // F
                damagePlayer(player, hp);     // F

                cout << "Your HP is halved!" << endl;
            }
        }
    }



    // event 13
      
    else if (eventId == 13) {

        cout << "Encouragement of the God of Revenge!" << endl;
        cout << "The God of Revenge admires your courage for entering the abyss alone." << endl;
        cout << "For once, the god decides to be generous." << endl;

        int lostHP = getMaxHP(player) - getHP(player);   // F
        changeAttack(player, lostHP);                    // F

        cout << "Your pain has been transformed into strength." << endl;
        cout << "You gained " << lostHP << " Attack." << endl;
    }



      
    // event 14
    else if (eventId == 14) {

        cout << "Hope!" << endl;
        cout << "In the abyss, you find the remains of a fallen adventurer." << endl;
        cout << "A noble soul rises from the bones and grants you hope to defeat the Demon King." << endl;

        changeKindness(player, +5);   // F
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
            int gold = getGold(player);          // F
            int gain = gold / 10;                // F

            loseAllGold(player);                 // F
            changeAttack(player, gain);          // F
            changeDefense(player, gain);         // F

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

        Enemy enemy = createEnemy(demon_king_id);   // F
        bool win = startBattle(player, enemy);      // F

        if (win) {
            cout << "You defeated the Demon King!" << endl;
            cout << "Your revenge is complete." << endl;
        }
        else {
            cout << "You were defeated by the Demon King..." << endl;
        }
    }
}
