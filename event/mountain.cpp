#include <iostream>
#include <string>
#include <cstdlib>
#include "../player/player.h"
#include "../enemy/enemy.h"
#include "../event/common.h"
#include "../combat_system/combat.h"

using namespace std;

void runMountainEvent(int eventId, Player &player, bool isHard) {
    if (eventId == 1) {
        // Execute external function for Event 1
        runBattleGodBlessingEvent(player);
    }
    else if (eventId == 2) {
        // Execute external function for Event 2
        runJudgmentEvent(player);
    }
    else if (eventId == 3) {
        // Execute external function for Event 3
        runMerchantEvent(player,isHard);
    }
    else if (eventId == 4) {
       // Execute external function for Event 4
       runGamblingEvent(player);
    }
    else if (eventId == 5) {
       // Execute external function for Event 5
       runFoodCartEvent(player);
    }
    else if (eventId == 6) {
       // Execute external function for Event 6
       runRevengeGodBlessingEvent(player);
    }  
    else if (eventId == 7) {

        // Display event title
        cout << "Landslide!" << endl;

        // Display player choices
        cout << "1. Drop everything and run for your life" << endl;
        cout << "2. Leave it to fate" << endl;

       int choice = getValidEventChoice(1, 2);

        // Process Choice 1: The coward's route
        if (choice == 1) {
            
            // Output narrative text
            cout << "You throw away your equipment and escape in panic." << endl;

            // Apply severe stat penalties
            changePlayerAttack(player, -3);   // Decrease attack power
            changePlayerDefense(player, -3);  // Decrease defense power
            changePlayerGold(player, -10);    // Decrease wallet balance
        }
        // Process Choice 2: The brave/reckless route
        else if (choice == 2) {
            
            // Output narrative text
            cout << "You decide to leave it to fate." << endl;

            // Calculate random damage (RNG from 1 to 10)
            int damage = rand() % 10 + 1;
            
            // Apply damage to the player's health pool
            damagePlayer(player, damage);   

            // Inform the player of the outcome
            cout << "You lost " << damage << " HP." << endl;
            
        }
    }
    else if (eventId == 8) {

        // Display narrative text for the ambush
        cout << "Griffon Attack!" << endl;
        cout << "A griffon suddenly swoops down from the sky!" << endl;

        // Instantiate the Griffin enemy
        Enemy enemy = createEnemy(EnemyType::Griffon, isHard);   
        
        // Trigger the combat sequence (Execution jumps to Combat.cpp)
        startBattle(player, enemy);              
    }
    else if (eventId == 9) {

        // Display narrative text and lore
        cout << "Blessing of the God of the Mountain" << endl;
        cout << "You arrive at the statue of the God of the Mountain." << endl;
        cout << "Perhaps you need the god's blessing to overcome the hardships ahead." << endl;
        cout << "Like the God of Battle, the God of the Mountain can also be 'persuaded' with gold." << endl;
        cout << "💰 [Your Gold: " << getPlayerGold(player) << "]" << endl;
        // Display player choices
        cout << "1. Kneel and pray sincerely" << endl;
        cout << "2. Reject the gods" << endl;
        int choice = getValidEventChoice(1, 2);

        // Process Choice 1: Submission and payment
        if (choice == 1) {
            if (getPlayerGold(player) < 20) {
                cout << "The God of the Mountain rejects your empty pockets. You need 20 gold. Nothing happens." << endl;
            }
            else{
                // Output narrative text
                cout << "You kneel before the statue and offer your gold." << endl;
                changePlayerGold(player, -20);      // Deduct funds
                changePlayerDefense(player, +3);    // Grant defensive blessing
            }
            
        }
        // Process Choice 2: Defiance and curse
        else if (choice == 2) {
            // Output narrative text
            cout << "You believe gods are only illusions." << endl;
            cout << "Unlike the God of Battle, the God of the Mountain is not merciful." << endl;
            cout << "You are cursed for your arrogance." << endl;
            // Apply curse penalty
            changePlayerAttack(player, -1);     // Reduce offensive power
            
        }
    }
    else if (eventId == 10){
        // Execute external function for Event 10
        runMasterHermitEvent(player);
    }
    else if (eventId == 11) {

        // Display narrative text
        cout << "Bandit Invasion" << endl;
        cout << "A group of bandits are terrorizing this area." << endl;
        cout << "Do you have the courage to stop them?" << endl;

        // Display player choices
        cout << "1. Stay cowardly" << endl;
        cout << "2. Fight for justice" << endl;

        int choice = getValidEventChoice(1, 2);

        // Process Choice 1: Avoid combat, lose morality
        if (choice == 1) {
            
            // Output narrative text
            cout << "You decide not to get involved." << endl;

            // Apply morality penalty
            changePlayerKindness(player, -3);   
            
        }
        // Process Choice 2: Engage in combat
        else if (choice == 2) {
            
            // Output narrative text
            cout << "You decide to stand up against the bandits!" << endl;

            // Instantiate Bandit enemy
            Enemy enemy = createEnemy(EnemyType::Bandit, isHard);   
            
            // Trigger combat sequence
            startBattle(player, enemy);             
            
        }
    }
    else if (eventId == 12) {

        // Display narrative text
        cout << "Fire Spirit" << endl;
        cout << "This is a volcano. The burning lava has given birth to a Fire Spirit." << endl;
        cout << "💰 [Your Gold: " << getPlayerGold(player) << "]" << endl;
        // Display player choices
        cout << "1. Hunt the Fire Spirit" << endl;
        cout << "2. Trade fairly" << endl;
        cout << "3. Leave it" << endl;
        int choice = getValidEventChoice(1, 3);

        // Process Choice 1: Aggressive path
        if (choice == 1) {
            
            // Output narrative text
            cout << "You attack the Fire Spirit." << endl;

            // Apply morality penalty for unprovoked attack
            changePlayerKindness(player, -1);   

            // Instantiate Fire Spirit enemy
            Enemy enemy = createEnemy(EnemyType::FireSprite, isHard);  
            
            // Trigger combat sequence
            startBattle(player, enemy);                 
            
        }
        // Process Choice 2: Peaceful path
        else if (choice == 2) {
            if (getPlayerGold(player) < 10) {
                cout << "The Fire Spirit notices your empty coin pouch and refuses to trade. Nothing happens." << endl;
            }
            else{
                // Output narrative text
                cout << "You trade gold for the spirit's flame." << endl;
                // Apply transaction and stat boosts
                changePlayerGold(player, -10);     // Deduct funds
                changePlayerKindness(player, +1);  // Increase morality
                changePlayerAttack(player, +1);    // Increase offensive power
            }
        }
        else if (choice==3)
        {
            cout << " You left the fire spirit with nothing happened." << endl;
        }
    }
    else if (eventId == 13) {

        // Display narrative text
        cout << "A Dragon Egg!" << endl;
        cout << "At the mountain peak, you discover a sleeping dragon and a dragon egg." << endl;

        // Display player choices
        cout << "1. Walk away quietly" << endl;
        cout << "2. Steal the egg" << endl;

        int choice = getValidEventChoice(1, 2);

        // Process Choice 1: The safe route
        if (choice == 1) {
            
            // Output narrative text
            cout << "Even though the egg is priceless, you dare not wake the dragon." << endl;
            cout << "Nothing happens." << endl;
            
        }
        // Process Choice 2: The greedy route
        else if (choice == 2) {
            
            // Output narrative text
            cout << "You attempt to steal the dragon egg..." << endl;

            // Apply morality penalty for theft
            changePlayerKindness(player, -1);   

            // Generate a random number between 0 and 99
            int r = rand() % 100;

            // Determine outcome: 25% chance of success
            if (r < 25) {
                
                // Success output
                cout << "You successfully stole the egg without waking the dragon!" << endl;
                
                // Massive gold reward
                changePlayerGold(player, +50);  
                
            }
            // Determine outcome: 75% chance of failure
            else {
                
                // Failure output
                cout << "You wake the dragon. You must face its wrath!" << endl;

                // Instantiate Dragon Boss enemy
                Enemy enemy = createEnemy(EnemyType::Dragon, isHard);   
                
                // Trigger deadly combat sequence
                startBattle(player, enemy);             
                
            }
        }
    }
    else if (eventId == 14) {
        cout << "Griffin Ambush!" << endl;
        cout << "Another wild griffin dives at you from the cliffs!" << endl;
        Enemy enemy = createEnemy(EnemyType::Griffon, isHard);
        startBattle(player, enemy);
    }
    else {
        runMerchantEvent(player,isHard); 
    }
}