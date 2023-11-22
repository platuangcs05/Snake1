#include "SnakeLog.h"

ScopedLogFile::ScopedLogFile(const std::string& filename, std::ios_base::openmode mode)
    : file(filename, mode) {}

ScopedLogFile::~ScopedLogFile() {
    if (file.is_open()) {
        file.close();
    }
}

std::ofstream& ScopedLogFile::get() {
    return file;
}

SnakeLog::SnakeLog()
    : stopThread(false),
    logFile("SnakeLog.txt", std::ios::out | std::ios::app),
    SnakeLogThread(&SnakeLog::SnakeLogLoop, this) {}

SnakeLog::~SnakeLog() {
    stopThread = true;
    SnakeLogThread.join();
}

void SnakeLog::Start() {
    auto currentTime = std::chrono::steady_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());  
    std::lock_guard<std::mutex> lock(logMutex);
    logFile.get() << "Game initiated at: " << std::ctime(&time);
}

void SnakeLog::End(int score, int size, long totalTime) {
    auto currentTime = std::chrono::steady_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());  
    std::lock_guard<std::mutex> lock(logMutex);
    logFile.get() << "..................................................................." << std::endl;
    logFile.get() << "Game completion time: " << std::ctime(&time);
    logFile.get() << "Snake Time: " << totalTime << " seconds" << std::endl;
    logFile.get() << "Snake Score: " << score << std::endl;
    logFile.get() << "Snake Size: " << size << std::endl;
    logFile.get() << "..................................................................." << std::endl;
}

void SnakeLog::SnakeLogLoop() {
    while (!stopThread) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
