#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char *argv[]){

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "Error: " << SDL_GetError();
    }

    
}