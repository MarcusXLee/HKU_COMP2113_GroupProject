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

    
}
