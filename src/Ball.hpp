#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Ball{
    SDL_Rect ball;  //the object that is the ball
    int x_vel;      //holds the current x velocity
    int y_vel;      //holds the current y velocity
public:
    void start_game();      //starts the game by selecting a random x and y velocity
    void move_ball();       //moves the ball
    void render_ball(SDL_Renderer* rend);     //renders the ball
    void reverse_x();       //reverses the direction of x (if it hits a paddle)
    void ball_bounce();     //reverses the direction of y (if it hits a wall)
    int get_x();            //returns the x position of the ball
    int get_y();            //returns the y position of the ball
};