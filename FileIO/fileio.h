#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <iostream>
#include "../player/player.h"   // needed for Player struct

class FileIO {
private:
    std::string logFileName;
    std::string saveFileName;

public:
    FileIO();
 
    // Checks / pre-loads any required local resources.
    void loadGameData();
 
    // Appends a timestamped entry to game_log.txt.
    void writeLog(const std::string& message);
 
    // Reads every line of a plain-text file and returns them as a vector.
    std::vector<std::string> readTextFile(const std::string& filename);
 
    // ── Task 2: Persistence ───────────────────────────────────────────────
 
    // Writes the current game state (player stats + chapter) to save.txt
    // using std::ofstream.
    // chapterIndex: 0 = Forest, 1 = Mountain, 2 = Abyss, 3 = Completed
    // isHardMode: stored so the game can restore the correct difficulty.
    void saveGame(const Player &p, int chapterIndex, bool isHardMode);
 
    // Reads save.txt with std::ifstream and fills the out-parameters.
    // Returns true on success, false if the file does not exist or is corrupt.
    bool loadGame(Player &p, int &chapterIndex, bool &isHardMode);
};

#endif