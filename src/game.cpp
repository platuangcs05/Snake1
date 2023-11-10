#include "game.h"
#include <iostream>
#include "SDL.h"


Game::Game(std::size_t grid_width, std::size_t grid_height)
	: snake(grid_width, grid_height),
	engine(dev()),
	random_w(0, static_cast<int>(grid_width - 1)),
	random_h(0, static_cast<int>(grid_height - 1)) {
	PlaceFood();
	PlaceSpecialFood();
}

void Game::Run(Controller const& controller, std::unique_ptr<Renderer>& renderer,
	std::size_t target_frame_duration) {
	Uint32 title_timestamp = SDL_GetTicks();
	Uint32 frame_start;
	Uint32 frame_end;
	Uint32 frame_duration;
	int frame_count = 0;
	bool running = true;
	while (running) {
		frame_start = SDL_GetTicks();

		// Input, Update, Render - the main game loop.
		controller.HandleInput(running, snake);
		renderer->Render(snake, food, SpecialFood);
		Update();
		frame_end = SDL_GetTicks();

		// Keep track of how long each loop through the input/update/render cycle
		// takes.
		frame_count++;
		frame_duration = frame_end - frame_start;

		// After every second, update the window title.
		if (frame_end - title_timestamp >= 1000) {
			renderer->UpdateWindowTitle(score, frame_count, countdown);
			if (countdown == 0)
			{
				recreate = true;
				countdown = 10;
			}
			countdown--;
			frame_count = 0;
			title_timestamp = frame_end;
		}

		// If the time for this frame is too small (i.e. frame_duration is
		// smaller than the target ms_per_frame), delay the loop to
		// achieve the correct frame rate.
		if (frame_duration < target_frame_duration) {
			SDL_Delay(target_frame_duration - frame_duration);
		}
	}
}

void Game::PlaceFood() {
	int x, y;
	while (true) {
		x = random_w(engine);
		y = random_h(engine);
		// Check that the location is not occupied by a snake item before placing
		// food.
		if (!snake.SnakeCell(x, y)) {
			food.x = x;
			food.y = y;
			return;
		}
	}
}


void Game::PlaceSpecialFood() {
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    bool bCheck = distribution(engine) < PROBABILITY / 100.0;
    
    while (bCheck) {
        int x = random_w(engine);
        int y = random_h(engine);
        
        if (!snake.SnakeCell(x, y) && x != food.x && y != food.y) {
            SpecialFood.x = x;
            SpecialFood.y = y;
            return;
        }
        
        bCheck = distribution(engine) < PROBABILITY / 100.0;
    }
}


void Game::Update() {
	if (!snake.alive) return;

	snake.Update();
	//food position
	int new_x = static_cast<int>(snake.head_x);
	int new_y = static_cast<int>(snake.head_y);
	//speacical food position
	int newSpecical_x = static_cast<int>(snake.head_x);
	int newSpecical_y = static_cast<int>(snake.head_y);
	if (recreate)
	{
		recreate = false;
		PlaceSpecialFood();
	}
	// Check if there's food over here
	if (food.x == new_x && food.y == new_y) {
		score++;
		PlaceFood();
		// Grow snake and increase speed.
		snake.GrowBody();
		snake.speed += 0.02;
	}
	// Check if there's specical food over here
	if (SpecialFood.x == newSpecical_x && SpecialFood.y == newSpecical_y) {
   		score = (score == 0) ? 3 : score + 3;
      	PlaceSpecialFood();
	}
}



int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }