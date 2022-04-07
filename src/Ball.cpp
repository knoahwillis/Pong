#include "Ball.hpp"
#include <ctime>
#include <random>

void Ball::start_game(){
    srand(time(0));
    ball.h = 5;
    ball.w = 5;
    ball.x = 1080 / 2;
    ball.y = 1080 / 2;
    x_vel = 5;
    y_vel = rand() % 3;
}

void Ball::move_ball(){
    ball.x += x_vel;
    ball.y += y_vel;
}

void Ball::reverse_x(){
    this->x_vel *= -1;
}

void Ball::reverse_y(){
    this->x_vel *= -1;
}

int Ball::get_x(){
    return ball.x;
}

int Ball::get_y(){
    return ball.y;
}


