#pragma once
#include "Paddle.hpp"
#include "Ball.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void check_collision(Ball &ball, Paddle player1, Paddle player2);