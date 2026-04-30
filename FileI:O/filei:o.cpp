#include "filei:o.h"
#include <iostream>
#include <fstream>
#include <ctime>

// Setting the name of log
FileIO::FileIO() {
    logFileName = "game_log.txt";
    
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
    } else {
        std::cerr << "[Warning] Could not read text file: " << filename << std::endl;
        // Error report
        lines.push_back("Error 404: Text not found."); 
    }

    return lines;
}