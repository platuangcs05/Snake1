#include <iostream>
#include <chrono>

#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "SnakeLog.h"

int main() {
    constexpr std::size_t kFramesPerSecond{60}; //constexpr hang so
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{600};
    constexpr std::size_t kScreenHeight{600};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};

    //smart pointer tu dong delete, new & delete
    std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    
    // class tao kieu du lieu, bien tao ra tu class goi object,
    Controller controller; //stack
    Game game(kGridWidth, kGridHeight); //stack

    SnakeLog SnakeLog; // //stack
    SnakeLog.Start(); //ham trong class la method (API)
    
    game.SnakeSpeed(); // Cach goi
    
    game.Run(controller, renderer, kMsPerFrame);

    //[TUAN] Snake Time
    SnakeLog.End(game.GetScore(), game.GetSize(), game.frame_snakeTime);

    std::cout << "Snake Time: " << game.frame_snakeTime << " seconds\n";
    std::cout << "Snake Score: " << game.GetScore() << "\n";
    std::cout << "Snake Size: " << game.GetSize() << "\n";
    return 0;
}
