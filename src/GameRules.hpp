#pragma once
#include "Paddle.hpp"
#include "Ball.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void check_collision(Ball &ball, Paddle player1, Paddle player2);

class pause_menu{
    SDL_Rect pause1;    //first rectangle on left
    SDL_Rect pause2;    //second rectangle on right
public:
    pause_menu();
    void render_pause(SDL_Renderer* rend);
};