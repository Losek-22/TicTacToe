#include "TicTacToe.h"
/*
This is my take on TicTacToe in C++. I am aware of popularity of this beginner project,
but I did not follow any guide or check the internet for ready solutions.

Note: This code does not represent my current programming skills. I've done it as an exercise after
completing first out of three parts of Bjarne Stroustrup's "Programming - Principles and Practise using C++"
as an exercise. My skills keep improving.

*/

int main() {
	TicTacToe::Game game_instance = TicTacToe::begin_game();												// initialise the game and create main game object
	while (true) {
		try {
			game_instance.display_board();
			game_instance.player_move(1);																	// 1st player move
			game_instance.display_board();
			if (game_instance.check_for_threes()) {															// was there a consequtive three after player1's turn?
				game_instance.handle_game_end(1);
			}
			game_instance.player_move(2);																	// 2nd player move
			game_instance.display_board();
			if (game_instance.check_for_threes()) {															// was there a consequtive three after player2's turn?
				game_instance.handle_game_end(2);															// ask if player wants to continue playing, if not exit, if yes
			}
		}
		catch (std::exception& e) {
			std::cout << std::endl << std::endl << "Exception occured: " << e.what() << std::endl;
		}
		catch (...) {
			std::cout << std::endl << std::endl << "Unknown error occured." << std::endl;
		}
	}
}
