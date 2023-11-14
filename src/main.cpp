#include <iostream>
#include <chrono>
#include <thread>

#include "controller.h"
#include "game.h"
#include "renderer.h"

//#include "SnakeLog.h"

int main() {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};

    //[TUAN] Add 
    std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    //SnakeLog SnakeLog;
    //SnakeLog.Start();
    //auto startTime = std::chrono::steady_clock::now();
    steady_clock::time_point startTime = steady_clock::now(); // 1. 現在日時を取得
    std::this_thread::sleep_for(seconds(3)); // 2. 時間のかかる処理...
    
    game.Run(controller, renderer, kMsPerFrame);

    //auto endTime = std::chrono::steady_clock::now();
    steady_clock::time_point endTime = steady_clock::now(); // 3. 現在日時を再度取得 // 1～3の間にシステム時計が変更されても時間が逆行することはない

    //auto elapsedTime = duration_cast<seconds>(endTime - startTime).count();
    auto snakeTime = duration_cast<seconds>(endTime - startTime).count();

    //SnakeLog.End(game.GetScore(), game.GetSize(), snakeTime);

    //[TUAN] Add time
    std::cout << "Snake Time: " << snakeTime << " seconds\n";
    std::cout << "Snake Score: " << game.GetScore() << "\n";
    std::cout << "Snake Size: " << game.GetSize() << "\n";
    return 0;
}