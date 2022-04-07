#pragma once

class Ball{
    int x_vel;      //holds the current x velocity
    int y_vel;      //holds the current y velocity
public:
    void start_game();      //starts the game by selecting a random x and y velocity

    void reverse_x();       //reverses the direction of x (if it hits a paddle)
    void reverse_y();       //reverses the direction of y (if it hits a wall)
};