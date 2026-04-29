// =========================================================================================
//  __  __  ____  _    _ _   _ _______       _____ _   _    _______      ________ _   _ _______ _____ 
// |  \/  |/ __ \| |  | | \ | |__   __|/\   |_   _| \ | |  |  ____\ \    / /  ____| \ | |__   __/ ____|
// | \  / | |  | | |  | |  \| |  | |  /  \    | | |  \| |  | |__   \ \  / /| |__  |  \| |  | | | (___  
// | |\/| | |  | | |  | | . ` |  | | / /\ \   | | | . ` |  |  __|   \ \/ / |  __| | . ` |  | |  \___ \ 
// | |  | | |__| | |__| | |\  |  | |/ ____ \ _| |_| |\  |  | |____   \  /  | |____| |\  |  | |  ____) |
// |_|  |_|\____/ \____/|_| \_|  |_/_/    \_\_____|_| \_|  |______|   \/   |______|_| \_|  |_| |_____/ 
//                                                                                                      
// =========================================================================================
// Project Name:        HKU COMP2113 Group Project - Text-based RPG Game
// Module:              Chapter 2 - The Mountain Progression System
// File Name:           MountainEvents.cpp 
// Primary Author:      yuzhenxiang6-dotcom (Member A)
// Co-Authors:          Team Members
// 
// Description:         
// This module contains the exhaustive logic, narrative routing, and state manipulation 
// for the "Mountain" chapter. The events are generated via an RNG seed provided by 
// the EventManager and handled here via a localized event router.
//
// Developer Notes:
// - All syntax errors from the previous integration phase (e.g., dangling else-ifs) 
//   have been safely resolved in this build.
// - The typo for the Food Cart event (ID: 55 -> 5) has been corrected to ensure 
//   event accessibility.
// - Narrative balancing: Mountain events are designed to be high-attrition, testing 
//   the player's resource management (HP, Gold) before the final Boss.
//
// =========================================================================================
// CHANGELOG / VERSION HISTORY:
// v1.0.0 - Initial layout and raw logic structure.
// v1.0.1 - Minor text fixes.
// v1.1.0 - Fixed critical 'else if' routing bug at event 1.
// v1.1.1 - Hotfix: Food cart ID typo corrected.
// v2.0.0 - Massive documentation update. Added comprehensive Lore and Mechanics 
//          breakdowns for every single event to improve maintainability.
// =========================================================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include "../player/player.h"
#include "../enemy/enemy.h"
#include "../event/common.h"
// -----------------------------------------------------------------------------------------
// EXTERNAL DEPENDENCIES (Handled by other team members)
// -----------------------------------------------------------------------------------------
// #include "Player.h"    // Provides: Player object, changeGold, changeAttack, changeDefense
// #include "Enemy.h"     // Provides: Enemy object, createEnemy
// #include "Combat.h"    // Provides: startBattle, damagePlayer
// -----------------------------------------------------------------------------------------

using namespace std;
bool startBattle(Player &player, Enemy &enemy);

