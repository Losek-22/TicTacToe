#pragma once
#include <iostream>

// size of the board (board size by board size), declared here because can't declare constexpr outside this file
extern constexpr int board_size{ 3 };

namespace TicTacToe {

	enum class mark { empty = 0, cross = 1, nought = 2 };											// types of available board marks for code clarity

	class Game {
	private:
		mark board[board_size][board_size] = {mark::empty};											// initialise board with empty fields
		std::string player1_name;
		std::string player2_name;
	public:
		Game(const std::string&, const std::string&);												// initialise player names
		void const display_board();																	// displays the board in its current state in output stream
		bool const check_for_threes();																// check if there's a winner
		void handle_game_end(int);																	// asks if user wants to play another game, if so resets the board
		void player_move(int);																		// ask for a new mark on the board
	};
	Game begin_game();																				// welcomes players and gets playernames from is
}

// global constants for marks used by players
extern const TicTacToe::mark player1_mark;
extern const TicTacToe::mark player2_mark;