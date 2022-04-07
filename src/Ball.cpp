#include "Ball.hpp"
#include <ctime>
#include <random>

void Ball::start_game(){
    srand(time(0));
    this->x_vel = rand() % 5000;
    this->y_vel = rand() % 5000;
}

void Ball::reverse_x(){
    this->x_vel *= -1;
}

void Ball::reverse_y(){
    this->x_vel *= -1;
}


