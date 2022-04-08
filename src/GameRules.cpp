#include "GameRules.hpp"

void check_collision(Ball &ball, Paddle player1, Paddle player2){
		    if((ball.get_x() < player1.get_paddle_x() + 10 &&
		ball.get_x() + 5 > player1.get_paddle_x() &&
		ball.get_y() < player1.get_paddle_y() + 150 &&
		ball.get_y() + 5 > player1.get_paddle_y()) || (
        (ball.get_x() < player2.get_paddle_x()+ 150 &&
		ball.get_x() + 5 > player2.get_paddle_x() &&
		ball.get_y() < player2.get_paddle_y() + 150 &&
		ball.get_y() + 5 > player2.get_paddle_y()))){
            ball.reverse_x();
        }
    if(ball.get_x() > 1280 || ball.get_x() < 0){
            ball.start_game();
        }
}

pause_menu::pause_menu(){
    pause1.x = 455;
    pause2.x = 570;
    pause1.y = 225;
    pause2.y = 225;

    pause1.h = 250;
    pause2.h = 250;
    pause1.w = 50;
    pause2.w = 50;
}

void pause_menu::render_pause(SDL_Renderer* rend){
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
    SDL_RenderFillRect(rend, &pause1);
    SDL_RenderFillRect(rend, &pause2);
}


