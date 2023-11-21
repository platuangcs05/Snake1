# CPPND: Capstone Snake Game 1.0

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.


## Build/Running Instructions
1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

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


## Features added to the game
# Features 1: Add user input the SpeedGame
Expected behavior
  * Adding SnakeSpeed, the user can input which SnakeSpeed they want to play a game.
    game.cpp line 77

# Features 2: Add Walls
Expected behavior
  * Adding walls, the game now also has a red walls.
  * The Snake will die if it hit the walls or youself.
    game.cpp line 12,80, 126

# Features 3: Add Game Time
Expected behavior
  * Adding Game Time, the game now also has a Game Time on title so that players can know and manage their playing time with the aim of achieving the highest score in the shortest time.
    game.cpp line 45

  * Game Time will be displayed as Snake Time together with Snake Score, Snake Size.
    main.cpp line 30

# Features 4: Add spells
Expected behavior
  * Adding spells, Players will be surprised when encountering spells. 
    The game will use Poison Spell, and will develop many other spells later.
    Spell duration is 10 seconds.
    When Snake eat a Poison Spell, user cannot control the snake as they want.
    game.cpp line 18

# Features 5: Add Log
Expected behavior
  * Adding log, the game will be logged the game date, Snake Time, Snake Score, Snake size in the `SnakeLog.txt` file.
  main.cpp line 22

## Rubric Description
# Loops, Functions, I/O
  * The project code is clearly organized into functions.
  * The project accepts user input and processes the input.

# Object Oriented Programming
  * All class data members are explicitly specified as public, protected, or private.
  * Classes are organized with attributes to hold data and methods to perform tasks.

# Memory Management
  * The project makes use of references in function declarations.
  * The project uses destructors appropriately.
  * The project uses smart pointers instead of raw pointers.

# Concurrency
  * The project uses multithreading.
  * A mutex or lock is used in the project.

## CC Attribution-ShareAlike 4.0 International

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
