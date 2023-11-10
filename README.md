# CPPND: Capstone Snake Game Example with Score Logging and Multi-threading

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

![Snake Game](snake_game.gif)

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Score Logging and Multi-threading
Now includes a log of gameplay dates, scores, snake size, and playtime in the `SnakeLog.txt` file. This information is captured and written using multi-threading to prevent any impact on game performance.

## Special food
In addition to regular food, the game now also has a special dish. If the snake eats special food, it will gain random points and not increase in size. Every 10 seconds there will be a special food random mode that will be regenerated.

## Smart Pointer Usage
The `Renderer` class now uses smart pointers for managing SDL resources. Smart pointers automatically manage the lifetime of the SDL resources, preventing memory leaks.

## Rubric Points Addressed

1. The project demonstrates an understanding of C++ functions and control structures.
2. The project reads data from a file and processes the data, or the program writes data to a file.
3. The project accepts user input and processes the input.
4. Classes use appropriate access specifiers for class members.
5. The project uses Object Oriented Programming techniques.

## CC Attribution-ShareAlike 4.0 International

![CC BY-SA 4.0](https://licensebuttons.net/l/by-sa/4.0/88x31.png)

This work is licensed under a [Creative Commons Attribution-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-sa/4.0/).
