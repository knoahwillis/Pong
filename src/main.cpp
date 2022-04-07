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
    Ball ball;

    play1.h = 150;
    play1.w = 10;
    play1.x = 0;
    play1.y = 200;

    play2.h = 150;
    play2.w = 10;
    play2.x = 1070;
    play2.y = 200;

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
        ball.move_ball();
        if((ball.get_x() < play1.x + play1.w &&
		ball.get_x() + 5 > play1.x &&
		ball.get_y() < play1.y + play1.h &&
		ball.get_y() + 5 > play1.y) || (
        (ball.get_x() < play2.x + play2.w &&
		ball.get_x() + 5 > play2.x &&
		ball.get_y() < play2.y + play2.h &&
		ball.get_y() + 5 > play2.y))){
            ball.reverse_x();
        }
        if(ball.get_x() > 1280 || ball.get_x() < 0){
            ball.start_game();
        }
        SDL_RenderClear(rend);
		SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
        SDL_RenderFillRect(rend, &play1);
        SDL_RenderFillRect(rend, &play2);
        ball.render_ball(rend);
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);

        SDL_RenderPresent(rend);
 
        SDL_Delay(1000 / 60);
	}

	SDL_DestroyRenderer(rend);

	SDL_DestroyWindow(window);
	
	SDL_Quit();

	return 0;

}