#include <iostream>
using namespace std;

void runForestEvent(int eventId, Player &player) {

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


    else if (eventId == 2) {

        cout << "Blessing of the God of Battle" << endl;
        cout << "After wandering for a while, you discover a statue of the God of Battle." << endl;

        cout << "1. Pray sincerely" << endl;
        cout << "2. Reject the gods" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You kneel and pray for strength to defeat your enemies and take revenge." << endl;
            cout << "The God of Battle admires your courage and offers power in exchange for gold." << endl;

            【function: changeGold(player, -20)】
            【function: changeAttack(player, +1)】
            【function: changeDefense(player, +1)】
        }
        else if (choice == 2) {
            cout << "You believe gods are just illusions. Only your own strength matters." << endl;
            cout << "Nothing happens." << endl;
        }
    }

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


      
    else if (eventId == 5) {

        cout << "Judgment of Good and Evil" << endl;
        cout << "A statue of the God of Good and Evil stands in the middle of the road." << endl;
        cout << "Every traveler must accept its judgment." << endl;

        int kindness = 【function: getKindness(player)】;

        if (kindness >= 5) {
            cout << "Your kindness deserves a reward!" << endl;

            【function: changeMaxHP(player, +5)】
            【function: changeAttack(player, +1)】
            【function: changeDefense(player, +1)】
        }
        else if (kindness > 0 && kindness < 5) {
            cout << "Your kindness is worth encouraging!" << endl;

            【function: changeMaxHP(player, +3)】
        }
        else if (kindness < 0 && kindness > -5) {
            cout << "This is a warning!" << endl;

            int r = rand() % 2;

            if (r == 0) {
                cout << "You lost 1 Attack." << endl;
                【function: changeAttack(player, -1)】
            }
            else {
                cout << "You lost 1 Defense." << endl;
                【function: changeDefense(player, -1)】
            }
        }
        else if (kindness <= -5) {
            cout << "Your sins are unforgivable. Judgment must be carried out!" << endl;

            【function: changeMaxHP(player, -5)】
        }
        else {
            cout << "Nothing happens." << endl;
        }
    }


    else if (eventId == 6) {

        cout << "Wandering Merchant" << endl;
        cout << "A wandering merchant offers many goods for sale." << endl;
        cout << "Use your gold to make a choice." << endl;

        cout << "1. Buy a weapon" << endl;
        cout << "2. Buy an armor" << endl;
        cout << "3. Rob the merchant" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Choose your weapon:" << endl;
            cout << "1. Cheap Weapon (-5 gold, +1 Attack)" << endl;
            cout << "2. Fine Weapon (-15 gold, +2 Attack)" << endl;
            cout << "3. Top Weapon (-25 gold, +3 Attack)" << endl;

            int subChoice;
            cin >> subChoice;

            if (subChoice == 1) {
                【function: changeGold(player, -5)】
                【function: changeAttack(player, +1)】
                cout << "You bought a cheap weapon." << endl;
            }
            else if (subChoice == 2) {
                【function: changeGold(player, -15)】
                【function: changeAttack(player, +2)】
                cout << "You bought a fine weapon." << endl;
            }
            else if (subChoice == 3) {
                【function: changeGold(player, -25)】
                【function: changeAttack(player, +3)】
                cout << "You bought a top weapon." << endl;
            }
        }
        else if (choice == 2) {
            cout << "Choose your armor:" << endl;
            cout << "1. Cheap Armor (-5 gold, +1 Defense)" << endl;
            cout << "2. Fine Armor (-15 gold, +2 Defense)" << endl;
            cout << "3. Top Armor (-25 gold, +3 Defense)" << endl;

            int subChoice;
            cin >> subChoice;

            if (subChoice == 1) {
                【function: changeGold(player, -5)】
                【function: changeDefense(player, +1)】
                cout << "You bought a cheap armor." << endl;
            }
            else if (subChoice == 2) {
                【function: changeGold(player, -15)】
                【function: changeDefense(player, +2)】
                cout << "You bought a fine armor." << endl;
            }
            else if (subChoice == 3) {
                【function: changeGold(player, -25)】
                【function: changeDefense(player, +3)】
                cout << "You bought a top armor." << endl;
            }
        }
        else if (choice == 3) {
            cout << "You decide to rob the merchant!" << endl;

            【function: enemy = createEnemy(merchant_id)】
            【function: startBattle(player, enemy)】
        }
    }


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

  
}
