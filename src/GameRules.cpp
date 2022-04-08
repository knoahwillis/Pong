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
