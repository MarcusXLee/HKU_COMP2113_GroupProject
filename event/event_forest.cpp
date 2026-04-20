#include <iostream>
using namespace std;

void runForestEvent(int eventId, Player &player) {

//event 1    
    if (eventId == 1) {

        cout << "Goblin Robbery!" << endl;
        cout << "'Stop right there!'" << endl;
        cout << "Two small goblins jump out from behind a tree. "
             << "They are only half your height, but they threaten you with knives." << endl;

        cout << "1. Give them your gold" << endl;
        cout << "2. Fight back" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You hand over half of your gold. "
                 << "The goblins leave happily and even call you a good person." << endl;

            【function: changeGold(player, -5)】
            【function: changeKindness(player, +1)】
        }
        else if (choice == 2) {
            cout << "You refuse to give up your gold and prepare to fight!" << endl;

            【function: enemy = createEnemy(1)】
            【function: startBattle(player, enemy)】
        }
    }

//event 2
    else if (eventId == 2) {
        runBattleGodBlessingEvent(player);
    }


//event 3        
    else if (eventId == 3) {

        cout << "A Peaceful Village" << endl;
        cout << "After a long journey, you discover a peaceful village hidden in the forest." << endl;
        cout << "You may take a rest... or do something else." << endl;

        cout << "1. Rest" << endl;
        cout << "2. Steal from the blacksmith" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You decide to take a full day of rest." << endl;

            【function: healPlayer(player, 30_percent_maxHP)】
        }
        else if (choice == 2) {
            cout << "You sneak into the blacksmith shop and steal a piece of equipment." << endl;

            【function: changeKindness(player, -1)】

            int r = rand() % 2;

            if (r == 0) {
                cout << "You gained +1 Attack." << endl;
                【function: changeAttack(player, +1)】
            } else {
                cout << "You gained +1 Defense." << endl;
                【function: changeDefense(player, +1)】
            }
        }
    }


//event 4      
    else if (eventId == 4) {

        cout << "Ruined Village" << endl;
        cout << "After a long journey, you find a ruined village hidden in the forest." << endl;
        cout << "Only the elderly, women, and children are left." << endl;

        cout << "1. Rob them" << endl;
        cout << "2. Help them" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "There are no strong men left in the village." << endl;
            cout << "You rob the helpless villagers and take their last coins." << endl;
            cout << "All you receive in return is their curse." << endl;

            【function: changeKindness(player, -3)】
            【function: changeGold(player, +5)】
        }
        else if (choice == 2) {
            cout << "You feel sorry for them and give them some of your own gold." << endl;
            cout << "You hope they can survive." << endl;

            【function: changeKindness(player, +2)】
            【function: changeGold(player, -5)】
        }
    }


//event 5      
    else if (eventId == 5) {
        runJudgmentEvent(player);
    }

        
//event 6
    else if (eventId == 6) {
        runMerchantEvent(player);
    }

        
//event 7
    else if (eventId == 7) {

        cout << "Adventurer's Remains" << endl;
        cout << "You discover the crushed remains of an adventurer." << endl;
        cout << "There may still be something useful among the remains." << endl;

        cout << "1. Search the remains" << endl;
        cout << "2. Bury the body" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            int r1 = rand() % 4;

            if (r1 == 0) {
                cout << "A lot of gold!" << endl;
                【function: changeGold(player, +5)】
            }
            else if (r1 == 1) {
                cout << "Some gold!" << endl;
                【function: changeGold(player, +3)】
            }
            else if (r1 == 2) {
                cout << "A little gold!" << endl;
                【function: changeGold(player, +1)】
            }
            else {
                cout << "You found nothing." << endl;
            }

            int r2 = rand() % 2;

            if (r2 == 0) {
                cout << "The rotten corpse carries a disease. You are infected!" << endl;
                【function: changeMaxHP(player, -1)】
            }
            else {
                cout << "Nothing else happens." << endl;
            }
        }
        else if (choice == 2) {
            cout << "You spend some time digging a deep hole and bury the remains." << endl;

            【function: changeKindness(player, +1)】
        }
    }

//event 8
    else if (eventId == 8) {

        cout << "Forest Tiger" << endl;
        cout << "You hear that a fierce tiger lives deep in the forest." << endl;
        cout << "Many adventurers and villagers nearby have already died to it." << endl;

        cout << "1. Eliminate the beast" << endl;
        cout << "2. Avoid it" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You decide to hunt the tiger." << endl;

            【function: enemy = createEnemy(tiger_id)】
            【function: startBattle(player, enemy)】
        }
        else if (choice == 2) {
            cout << "Only a fool would challenge the king of the forest. You choose to go around it." << endl;

            int r = rand() % 100;

            if (r < 25) {
                cout << "You safely avoid the tiger." << endl;
            }
            else {
                cout << "The longer path is rough and dangerous." << endl;
                cout << "You fall badly and even tear your money bag on the bushes." << endl;

                【function: damagePlayer(player, 3)】
                【function: changeGold(player, -3)】
            }
        }
    }


        // ========================
    // Event 9: Senior Adventurer
    // ========================
    else if (eventId == 9) {

        cout << "Senior Adventurer" << endl;
        cout << "You meet a senior adventurer and decide to learn from them." << endl;

        cout << "1. Balance of attack and defense" << endl;
        cout << "2. Offense is the best defense" << endl;
        cout << "3. Defense is the best offense" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You learn a balanced fighting style." << endl;

            【function: changeAttack(player, +1)】
            【function: changeDefense(player, +1)】
        }
        else if (choice == 2) {
            cout << "You focus entirely on offense." << endl;

            【function: changeAttack(player, +3)】
            【function: changeDefense(player, -1)】
        }
        else if (choice == 3) {
            cout << "You focus entirely on defense." << endl;

            【function: changeDefense(player, +3)】
            【function: changeAttack(player, -1)】
        }
    }


        
// event 10
    else if (eventId == 10) {

        cout << "Backstab!" << endl;
        cout << "The forest is pitch dark at night." << endl;
        cout << "Before you can react, someone stabs you from behind!" << endl;

        【function: damagePlayer(player, 2)】

        cout << "You are hurt and immediately enter battle." << endl;

        【function: enemy = createEnemy(thief_id)】
        【function: startBattle(player, enemy)】
    }


//event 11
    else if (eventId == 11) {
       runGamblingEvent(player);
   }

        
// event 12
        
    else if (eventId == 12) {
        cout << "Hunting" << endl;
        cout << "An old hunter living in the forest invites you to go hunting with him." << endl;
        cout << "1. Small prey" << endl;
        cout << "2. Medium prey" << endl;
        cout << "3. Large prey" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You decide to hunt small prey." << endl;

           【function: enemy = createEnemy(rabbit_id)】
           【function: startBattle(player, enemy)】
        }
        else if (choice == 2) {
            cout << "You decide to hunt medium prey." << endl;

           【function: enemy = createEnemy(dog_id)】
           【function: startBattle(player, enemy)】
        }
        else if (choice == 3) {
            cout << "You decide to hunt large prey." << endl;

           【function: enemy = createEnemy(bear_id)】
           【function: startBattle(player, enemy)】
        }
    }


}
