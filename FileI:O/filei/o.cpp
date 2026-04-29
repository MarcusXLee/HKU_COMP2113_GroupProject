// combat_system/FileIO.h
#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <iostream>

class FileIO {
public:
    FileIO() = default;
    
    // 负责读取游戏存档或外部配置文本
    void loadGameData() {
        std::cout << "[System] Game data loaded successfully." << std::endl;
        // 未来可以在这里补充具体的 fstream 读取逻辑
    }

    void saveGameData() {
        // 未来可以在这里补充存档逻辑
    }
};

#endif