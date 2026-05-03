The Vengeful Adventurer ⚔️

Team Members(group 137)

Qu Cheng 3036403703

Zhang Yiwen 3036588890

Yu Zhenxiang 3036588553

LI Xinye 3036483832

Shi Xiang’er 3036397136

Application Description

"The Vengeful Adventurer" is a sophisticated text-based RPG developed in C++. The narrative follows a survivor seeking retribution against the Demon King across three distinct procedural chapters: The Forest, The Mountain, and The Abyss.
The project goes beyond a simple story by implementing a balanced combat engine, a persistent save/load system, and a "Karma" morality mechanic that dynamically scales the game's difficulty based on the player's ethical choices.
Features & Coding Requirements Mapping
This project strictly adheres to the five core coding elements specified in the course rubric:

1. Generation of Random Events

•	Feature Supported: Procedural Exploration & Replayability.
•	Implementation: Within GameManager::processChapter, we utilize rand() % 16 + 1 to generate seven random events per chapter. These events range from combat encounters and wandering merchants to moral dilemmas and gambling halls.

2. Data Structures for Storing Data

•	Feature Supported: Entity Management & Resource Handling.
•	Implementation:
o	We define struct Player and struct Enemy to encapsulate complex state data.
o	We utilize std::vector<std::string> in the FileIO and UIManager modules to store and manipulate text data read from external files.

3. Dynamic Memory Management

•	Feature Supported: Lifecycle Management of Boss Entities.
•	Implementation: In GameManager::triggerBoss(), we use the new keyword to dynamically allocate memory for Enemy boss objects on the heap. We ensure memory safety by calling delete immediately after the battle concludes to prevent memory leaks.

4. File Input/Output
   
•	Feature Supported: Game Persistence & External Narrative Driving.
•	Implementation:
o	The game reads story lore and "roast" messages from story.txt and roast.txt using std::ifstream.
o	We implemented a full save/load system in FileIO::saveGame and FileIO::loadGame that serializes player stats (HP, Gold, Kindness, etc.) into save.txt.

5. Program Codes in Multiple Files

•	Feature Supported: Modular Software Architecture.
•	Implementation: The source code is organized into specialized directories: player, enemy, combat_system, event, UI, and FileIO. This modularity allows for clear separation of concerns and maintainable code through header files and implementation files.
Multiple Difficulty Levels (Additional Requirement)
The game provides "Simple" and "Challenging" modes. Selecting "Challenging" (Hard Mode) applies a 1.5x multiplier to base enemy stats, providing a significantly harder experience.

Additional Technical Highlights

•	Karma Influence: The Kindness stat is more than a label; it mathematically scales the final boss's atk and def values, rewarding virtuous players and punishing evil ones.
•	Defensive Coding: We use std::max and std::min throughout player.cpp and combat.cpp to ensure HP never exceeds its max or falls below zero, and that damage is always at least 1 point.
Non-Standard C/C++ Libraries
None. The project is built entirely using the C++11 Standard Library to ensure native compatibility across Unix/Linux environments.

Contribution Note

Although the GitHub Contributors Graph may show an uneven distribution of added lines, this is largely because the member responsible for the event module implemented a very large amount of event text and narrative content, which significantly increased the total line count in that part of the project.
After internal review within the group, we confirm that each member's pure code contribution exceeds 15%, and all team members agree with this assessment without objection.

Compilation and Execution Instructions

We have provided a Makefile to handle the build process automatically. Enter these bash commands when you are in our repository in the terminal.
Clean previous builds:
make clean

Compile the source code:
make

Run the game:
./vengeful_adventurer

