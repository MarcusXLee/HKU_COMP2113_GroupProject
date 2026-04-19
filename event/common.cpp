#include <iostream>
#include <cstdlib>
using namespace std;

//Blessing of the God of Battle

void runBattleGodBlessingEvent(Player &player) {

    cout << "Blessing of the God of Battle" << endl;
    cout << "After wandering for a while, you discover a statue of the God of Battle." << endl;

    cout << "1. Pray sincerely" << endl;
    cout << "2. Reject the gods" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You kneel and pray for strength to defeat your enemies and avenge the Demon King." << endl;
        cout << "The God of Battle admires your courage and offers power in exchange for gold." << endl;

        【function: changeGold(player, -20)】
        【function: changeAttack(player, +1)】
        【function: changeDefense(player, +1)】
    }
    else if (choice == 2) {
        cout << "You believe the gods are only illusions." << endl;
        cout << "Only your own strength can lead you to revenge." << endl;
        cout << "Nothing happens." << endl;
    }
}


// Judgment of Good and Evil

void runJudgmentEvent(Player &player) {

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



// Wandering Merchant

void runMerchantEvent(Player &player) {

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


// Hunting

void runHuntingEvent(Player &player) {

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
