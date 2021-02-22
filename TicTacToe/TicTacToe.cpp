#include "TicTacToe.h"
#include <iostream>
#include <stdlib.h>

/* 
global constants used
board_size is in header file - can't define constexpr in separate file 
*/
const TicTacToe::mark player1_mark = TicTacToe::mark::cross;									// player 1's mark (if changed you need to change text in game constructor)
const TicTacToe::mark player2_mark = TicTacToe::mark::nought;									// player 2's mark

/*
Initialises name of a player
Arguments: Game instance, string name of the player, number of player (1 or 2)
*/
TicTacToe::Game TicTacToe::begin_game() {
	std::string player1_name;
	std::string player2_name;
	std::cout << "The game has been initialised." << std::endl <<
		"Input the name of first player, whose mark will be a cross." << std::endl;
	std::cin >> player1_name;
	std::cout << "Input the name of second player, whose mark will be a nought." << std::endl;
	std::cin >> player2_name;
	return TicTacToe::Game::Game(player1_name, player2_name);
}

/* 
Game constructor
Arguments: string name of player 1, string name of player 2
Outputs: game object
*/
TicTacToe::Game::Game(const std::string& player1_name, const std::string& player2_name)
	:player1_name(player1_name), player2_name(player2_name) 
{}

// displays the board in its current state in output stream
void const TicTacToe::Game::display_board() {
	system("CLS");																				// clear the window
	std::cout << player1_name << ": cross" << std::endl
		<< player2_name << ": nought" << std::endl
		<< "Current board state: " << std::endl << std::endl;
	for (int i = 0; i < board_size; ++i)														// for every row (board_size defined in header file)
	{
		for (int j = 0; j < board_size; ++j) {													// for every column
			if (board[i][j] == player1_mark) {
				std::cout << 'X';																// crosses
			}
			else if (board[i][j] == player2_mark) {
				std::cout << 'O';																// noughts
			}
			else {
				std::cout << '-';																// empty fields
			}
		}
		std::cout << std::endl;																	// for clarity
	}
}

/* 
prompts a player move
Arguments: int player number (1 or 2)
*/
void TicTacToe::Game::player_move(int player) {
	int row, column;
	if (player == 1) {																			// which players turn is it?
		std::cout << player1_name << ", it's your turn. First input number of row, " <<
			"then number of column where you want your mark to be." << std::endl;
	}
	else {
		std::cout << player2_name << ", it's your turn. First input number of row, " <<
			"then number of column where you want your mark to be." << std::endl;
	}
	std::cin >> row >> column;
	if ((row < 1) || (row > 3) || (column < 1) || (column > 3)) {								// input data validation - is out of range of board?
		std::cout << "Invalid coordinates. Both row and column numbers are between 1 and 3" << std::endl;
		TicTacToe::Game::player_move(player);													// ask for coords again
		return;
	}
	--row;																						// -1 to compensate for arrays starting at 0, humans count from 1
	--column;
	if (!(board[row][column] == TicTacToe::mark::empty)) {										// input data validation - is the space on the board already marked?
		std::cout << "Invalid coordinates. This space on the board is already marked." << std::endl;
		TicTacToe::Game::player_move(player);													// ask for coords again
		return;
	}
	if (player == 1) {
		board[row][column] = player1_mark;											
	}
	else {
		board[row][column] = player2_mark;
	}
}

/*
checks it there's a winner
Outputs: a boolean, true means game's over
*/
bool const TicTacToe::Game::check_for_threes() {
	// check rows
	for (int i = 0; i < board_size; ++i) {
		if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) &&						// check if three consecutive spaces are the same AND
			(board[i][0] == player1_mark || board[i][0] == player2_mark)) {						// they are either noughts or crosses
			return true;
		}
	}
	// check columns
	for (int i = 0; i < board_size; ++i) {
		if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) &&						// check if three consecutive spaces are the same AND
			(board[0][i] == player1_mark || board[0][i] == player2_mark)) {						// they are either noughts or crosses
			return true;
		}
	}
	// check diagonals
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) &&							// check if three consecutive spaces are the same AND
		(board[0][0] == player1_mark || board[0][0] == player2_mark)) {							// they are either noughts or crosses
		return true;
		}
	return false;
}

/*
Asks if user wants to play another game, if so resets the board
Arguments: winning player as an int, 1 - player1, 2 - player2
*/
void TicTacToe::Game::handle_game_end(int winner) {
	if (winner == 1) {
		std::cout << player1_name << " ,you won. Do you want to play another game? (1 for y/0 for n)" << std::endl;
	}
	else {
		std::cout << player2_name << " ,you won. Do you want to play another game? (1 for y/0 for n)" << std::endl;
	}
	bool continue_game;
	std::cin >> continue_game;
	if (continue_game) {																		// if player wants to continue game
		for (int i = 0; i < board_size; ++i) {													// reset all fields to empty
			for (int j = 0; j < board_size; j++) {
				board[i][j] = TicTacToe::mark::empty;
			}
		}
		TicTacToe::Game::display_board();														// display the freshly emptied board
	}
	else {
		exit(0);																				// else close the program
	}
}

