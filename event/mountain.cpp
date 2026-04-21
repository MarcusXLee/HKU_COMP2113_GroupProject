#include <iostream>
using namespace std;

void runForestEvent(int eventId, Player &player) {
    
//event 1
    else if (eventId == 1) {
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
    else if (eventId == 55) {
       runFoodCartEvent(player);
   }

//event 6
    else if (eventId == 6) {
       runRevengeGodBlessingEvent(player);
    }  


    // event 7
    else if (eventId == 7) {

        cout << "Landslide!" << endl;

        cout << "1. Drop everything and run for your life" << endl;
        cout << "2. Leave it to fate" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You throw away your equipment and escape in panic." << endl;

            changeAttack(player, -3);   //F
            changeDefense(player, -3);  //F
            changeGold(player, -10);    //F
        }
        else if (choice == 2) {
            cout << "You decide to leave it to fate." << endl;

            int damage = rand() % 10 + 1;
            damagePlayer(player, damage);   // lose 1 to 10 HP

            cout << "You lost " << damage << " HP." << endl;
        }
        else {
            cout << "Invalid choice. Nothing happens." << endl;
        }
    }


    // event 8
    else if (eventId == 8) {

        cout << "Griffin Attack!" << endl;
        cout << "A griffin suddenly swoops down from the sky!" << endl;

        Enemy enemy = createEnemy(griffin_id);   //F
        startBattle(player, enemy);              //F
    }



    // event 9
    else if (eventId == 9) {

        cout << "Blessing of the God of the Mountain" << endl;
        cout << "You arrive at the statue of the God of the Mountain." << endl;
        cout << "Perhaps you need the god's blessing to overcome the hardships ahead." << endl;
        cout << "Like the God of Battle, the God of the Mountain can also be 'persuaded' with gold." << endl;

        cout << "1. Kneel and pray sincerely" << endl;
        cout << "2. Reject the gods" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You kneel before the statue and offer your gold." << endl;

            changeGold(player, -20);      //F
            changeDefense(player, +3);    //F
        }
        else if (choice == 2) {
            cout << "You believe gods are only illusions." << endl;
            cout << "Unlike the God of Battle, the God of the Mountain is not merciful." << endl;
            cout << "You are cursed for your arrogance." << endl;

            changeAttack(player, -1);     //F
        }
        else {
            cout << "Invalid choice. Nothing happens." << endl;
        }
    }

    //event 10
    else if (eventId == 10){
        runMasterHermitEvent(player);
    }

        // ========================
    // Event 11: Bandit Invasion
    // ========================
    else if (eventId == 11) {

        cout << "Bandit Invasion" << endl;
        cout << "A group of bandits are terrorizing this area." << endl;
        cout << "Do you have the courage to stop them?" << endl;

        cout << "1. Stay cowardly" << endl;
        cout << "2. Fight for justice" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You decide not to get involved." << endl;

            changeKindness(player, -3);   //F
        }
        else if (choice == 2) {
            cout << "You decide to stand up against the bandits!" << endl;

            Enemy enemy = createEnemy(bandit_id);   //F
            startBattle(player, enemy);             //F
        }
        else {
            cout << "Invalid choice. Nothing happens." << endl;
        }
    }


    // event 12
    else if (eventId == 12) {

        cout << "Fire Spirit" << endl;
        cout << "This is a volcano. The burning lava has given birth to a Fire Spirit." << endl;

        cout << "1. Hunt the Fire Spirit" << endl;
        cout << "2. Trade fairly" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You attack the Fire Spirit." << endl;

            changeKindness(player, -1);   // F

            Enemy enemy = createEnemy(fire_spirit_id);  //F
            startBattle(player, enemy);                 // F
        }
        else if (choice == 2) {
            cout << "You trade gold for the spirit's flame." << endl;

            changeGold(player, -10);     // F
            changeKindness(player, +1);  // F
            changeAttack(player, +1);    // F
        }
        else {
            cout << "Invalid choice. Nothing happens." << endl;
        }
    }


    // event 13
    else if (eventId == 13) {

        cout << "Dragon Egg!" << endl;
        cout << "At the mountain peak, you discover a sleeping dragon and a dragon egg." << endl;

        cout << "1. Walk away quietly" << endl;
        cout << "2. Steal the egg" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Even though the egg is priceless, you dare not wake the dragon." << endl;
            cout << "Nothing happens." << endl;
        }
        else if (choice == 2) {
            cout << "You attempt to steal the dragon egg..." << endl;

            changeKindness(player, -1);   // F

            int r = rand() % 100;

            if (r < 25) {
                cout << "You successfully stole the egg without waking the dragon!" << endl;

                changeGold(player, +50);  //F
            }
            else {
                cout << "You wake the dragon. You must face its wrath!" << endl;

                Enemy enemy = createEnemy(dragon_id);   // F
                startBattle(player, enemy);             //F
            }
        }
        else {
            cout << "Invalid choice. Nothing happens." << endl;
        }
    }

        

    // event 14
    else if (eventId == 14) {

        cout << "Stone Giant" << endl;
        cout << "To leave the mountains and descend into the abyss," << endl;
        cout << "you must defeat the guardian of the Demon King — the Stone Giant." << endl;

        cout << "Prepare for battle!" << endl;

        Enemy enemy = createEnemy(stone_giant_id);   // create stone giant boss
        bool win = startBattle(player, enemy);       // start battle

        if (win) {
            cout << "You defeated the Stone Giant!" << endl;
            cout << "The path to the abyss is now open." << endl;
        } else {
            cout << "You were defeated by the Stone Giant..." << endl;
        }
    }
}
