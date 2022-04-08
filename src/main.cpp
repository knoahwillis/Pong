#include <iostream>
#include "Ball.hpp"
#include "Paddle.hpp"
#include "GameRules.hpp"
#include <ctime>
#include <random>

int main(int argc, char *argv[]){

    srand(time(0));

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "Error: " << SDL_GetError();
    }

    SDL_Window* window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, 0);

    SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Paddle player1(0);
    Paddle player2(1070);
    Ball ball;
	pause_menu pause;

    bool close = false;
	bool paused = false;
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);

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
					player1.move_paddle_up();
					break;
				case SDL_SCANCODE_UP:
					player2.move_paddle_up();
					break;
				case SDL_SCANCODE_S:
					player1.move_paddle_down();
					break;
				case SDL_SCANCODE_DOWN:
					player2.move_paddle_down();
					break;
				case SDL_SCANCODE_TAB:
					paused = !paused;
					break;
				case SDL_SCANCODE_ESCAPE:
					paused = !paused;
					break;
				default:
					break;
                }
            }
            player1.stop_paddle_move();
            player2.stop_paddle_move();
		}
		if(!paused){
			ball.move_ball();
		}
		check_collision(ball, player1, player2);
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
        SDL_RenderClear(rend);
		if(paused){
			pause.render_pause(rend);
		}
		ball.render_ball(rend);
        player1.render_paddle(rend);
        player2.render_paddle(rend);
        SDL_RenderPresent(rend);
 
        SDL_Delay(1000 / 60);
	}


	SDL_DestroyRenderer(rend);

	SDL_DestroyWindow(window);
	
	SDL_Quit();

	return 0;

}
