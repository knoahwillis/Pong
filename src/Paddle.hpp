#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Paddle{
    SDL_Rect paddle;    //the object that is the paddle
    int speed = 900;          //the speed the player can move the paddle
public:
    Paddle(int x_pos);
    void render_paddle(SDL_Renderer* rend);     //renders the paddle
    void move_paddle_up();     //moves the paddle up
    void move_paddle_down();   //moves the paddle down
    void stop_paddle_move();   //stops the paddle if it hits the end of the screen
    int get_paddle_x();
    int get_paddle_y();
};