// =========================================================================================
// FUNCTION: runMountainEvent
// =========================================================================================
// PURPOSE:
// Acts as a master switchboard. It takes the integer ID rolled by the random number 
// generator and executes the corresponding narrative sequence, choices, and stat changes.
//
// PARAMETERS:
// - eventId (int): An integer ranging from 1 to 14 indicating which event to fire.
// - player (Player &): A pass-by-reference object of the main player, allowing this 
//                      function to directly mutate their HP, Gold, and stats.
// =========================================================================================
void runMountainEvent(int eventId, Player &player, bool isHard) {
    
    // =====================================================================================
    // EVENT 1: BATTLE GOD'S BLESSING
    // =====================================================================================
    // NARRATIVE LORE:
    // High in the frigid peaks, the player stumbles upon an ancient, weather-beaten shrine.
    // It is dedicated to the God of Battle. 
    //
    // GAMEPLAY MECHANICS:
    // This is an externalized event. The routing logic simply calls the helper function
    // 'runBattleGodBlessingEvent'.
    // 
    // DEBUG NOTE: 
    // Fixed a previous syntax error here where this block started with 'else if' instead of 'if'.
    // =====================================================================================
    if (eventId == 1) {
        // Execute external function for Event 1
        runBattleGodBlessingEvent(player);
    }

    // =====================================================================================
    // EVENT 2: THE JUDGMENT
    // =====================================================================================
    // NARRATIVE LORE:
    // The player's past actions (their Kindness / Alignment stat) catch up to them.
    // A mysterious, ethereal force evaluates their worthiness to proceed.
    //
    // GAMEPLAY MECHANICS:
    // Relies on the 'runJudgmentEvent' helper. Outcomes vary drastically based on 
    // the player's accumulated hidden stats.
    // =====================================================================================
    else if (eventId == 2) {
        // Execute external function for Event 2
        runJudgmentEvent(player);
    }

    // =====================================================================================
    // EVENT 3: THE WANDERING MERCHANT
    // =====================================================================================
    // NARRATIVE LORE:
    // Despite the harsh environment, capitalism finds a way. A heavily bundled merchant
    // offers rare items in exchange for the player's hard-earned gold.
    //
    // GAMEPLAY MECHANICS:
    // Calls 'runMerchantEvent'. Acts as a mid-chapter gold sink to prevent economy inflation.
    // =====================================================================================
    else if (eventId == 3) {
        // Execute external function for Event 3
        runMerchantEvent(player);
    }

    // =====================================================================================
    // EVENT 4: MOUNTAIN GAMBLING
    // =====================================================================================
    // NARRATIVE LORE:
    // A shady figure huddled around a campfire offers to play a game of chance.
    // The player can risk their gold for a chance to double it.
    //
    // GAMEPLAY MECHANICS:
    // Calls 'runGamblingEvent'. Pure RNG check.
    // =====================================================================================
    else if (eventId == 4) {
       // Execute external function for Event 4
       runGamblingEvent(player);
    }

    // =====================================================================================
    // EVENT 5: THE STRANGE FOOD CART
    // =====================================================================================
    // NARRATIVE LORE:
    // Bizarrely, a fully stocked food cart sits on a snowy ridge. The food smells amazing,
    // but its origins are highly suspicious.
    //
    // GAMEPLAY MECHANICS:
    // Calls 'runFoodCartEvent'. 
    // 
    // DEBUG NOTE:
    // Fixed typo. Originally set to '55', which made this event completely unreachable.
    // =====================================================================================
    else if (eventId == 5) {
       // Execute external function for Event 5
       runFoodCartEvent(player);
    }

    // =====================================================================================
    // EVENT 6: REVENGE GOD'S BLESSING
    // =====================================================================================
    // NARRATIVE LORE:
    // A darker counterpart to Event 1. This shrine offers immense offensive power, but
    // the sacrifices required are steep and permanent.
    //
    // GAMEPLAY MECHANICS:
    // Calls 'runRevengeGodBlessingEvent'.
    // =====================================================================================
    else if (eventId == 6) {
       // Execute external function for Event 6
       runRevengeGodBlessingEvent(player);
    }  

    // =====================================================================================
    // EVENT 7: THE DEADLY LANDSLIDE (INTERACTIVE EVENT)
    // =====================================================================================
    // NARRATIVE LORE:
    // The player is caught in a sudden, catastrophic natural disaster. Thousands of tons
    // of rock and snow begin to slide down the mountain face. The player has less than 
    // a second to make a life-or-death decision.
    //
    // GAMEPLAY MECHANICS:
    // - Choice 1 (Flee): Guaranteed survival, but the player drops their gear. 
    //   Penalty: -3 Attack, -3 Defense, -10 Gold.
    // - Choice 2 (Brace): The player risks taking the hit. 
    //   Penalty: Random HP loss between 1 and 10. No stat penalties.
    // =====================================================================================
    else if (eventId == 7) {

        // Display event title
        cout << "Landslide!" << endl;

        // Display player choices
        cout << "1. Drop everything and run for your life" << endl;
        cout << "2. Leave it to fate" << endl;

        // Variable to hold the user's input
        int choice;
        
        // Read input from the console
        cin >> choice;

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
        // Process Invalid Input
        else {
            // Failsafe for incorrect console input
            cout << "Invalid choice. Nothing happens." << endl;
        }
    }

    // =====================================================================================
    // EVENT 8: GRIFFIN AMBUSH (COMBAT EVENT)
    // =====================================================================================
    // NARRATIVE LORE:
    // The player has entered the hunting grounds of the apex predator of the mountains.
    // A massive Griffin with razor-sharp talons initiates an unavoidable ambush.
    //
    // GAMEPLAY MECHANICS:
    // Immediately constructs an Enemy object using the predefined 'griffin_id', and passes 
    // control to the Combat module's 'startBattle' loop.
    // =====================================================================================
    else if (eventId == 8) {

        // Display narrative text for the ambush
        cout << "Griffon Attack!" << endl;
        cout << "A griffon suddenly swoops down from the sky!" << endl;

        // Instantiate the Griffin enemy
        Enemy enemy = createEnemy(EnemyType::Griffon, isHard);   
        
        // Trigger the combat sequence (Execution jumps to Combat.cpp)
        startBattle(player, enemy);              
    }

    // =====================================================================================
    // EVENT 9: BLESSING OF THE MOUNTAIN GOD (INTERACTIVE EVENT)
    // =====================================================================================
    // NARRATIVE LORE:
    // The Mountain God is an arrogant and greedy deity. Unlike the God of Battle, this 
    // entity demands monetary tribute in exchange for protection from the elements.
    //
    // GAMEPLAY MECHANICS:
    // - Choice 1 (Pay Tribute): Costs 20 Gold, rewards +3 Defense.
    // - Choice 2 (Reject): Offends the deity. Player is cursed with -1 Attack.
    // =====================================================================================
    else if (eventId == 9) {

        // Display narrative text and lore
        cout << "Blessing of the God of the Mountain" << endl;
        cout << "You arrive at the statue of the God of the Mountain." << endl;
        cout << "Perhaps you need the god's blessing to overcome the hardships ahead." << endl;
        cout << "Like the God of Battle, the God of the Mountain can also be 'persuaded' with gold." << endl;

        // Display player choices
        cout << "1. Kneel and pray sincerely" << endl;
        cout << "2. Reject the gods" << endl;

        // Variable to hold the user's input
        int choice;
        
        // Read input from the console
        cin >> choice;

        // Process Choice 1: Submission and payment
        if (choice == 1) {
            
            // Output narrative text
            cout << "You kneel before the statue and offer your gold." << endl;

            // Apply transaction
            changePlayerGold(player, -20);      // Deduct funds
            changePlayerDefense(player, +3);    // Grant defensive blessing
            
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
        // Process Invalid Input
        else {
            // Failsafe for incorrect console input
            cout << "Invalid choice. Nothing happens." << endl;
        }
    }

    // =====================================================================================
    // EVENT 10: THE MASTER HERMIT
    // =====================================================================================
    // NARRATIVE LORE:
    // Hidden in a secluded cave, a legendary martial arts master spends his final years.
    // If the player proves worthy, they might learn a secret technique.
    //
    // GAMEPLAY MECHANICS:
    // Calls external function 'runMasterHermitEvent'.
    // =====================================================================================
    else if (eventId == 10){
        // Execute external function for Event 10
        runMasterHermitEvent(player);
    }

    // =====================================================================================
    // EVENT 11: BANDIT INVASION (MORALITY & COMBAT EVENT)
    // =====================================================================================
    // NARRATIVE LORE:
    // The player encounters a group of bandits harassing weary travelers. The player 
    // must decide whether to intervene (risking their life) or turn a blind eye.
    //
    // GAMEPLAY MECHANICS:
    // - Choice 1 (Ignore): Safely bypasses combat, but the player suffers a -3 Kindness 
    //   penalty for their cowardice.
    // - Choice 2 (Fight): Preserves Kindness and initiates combat with a Bandit enemy.
    // =====================================================================================
    else if (eventId == 11) {

        // Display narrative text
        cout << "Bandit Invasion" << endl;
        cout << "A group of bandits are terrorizing this area." << endl;
        cout << "Do you have the courage to stop them?" << endl;

        // Display player choices
        cout << "1. Stay cowardly" << endl;
        cout << "2. Fight for justice" << endl;

        // Variable to hold the user's input
        int choice;
        
        // Read input from the console
        cin >> choice;

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
        // Process Invalid Input
        else {
            // Failsafe for incorrect console input
            cout << "Invalid choice. Nothing happens." << endl;
        }
    }

    // =====================================================================================
    // EVENT 12: THE FIRE SPIRIT (INTERACTIVE COMBAT/TRADE EVENT)
    // =====================================================================================
    // NARRATIVE LORE:
    // Approaching a volcanic vent, the player encounters a sentient elemental made of magma.
    // The spirit is not immediately hostile, presenting an opportunity for trade or violence.
    //
    // GAMEPLAY MECHANICS:
    // - Choice 1 (Attack): Player loses 1 Kindness for unprovoked aggression and fights.
    // - Choice 2 (Trade): Player pays 10 Gold to gain +1 Kindness and +1 Attack.
    // =====================================================================================
    else if (eventId == 12) {

        // Display narrative text
        cout << "Fire Spirit" << endl;
        cout << "This is a volcano. The burning lava has given birth to a Fire Spirit." << endl;

        // Display player choices
        cout << "1. Hunt the Fire Spirit" << endl;
        cout << "2. Trade fairly" << endl;

        // Variable to hold the user's input
        int choice;
        
        // Read input from the console
        cin >> choice;

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
            
            // Output narrative text
            cout << "You trade gold for the spirit's flame." << endl;

            // Apply transaction and stat boosts
            changePlayerGold(player, -10);     // Deduct funds
            changePlayerKindness(player, +1);  // Increase morality
            changePlayerAttack(player, +1);    // Increase offensive power
            
        }
        // Process Invalid Input
        else {
            // Failsafe for incorrect console input
            cout << "Invalid choice. Nothing happens." << endl;
        }
    }

    // =====================================================================================
    // EVENT 13: THE DRAGON EGG (HIGH-STAKES RNG EVENT)
    // =====================================================================================
    // NARRATIVE LORE:
    // The ultimate temptation. A slumbering ancient dragon guards its unhatched egg. 
    // The egg is worth a fortune, but waking the mother means almost certain death.
    //
    // GAMEPLAY MECHANICS:
    // - Choice 1 (Leave): Safe exit. Nothing changes.
    // - Choice 2 (Steal): -1 Kindness. Rolls a d100. 
    //   - Success (0-24): Player gains 50 Gold.
    //   - Failure (25-99): Player fights a Dragon Boss.
    // =====================================================================================
    else if (eventId == 13) {

        // Display narrative text
        cout << "A Dragon Egg!" << endl;
        cout << "At the mountain peak, you discover a sleeping dragon and a dragon egg." << endl;

        // Display player choices
        cout << "1. Walk away quietly" << endl;
        cout << "2. Steal the egg" << endl;

        // Variable to hold the user's input
        int choice;
        
        // Read input from the console
        cin >> choice;

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
        // Process Invalid Input
        else {
            // Failsafe for incorrect console input
            cout << "Invalid choice. Nothing happens." << endl;
        }
    }

    // =====================================================================================
    // EVENT 14: CHAPTER BOSS - THE STONE GIANT
    // =====================================================================================
    // NARRATIVE LORE:
    // The culmination of the Mountain chapter. The path to the Abyss is blocked by a 
    // colossal construct of animated rock, tasked by the Demon King to halt any intruders.
    //
    // GAMEPLAY MECHANICS:
    // This is a mandatory boss fight. The player cannot flee or negotiate. Winning 
    // is required to set the progression flag for the next chapter.
    // =====================================================================================
    else if (eventId == 14) {

        // Display epic narrative text for the boss encounter
        cout << "=====================================" << endl;
        cout << "             STONE GIANT             " << endl;
        cout << "=====================================" << endl;
        cout << "To leave the mountains and descend into the abyss," << endl;
        cout << "you must defeat the guardian of the Demon King — the Stone Giant." << endl;
        cout << "Prepare for battle!" << endl;
        cout << "=====================================" << endl;

        // Instantiate the Chapter Boss
        Enemy enemy = createBoss(2,isHard);   
        
        // Trigger the boss battle and capture the boolean result (Win/Loss)
        bool win = startBattle(player, enemy);       

        // Evaluate the result of the battle
        if (win) {
            
            // Player won the boss fight
            cout << "=====================================" << endl;
            cout << "You defeated the Stone Giant!" << endl;
            cout << "The path to the abyss is now open." << endl;
            cout << "=====================================" << endl;
            
            // NOTE FOR INTEGRATION: 
            // The GameManager should detect this state and update currentChapter.
            
        } else {
            
            // Player lost the boss fight
            cout << "=====================================" << endl;
            cout << "You were defeated by the Stone Giant..." << endl;
            cout << "Your journey ends here in the freezing mountains." << endl;
            cout << "=====================================" << endl;
            
            // NOTE FOR INTEGRATION:
            // The GameManager will detect player HP <= 0 and trigger the Game Over sequence.
            
        }
    }
}