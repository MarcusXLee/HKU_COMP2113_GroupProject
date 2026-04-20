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

            changeGold(player, -5);//F
            changeKindness(player, +1);//F
        }
        else if (choice == 2) {
            cout << "You refuse to give up your gold and prepare to fight!" << endl;

            Enemy enemy = createEnemy(1);//F
            startBattle(player, enemy);//F
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

            healPlayer(player, getMaxHP(player) * 0.3);//F
        }
        else if (choice == 2) {
            cout << "You sneak into the blacksmith shop and steal a piece of equipment." << endl;

            changeKindness(player, -1);//F

            int r = rand() % 2;

            if (r == 0) {
                cout << "You gained +1 Attack." << endl;
                changeAttack(player, +1);//F
            } else {
                cout << "You gained +1 Defense." << endl;
                changeDefense(player, +1);//F
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

            changeKindness(player, -3);//F
            changeGold(player, +5);//F
        }
        else if (choice == 2) {
            cout << "You feel sorry for them and give them some of your own gold." << endl;
            cout << "You hope they can survive." << endl;

            changeKindness(player, +2);//F
            changeGold(player, -5);//F
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
                changeGold(player, +5);//F
            }
            else if (r1 == 1) {
                cout << "Some gold!" << endl;
                changeGold(player, +3);//F
            }
            else if (r1 == 2) {
                cout << "A little gold!" << endl;
                changeGold(player, +1);//F
            }
            else {
                cout << "You found nothing." << endl;
            }

            int r2 = rand() % 2;

            if (r2 == 0) {
                cout << "The rotten corpse carries a disease. You are infected!" << endl;
                changeMaxHP(player, -1);//F
            }
            else {
                cout << "Nothing else happens." << endl;
            }
        }
        else if (choice == 2) {
            cout << "You spend some time digging a deep hole and bury the remains." << endl;

            changeKindness(player, +1);//F
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

            Enemy enemy = createEnemy(tiger_id);//F and need modify
            startBattle(player, enemy);//F
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

                damagePlayer(player, 3);//F
                changeGold(player, -3);//F
            }
        }
    }

        
    // event 9
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

            changeAttack(player, +1);//F
            changeDefense(player, +1);//F
        }
        else if (choice == 2) {
            cout << "You focus entirely on offense." << endl;

            changeAttack(player, +3);//F
            changeDefense(player, -1);//F
        }
        else if (choice == 3) {
            cout << "You focus entirely on defense." << endl;

            changeDefense(player, +3);//F
            changeAttack(player, -1);//F
        }
    }


        
// event 10
    else if (eventId == 10) {

        cout << "Backstab!" << endl;
        cout << "The forest is pitch dark at night." << endl;
        cout << "Before you can react, someone stabs you from behind!" << endl;

        damagePlayer(player, 2);//F

        cout << "You are hurt and immediately enter battle." << endl;

        Enemy enemy = createEnemy(thief_id);//F and need modify
        startBattle(player, enemy);//F
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

            Enemy enemy = createEnemy(rabbit_id);//F and need modify
            startBattle(player, enemy);//F
        }
        else if (choice == 2) {
            cout << "You decide to hunt medium prey." << endl;

            enemy = createEnemy(dog_id);//F and need modify
            startBattle(player, enemy);//F
        }
        else if (choice == 3) {
            cout << "You decide to hunt large prey." << endl;

            Enemy enemy = createEnemy(bear_id);//F need modify
            startBattle(player, enemy);//F
        }
    }



// event 13
    else if (eventId == 13) {

        cout << "Magic Spring" << endl;
        cout << "You discover a small green spring in the forest." << endl;
        cout << "It seems to have magical power." << endl;

        cout << "1. Clean your wounds" << endl;
        cout << "2. Drink it" << endl;
        cout << "3. Collect and sell it" << endl;
        cout << "4. Purify your sins" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You clean your wounds and recover some health." << endl;

            healPlayer(player, 5);//F
        }
        else if (choice == 2) {
            cout << "You drink the water and feel stronger." << endl;

            changeAttack(player, +1);//F
            changeDefense(player, +1);//F
            changeMaxHP(player, +1);//F
        }
        else if (choice == 3) {
            cout << "You collect the water and sell it for gold." << endl;

            changeGold(player, +10);//F
        }
        else if (choice == 4) {
            cout << "You try to purify your sins." << endl;

            int kindness = getKindness(player);

            if (kindness < 0) {
                cout << "Your sins are cleansed." << endl;

                setKindness(player, 0);
            } else {
                cout << "You have no sins to cleanse." << endl;
            }
        }
    }


        
// event 14
    else if (eventId == 14) {

        cout << "Guardian of the Forest" << endl;
        cout << "To leave the forest and move forward," << endl;
        cout << "you must defeat the guardian of the forest — the Treant." << endl;

        cout << "Prepare for battle!" << endl;

        Enemy enemy = createBoss(forest_boss_id);//F and need modify
        startBattle(player, enemy);//F
    }

//event 15
    else if (eventId == 15) {
       runFoodCartEvent(player);
   }

//event 16
    else if (eventId == 16) {
       runRevengeGodBlessingEvent(player);
    }    
}
