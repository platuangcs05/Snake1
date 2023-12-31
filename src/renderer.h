#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include <memory>
#include <string>

class Renderer {
public:
    Renderer(const std::size_t screen_width, const std::size_t screen_height,
        const std::size_t grid_width, const std::size_t grid_height);
    ~Renderer(); // hàm disstructer huy object

    void Render(Snake const snake, SDL_Point const& food, SDL_Point const& poisonousFood, bool *poisoned);
    void UpdateWindowTitle(std::string name, int score, int startTime);

private:
    std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> sdl_window;
    std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> sdl_renderer;

    const std::size_t screen_width;
    const std::size_t screen_height;
    const std::size_t grid_width;
    const std::size_t grid_height;
};

#endif
