#include "fileio.h"
#include <iostream>
#include <fstream>
#include <ctime>

// Setting the name of log
FileIO::FileIO() {
    logFileName = "game_log.txt";
    saveFileName = "save.txt";
    
    // Writing the launching mark into log
    std::ofstream logFile(logFileName, std::ios::app);
    if (logFile.is_open()) {
        logFile << "\n========================================\n";
        logFile << "[SYSTEM] Game Session Started\n";
        logFile << "========================================\n";
        logFile.close();
    }
}

void FileIO::loadGameData() {
    std::cout << "[System] Checking local resources..." << std::endl;
    // For future improvement
    std::cout << "[System] Game data loaded successfully." << std::endl;
}

// Generate log.txt
void FileIO::writeLog(const std::string& message) {
    // Ensuring the old log would not be covered
    std::ofstream logFile(logFileName, std::ios::app);
    
    if (logFile.is_open()) {
        logFile << "[LOG] " << message << std::endl;
        logFile.close();
    } else {
        // Error report
        std::cerr << "[Error] Unable to open log file: " << logFileName << std::endl;
    }
}

//Reading text
std::vector<std::string> FileIO::readTextFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream inFile(filename);
    std::string line;

    if (inFile.is_open()) {
        // Reading file content
        while (std::getline(inFile, line)) {
            lines.push_back(line);
        }
        inFile.close();
    } 
    else {
        std::cerr << "[Warning] Could not read text file: " << filename << std::endl;
        // Error report
        lines.push_back("Error 404: Text not found."); 
    }

    return lines;
}

//Saving Game Progress
void FileIO::saveGame(const Player &p, int chapterIndex, bool isHardMode) {
    std::ofstream out(saveFileName);       // overwrites any previous save
    if (!out.is_open()) {
        std::cerr << "[Error] Could not open save file for writing: "
                  << saveFileName << std::endl;
        return;
    }
 
    out << "chapter "  << chapterIndex          << "\n";
    out << "hard "     << (isHardMode ? 1 : 0)  << "\n";
    out << "hp "       << getPlayerHP(p)         << "\n";
    out << "maxHp "    << getPlayerMaxHP(p)      << "\n";
    out << "attack "   << getPlayerAttack(p)     << "\n";
    out << "defense "  << getPlayerDefense(p)    << "\n";
    out << "gold "     << getPlayerGold(p)       << "\n";
    out << "kindness " << getPlayerKindness(p)   << "\n";
 
    out.close();
 
    writeLog("Game saved. Chapter=" + std::to_string(chapterIndex)
             + " HP=" + std::to_string(getPlayerHP(p)));
    std::cout << "[System] Game saved successfully." << std::endl;
}

//Load the game
bool FileIO::loadGame(Player &p, int &chapterIndex, bool &isHardMode) {
    std::ifstream in(saveFileName);
    if (!in.is_open()) {
        std::cerr << "[Warning] No save file found: " << saveFileName << std::endl;
        return false;
    }
 
    // Temporary variables so we only modify the out-params on full success
    int  chapter = 0, hard = 0;
    int  hp = 0, maxHp = 0, attack = 0, defense = 0, gold = 0, kindness = 0;
 
    std::string label;
    bool ok = true;
 
    // Read exactly 8 labelled lines
    auto readInt = [&](const std::string& expected, int &dest) {
        std::string lbl;
        if (!(in >> lbl >> dest) || lbl != expected) {
            std::cerr << "[Error] Save file corrupt at field: " << expected << std::endl;
            ok = false;
        }
    };
 
    readInt("chapter",  chapter);
    readInt("hard",     hard);
    readInt("hp",       hp);
    readInt("maxHp",    maxHp);
    readInt("attack",   attack);
    readInt("defense",  defense);
    readInt("gold",     gold);
    readInt("kindness", kindness);
 
    in.close();
 
    if (!ok) return false;
 
    // Commit values to the out-parameters
    chapterIndex = chapter;
    isHardMode   = (hard != 0);
 
    setPlayerMaxHP(p,    maxHp);
    setPlayerHP(p,       hp);
    setPlayerAttack(p,   attack);
    setPlayerDefense(p,  defense);
    setPlayerGold(p,     gold);
    setPlayerKindness(p, kindness);
 
    writeLog("Game loaded. Chapter=" + std::to_string(chapterIndex)
             + " HP=" + std::to_string(getPlayerHP(p)));
    std::cout << "[System] Game loaded successfully." << std::endl;
    return true;
}
 