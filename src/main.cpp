#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

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

    //auto startTime = std::chrono::steady_clock::now();
    
    game.UpdateStartSpeed(); //Tuan Add Speed
    
    game.Run(controller, renderer, kMsPerFrame);
    //auto endTime = std::chrono::steady_clock::now();
    //auto snakeTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();

    //[TUAN] Snake Time
    std::cout << "Snake Time: " << game.frame_snakeTime << " seconds\n";
    std::cout << "Snake Score: " << game.GetScore() << "\n";
    std::cout << "Snake Size: " << game.GetSize() << "\n";
    return 0;
}
