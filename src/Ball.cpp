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
    y_vel = rand() % 5;
}
void Ball::render_ball(SDL_Renderer* rend){
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
    SDL_RenderFillRect(rend, &ball);
}

void Ball::move_ball(){
    ball.x += x_vel;
    ball.y += y_vel;
    if(ball.y < 0 || ball.y > 720){
        y_vel *= -1;
    }
}

void Ball::reverse_x(){
    this->x_vel *= -1;
}

void Ball::ball_bounce(){

}

int Ball::get_x(){
    return ball.x;
}

int Ball::get_y(){
    return ball.y;
}




