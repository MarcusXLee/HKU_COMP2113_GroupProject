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

        changeGold(player, -20);//F
        changeAttack(player, +1);//F
        changeDefense(player, +1);//F
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

        changeMaxHP(player, +5);//F
        changeAttack(player, +1);//F
        changeDefense(player, +1);//F
    }
    else if (kindness > 0 && kindness < 5) {
        cout << "Your kindness is worth encouraging!" << endl;

        changeMaxHP(player, +3);//F
    }
    else if (kindness < 0 && kindness > -5) {
        cout << "This is a warning!" << endl;

        int r = rand() % 2;

        if (r == 0) {
            cout << "You lost 1 Attack." << endl;
            changeAttack(player, -1);//F
        }
        else {
            cout << "You lost 1 Defense." << endl;
            changeDefense(player, -1);//F
        }
    }
    else if (kindness <= -5) {
        cout << "Your sins are unforgivable. Judgment must be carried out!" << endl;

        changeMaxHP(player, -5);//F
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
            changeGold(player, -5);//F
            changeAttack(player, +1);//F
            cout << "You bought a cheap weapon." << endl;
        }
        else if (subChoice == 2) {
            changeGold(player, -15);//F
            changeAttack(player, +2);//F
            cout << "You bought a fine weapon." << endl;
        }
        else if (subChoice == 3) {
            changeGold(player, -25);//F
            changeAttack(player, +3);//F
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
            changeGold(player, -5);//F
            changeDefense(player, +1);//F
            cout << "You bought a cheap armor." << endl;
        }
        else if (subChoice == 2) {
            changeGold(player, -15);//F
            changeDefense(player, +2);//F
            cout << "You bought a fine armor." << endl;
        }
        else if (subChoice == 3) {
            changeGold(player, -25);//F
            changeDefense(player, +3);//F
            cout << "You bought a top armor." << endl;
        }
    }
    else if (choice == 3) {
        cout << "You decide to rob the merchant!" << endl;

        Enemy enemy = createEnemy(merchant);//F and need modify
        startBattle(player, enemy);
    }
}



//Gambling House
void runGamblingEvent(Player &player) {

    cout << "Gambling House" << endl;
    cout << "You accidentally enter a gambling house." << endl;
    cout << "Do you want to take a gamble?" << endl;

    cout << "1. Small bet" << endl;
    cout << "2. Big bet" << endl;
    cout << "3. All in" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        int r = rand() % 100;

        if (r < 25) {
            cout << "You lost 1 gold." << endl;
            changeGold(player, -1);//F
        }
        else if (r < 75) {
            cout << "Nothing happens." << endl;
        }
        else {
            cout << "You won 1 gold!" << endl;
            changeGold(player, +1);//F
        }
    }

    else if (choice == 2) {
        int r = rand() % 100;

        if (r < 25) {
            cout << "You lost 5 gold." << endl;
            changeGold(player, -5);//F
        }
        else if (r < 75) {
            cout << "Nothing happens." << endl;
        }
        else {
            cout << "You won 5 gold!" << endl;
            changeGold(player, +5);//F
        }
    }

    else if (choice == 3) {
        int r = rand() % 100;

        if (r < 25) {
            cout << "You lost all your gold." << endl;
            loseAllGold(player);//F
        }
        else if (r < 75) {
            cout << "Nothing happens." << endl;
        }
        else {
            cout << "You doubled your gold!" << endl;
            doubleGold(player);//F
        }
    }   
}
    
// Food Cart
void runFoodCartEvent(Player &player) {

    cout << "Food Cart" << endl;
    cout << "The food cart arrives. Spend your gold to enjoy some perfect meals!" << endl;

    cout << "1. Have a snack (-2 gold, restore 10% HP)" << endl;
    cout << "2. Have a full meal (-5 gold, restore 30% HP)" << endl;
    cout << "3. Try magical food (-15 gold)" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You enjoy a small snack." << endl;

        changeGold(player, -2);//F
        healPlayer(player, getMaxHP(player) * 0.1);//F
    }
    else if (choice == 2) {
        cout << "You enjoy a full meal." << endl;

        changeGold(player, -5);//function
        healPlayer(player, getMaxHP(player) * 0.3);//function
    }
    else if (choice == 3) {
        cout << "You try the magical food..." << endl;

        changeGold(player, -15);//F

        int r = rand() % 2;

        if (r == 0) {
            cout << "You lost some Attack but gained great Defense!" << endl;

            int loss = rand() % 4 + 1;  // 1~4

            changeAttack(player, -loss);//function
            changeDefense(player, 2 * loss);//function
        }
        else {
            cout << "You lost some Defense but gained great Attack!" << endl;

            int loss = rand() % 4 + 1;

             changeDefense(player, -loss);//function
             changeAttack(player, 2 * loss);//function
        }
    }
}


// Blessing of the God of Revenge
void runRevengeGodBlessingEvent(Player &player) {

    cout << "Blessing of the God of Revenge" << endl;
    cout << "Guided by the God of Revenge, you arrive before the statue." << endl;
    cout << "Your hatred toward the Demon King pleases the god." << endl;

    cout << "1. Rational revenge" << endl;
    cout << "2. Aggressive revenge" << endl;
    cout << "3. Mad revenge" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The God of Revenge is disappointed, but still grants you power." << endl;

        changeAttack(player, +1);//F
    }
    else if (choice == 2) {
        cout << "The god approves your determination and demands a price." << endl;

        damagePlayer(player, 5);//F
        changeAttack(player, +3);//F
    }
    else if (choice == 3) {
        cout << "The God of Revenge is finally satisfied." << endl;
        cout << "You give up everything for ultimate power." << endl;

        setHPToOne(player);//F
        changeAttack(player, -2);//F
        doubleAttack(player);//F
    }
}


