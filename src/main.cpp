#include <iostream>
#include "Ball.hpp"
#include <ctime>
#include <random>

int main(int argc, char *argv[]){

    srand(time(0));

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "Error: " << SDL_GetError();
    }

    SDL_Window* window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, 0);

    SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Rect play1;
    SDL_Rect play2;
    SDL_Rect ball;

    play1.h = 150;
    play1.w = 10;
    play1.x = 0;
    play1.y = 200;

    play2.h = 150;
    play2.w = 10;
    play2.x = 1070;
    play2.y = 200;

    ball.h = 5;
    ball.w = 5;
    ball.x = 1080 / 2;
    ball.y = 1080 / 2;

    int ball_x_vel = 5;
    int ball_y_vel = rand() % 3;


    bool close = false;

    int speed = 900;

	while(!close){
		SDL_Event e;

		while(SDL_PollEvent(&e)){
			switch (e.type) {

			case SDL_QUIT:
				close = true;
				break;

			case SDL_KEYDOWN:
				switch (e.key.keysym.scancode) {
				case SDL_SCANCODE_W:
					play1.y -= speed / 30;
					break;
				case SDL_SCANCODE_UP:
					play2.y -= speed / 30;
					break;
				case SDL_SCANCODE_S:
					play1.y += speed / 30;
					break;
				case SDL_SCANCODE_DOWN:
					play2.y += speed / 30;
					break;
				default:
					break;
                }
            if (play1.y + play1.h > 720){
                play1.y = 720 - play1.h;
			}
            if (play2.y + play2.h > 720){
                play2.y = 720 - play2.h;
			}
            if (play1.y < 0){
                play1.y = 0;
			}
            if (play2.y < 0){
                play2.y = 0;
			}
            }
		}
        ball.y += ball_y_vel;
        ball.x += ball_x_vel;
        if(ball.y < 0 || ball.y > 720){
            ball_y_vel *= -1;
        }
        if((ball.x < play1.x + play1.w &&
		ball.x + ball.w > play1.x &&
		ball.y < play1.y + play1.h &&
		ball.y + ball.h > play1.y) || (
        (ball.x < play2.x + play2.w &&
		ball.x + ball.w > play2.x &&
		ball.y < play2.y + play2.h &&
		ball.y + ball.h > play2.y))){
            ball_x_vel *= -1;
        }
        if(ball.x > 1280 || ball.x < 0){
            ball.x = 1080 / 2;
            ball.y = 1080 / 2;
            ball_x_vel = -5;
            ball_y_vel = rand() % 3;
        }
        SDL_RenderClear(rend);
		SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
        SDL_RenderFillRect(rend, &play1);
        SDL_RenderFillRect(rend, &play2);
        SDL_RenderFillRect(rend, &ball);
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);

        SDL_RenderPresent(rend);
 
        SDL_Delay(1000 / 60);
	}

	SDL_DestroyRenderer(rend);

	SDL_DestroyWindow(window);
	
	SDL_Quit();

	return 0;

}