#include "game.h"
#include <iostream>
#include "SDL.h"
#include <thread>
#include <chrono>
#include <future>

Game::Game(std::size_t grid_width, std::size_t grid_height)
	: snake(grid_width, grid_height),
	engine(dev()),
	random_w(0, static_cast<int>(grid_width - 1)),
	random_h(0, static_cast<int>(grid_height - 1)) {
	PlaceFood();
	PlaceWall(); //[TUAN] Add wall
}

/**
 * @brief TimerThread: Adding Poison spell, will return snake to normal after 10 seconds
 */

void TimerThread(bool *poisoned) {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    // get back to normal after 10 seconds
    *poisoned = false;
}


void Game::Run(Controller const& controller, std::unique_ptr<Renderer>& renderer,
	std::size_t target_frame_duration) {
	Uint32 title_timestamp = SDL_GetTicks();
	Uint32 frame_start;
	//Uint32 frame_end;
	Uint32 frame_duration;
	int frame_count = 0;
	bool running = true;

	frame_tickinsecond = SDL_GetTicks(); //[TUAN] Add frame_tickinsecond

	while (running) {
		frame_start = SDL_GetTicks();

		// Input, Update, Render - the main game loop.
		controller.HandleInput(running, snake, *this);

		renderer->Render(snake, food, wall, &_poisoned); //[TUAN] Add wall
		//--------------------

		Update();
		frame_end = SDL_GetTicks();

		// Keep track of how long each loop through the input/update/render cycle
		// takes.
		frame_count++;
		frame_duration = frame_end - frame_start;

		// After every second, update the window title.
		
		if (frame_end - frame_tickinsecond >= 1000) {
			if (snake.alive)  {
			frame_snakeTime = (frame_end - title_timestamp)/1000;
			renderer->UpdateWindowTitle(score, frame_snakeTime);
			}
			
			frame_count = 0;
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

/**
 * @brief SnakeSpeed: Add Speed
 */
void Game::SnakeSpeed()
{
  snake.SetSpeed();
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

/**
 * @brief PlaceWall: Call PlaceWall
 */
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

void Game::Update() {
	if (!snake.alive)
	return;

	snake.Update();
	
	int new_x = static_cast<int>(snake.head_x);
	int new_y = static_cast<int>(snake.head_y);

	int newWall_x = static_cast<int>(snake.head_x); //[TUAN] Add wall
	int newWall_y = static_cast<int>(snake.head_y); //[TUAN] Add wall

	if (recreate)
	{
		recreate = false;
		PlaceWall();
	}

  	std::random_device rd;  //Will be used to obtain a seed for the random number engine
  	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  	std::uniform_int_distribution<> dis(1, 10);

	// Check if there's food over here
	if (food.x == new_x && food.y == new_y) {
		score++;
		PlaceFood();
		// Grow snake and increase speed.
		snake.GrowBody();
		snake.speed += 0.02;
		
		// 20 percentage change for the poisonous food
    	if(dis(gen) <= 2){
      		_poisoned = true;
      		// resolves 5 seconds later
      		std::thread poisonTimer(TimerThread, &_poisoned);
      		poisonTimer.detach();
    	}
	}

	// Check if there's wall here
	if (wall.x == newWall_x && wall.y == newWall_y) {
		snake.alive = false;
	}
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }