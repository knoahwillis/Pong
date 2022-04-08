#include "Paddle.hpp"

Paddle::Paddle(int x_pos){
    paddle.x = x_pos;
    paddle.y = 200;
    paddle.h = 150;
    paddle.w = 10;
}

void Paddle::render_paddle(SDL_Renderer* rend){
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
    SDL_RenderFillRect(rend, &paddle);
}

void Paddle::move_paddle_up(){
    paddle.y -= speed / 30;
}

void Paddle::move_paddle_down(){
    paddle.y += speed / 30;
}

void Paddle::stop_paddle_move(){
    if(paddle.y < 0){
        paddle.y = 0;
    }else if(paddle.y + paddle.h > 720){
        paddle.y = 720 - paddle.h;
    }
}

int Paddle::get_paddle_x(){
    return paddle.x;
}

int Paddle::get_paddle_y(){
    return paddle.y;
}