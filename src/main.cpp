#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Ball.hpp"

int main(int argc, char *argv[]){

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "Error: " << SDL_GetError();
    }

    SDL_Window* window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, 0);

    SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Rect play1;
    SDL_Rect play2;
    SDL_Surface* ball;

    play1.h = 150;
    play1.w = 10;
    play1.x = 500;
    play1.y = 200;

    play2.h = 150;
    play2.w = 10;
    play2.x = 900;
    play2.y = 200;



    bool close = false;

    int speed = 500;
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
				case SDL_SCANCODE_A:
					play1.x -= speed / 30;
					break;
				case SDL_SCANCODE_LEFT:
					play2.x -= speed / 30;
					break;
				case SDL_SCANCODE_S:
					play1.y += speed / 30;
					break;
				case SDL_SCANCODE_DOWN:
					play2.y += speed / 30;
					break;
				case SDL_SCANCODE_D:
					play1.x += speed / 30;
					break;
				case SDL_SCANCODE_RIGHT:
					play2.x += speed / 30;
					break;
				default:
					break;
				}
			}
		}
		SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
        SDL_RenderFillRect(rend, &play1);
        SDL_RenderFillRect(rend, &play2);

        SDL_RenderPresent(rend);
 
        SDL_Delay(1000 / 60);
	}

	SDL_DestroyRenderer(rend);

	SDL_DestroyWindow(window);
	
	SDL_Quit();

	return 0;

}