#include "game.h"
#include <iostream>
#include "SDL.h"


Game::Game(std::size_t grid_width, std::size_t grid_height)
	: snake(grid_width, grid_height),
	engine(dev()),
	random_w(0, static_cast<int>(grid_width - 1)),
	random_h(0, static_cast<int>(grid_height - 1)) {
	PlaceFood();

	//[TUAN] Add wall
	PlaceWall();
	//--------------------
}

void Game::Run(Controller const& controller, std::unique_ptr<Renderer>& renderer,
	std::size_t target_frame_duration) {
	Uint32 title_timestamp = SDL_GetTicks();
	Uint32 frame_start;
	Uint32 frame_end;
	Uint32 frame_duration;
	int frame_count = 0;
	bool running = true;

	//Tuan
	Uint32 frame_tickinsecond = SDL_GetTicks();

	while (running) {
		frame_start = SDL_GetTicks();

		// Input, Update, Render - the main game loop.
		controller.HandleInput(running, snake);

		//[TUAN] Add wall
		renderer->Render(snake, food, wall);
		//--------------------

		Update();
		frame_end = SDL_GetTicks();

		// Keep track of how long each loop through the input/update/render cycle
		// takes.
		frame_count++;
		frame_duration = frame_end - frame_start;

		//Tuan
		// After every second, update the window title.
		//if (frame_end - title_timestamp >= 1000) {
		if (frame_end - frame_tickinsecond >= 1000) {

			//renderer->UpdateWindowTitle(score, countdown);
			renderer->UpdateWindowTitle(score, (frame_end - title_timestamp)/1000);

			if (countdown == 0)
			{
				recreate = true;
				countdown = 3;
			}
			countdown--;
			frame_count = 0;

			//title_timestamp = frame_end;
			frame_tickinsecond = frame_end;
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

//[TUAN] Add wall
//--------------------
void Game::PlaceWall() {	
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    bool bCheck = distribution(engine) < PROBABILITY / 100.0;
    
    while (bCheck) {
        int x = random_w(engine);
        int y = random_h(engine);
        
        if (!snake.SnakeCell(x, y) && x != food.x && y != food.y) {
            wall.x = x;
            wall.y = y;
            return;
        }
        
        bCheck = distribution(engine) < PROBABILITY / 100.0;
    }
}
//--------------------

void Game::Update() {
	if (!snake.alive)
	return;

	snake.Update();
	
	int new_x = static_cast<int>(snake.head_x);
	int new_y = static_cast<int>(snake.head_y);

	//[TUAN] Add wall
	//--------------------
	int newWall_x = static_cast<int>(snake.head_x);
	int newWall_y = static_cast<int>(snake.head_y);

	if (recreate)
	{
		recreate = false;
		PlaceWall();
	}
	
	//[TUAN] Add food & wall
	// Check if there's food over here
	if (food.x == new_x && food.y == new_y) {
		score++;
		PlaceFood();
		// Grow snake and increase speed.
		snake.GrowBody();
		snake.speed += 0.02;
	}

	// Check if there's wall here
	if (wall.x == newWall_x && wall.y == newWall_y) {
		snake.alive = false;
	}
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }