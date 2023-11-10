#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "SnakeLog.h"

#include <chrono>

int main() {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};

    // Initialize the Renderer, Controller, and Game objects
    std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    SnakeLog SnakeLog;
    SnakeLog.Start();
    auto startTime = std::chrono::steady_clock::now();
    game.Run(controller, renderer, kMsPerFrame);
    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    SnakeLog.End(game.GetScore(), game.GetSize(), elapsedTime);
    std::cout << "[Program completion time]: " << elapsedTime << " seconds\n";
    std::cout << "[Final score]: " << game.GetScore() << "\n";
    std::cout << "[Snake size]: " << game.GetSize() << "\n";
    return 0;
}
