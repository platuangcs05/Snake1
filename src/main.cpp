#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "SnakeLog.h"

#include <chrono>

int main() {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{600};
    constexpr std::size_t kScreenHeight{600};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};

    std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);

    //[TUAN] Add log
    SnakeLog SnakeLog;
    SnakeLog.Start();
    
    game.SnakeSpeed(); //Tuan Add Speed
    
    game.Run(controller, renderer, kMsPerFrame);

    //[TUAN] Snake Time
    SnakeLog.End(game.GetScore(), game.GetSize(), game.frame_snakeTime);

    std::cout << "Snake Time: " << game.frame_snakeTime << " seconds\n";
    std::cout << "Snake Score: " << game.GetScore() << "\n";
    std::cout << "Snake Size: " << game.GetSize() << "\n";
    return 0;
}
