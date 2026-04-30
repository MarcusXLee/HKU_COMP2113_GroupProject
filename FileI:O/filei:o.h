#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <iostream>

class FileIO {
private:
    std::string logFileName;

public:
    // 构造函数，初始化时可以清空旧日志或写入启动时间
    FileIO();
    
    // 负责系统初始化时的一些读取或检查
    void loadGameData();

    // 核心功能 1：追加写入日志
    // 示例用法：fileIO.writeLog("Player entered Forest. Event 3 triggered.");
    void writeLog(const std::string& message);

    // 核心功能 2：读取外部文本文件（比如 ASCII Art，或者幽默语录）
    // 返回一个 string 数组，每一行是数组的一个元素
    std::vector<std::string> readTextFile(const std::string& filename);
};

#endif