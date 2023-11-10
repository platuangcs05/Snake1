#ifndef SnakeLog_H
#define SnakeLog_H

#include <fstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>


class ScopedLogFile {
public:
    ScopedLogFile(const std::string& filename, std::ios_base::openmode mode);
    ~ScopedLogFile();
    std::ofstream& get();

private:
    std::ofstream file;
};

class SnakeLog {
public:
    SnakeLog();
    ~SnakeLog();
    void Start();
    void End(int score, int size, long totalTime);

private:
    std::thread SnakeLogThread;
    std::atomic<bool> stopThread;
    ScopedLogFile logFile;
    std::mutex logMutex;

    void SnakeLogLoop();
};

#endif // SnakeLog_H
