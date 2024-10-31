#include <iostream>
#include "TicTacToe.h"

// There are 8 possible combinations to win tic tac toe
// 1) First row is filled
// 2) Second row is filled
// 3) Third row is filled
// 4) First column is filled
// 5) Second column is filled
// 6) Third column is filled
// 7) Left to right diagonal is filled
// 8) Right to left diagonal is filled
// Finally, on turn 8 an unresolved game is a tie
bool TicTacToe::IsGameOver() const {

	if (m_currTurn == 8) { // put checks for if the player is a winner here. move this check to an elseif. remember to set the winner based on who made the game winning move (0, 1, or 2).
		return true;
	}

	return false;
}

void TicTacToe::TakeTurn() {
	int newMarkerLocation = -1;

	// Allow the current player to take a turn (ensuring the spot is in-range and free)
	std::cout << "Enter a spot (1-9) where you'd like to place your marker: ";
	std::cin >> newMarkerLocation;
	while (newMarkerLocation < 1 || newMarkerLocation > 9 || m_board[newMarkerLocation] == m_player0Marker || m_board[newMarkerLocation] == m_player1Marker) {
		std::cout << "\nSorry! Your input was invalid. Please try another space.\n";
		std::cout << "Enter a spot (1-9) where you'd like to place your marker: ";
		std::cin >> newMarkerLocation;
	}

	// Switch the active player
	if (m_currPlayer == 0) {
		m_currPlayer = 1;
	}
	else {
		m_currPlayer = 0;
	}

	m_currTurn++;
}

void TicTacToe::Display() const {
	std::string boardOffset = "     "; // how many spaces to shift the board

	// Display the board
	std::cout << "\n\nBoard State:\n\n";
	std::cout << boardOffset << m_board[0] << "  |  " << m_board[1] << "  |" << m_board[2] << " \n";	// row 1
	std::cout << boardOffset << "--------------\n";
	std::cout << boardOffset << m_board[3] << "  |  " << m_board[4] << "  |" << m_board[5] << " \n";	// row 2
	std::cout << boardOffset << "--------------\n";
	std::cout << boardOffset << m_board[6] << "  |  " << m_board[7] << "  |" << m_board[8] << " \n";	// row 3
	std::cout << "\n";
	
	// Indicate whose turn it is. If the game has a winner, then display the winner instead.
	std::cout << "Player " << m_currPlayer+1 << " it's your turn!\n\n";
}