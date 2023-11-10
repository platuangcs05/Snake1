#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"


class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const& controller, std::unique_ptr<Renderer>& renderer,
      std::size_t target_frame_duration);

  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  SDL_Point food;
  SDL_Point SpecialFood;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  int countdown{10};
  bool recreate{ false };

  void PlaceFood();
  void PlaceSpecialFood();
  void Update();
};

#endif