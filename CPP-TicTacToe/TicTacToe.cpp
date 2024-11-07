#include <iostream>
#include "TicTacToe.h"

bool TicTacToe::IsGameOver() const {
	// get the marker of the last person who placed one (the opposite of the current player since this is called after the TakeTurn method)
	std::string checkedPlayer;
	char checkedMarker = '\0';

	if (m_currPlayer == 0) {
		checkedMarker = m_player1Marker;
		checkedPlayer = "Player 2";
	}
	else {
		checkedMarker = m_player0Marker;
		checkedPlayer = "Player 1";
	}

	// check if the last player who went has placed a winning marker
	if ( 
		   (m_board[0] == checkedMarker && m_board[1] == checkedMarker && m_board[2] == checkedMarker) // First row is filled
		|| (m_board[3] == checkedMarker && m_board[4] == checkedMarker && m_board[5] == checkedMarker) // Second row is filled
		|| (m_board[6] == checkedMarker && m_board[7] == checkedMarker && m_board[8] == checkedMarker) // Third row is filled
		|| (m_board[0] == checkedMarker && m_board[3] == checkedMarker && m_board[6] == checkedMarker) // First column is filled
		|| (m_board[1] == checkedMarker && m_board[4] == checkedMarker && m_board[7] == checkedMarker) // Second column is filled
		|| (m_board[2] == checkedMarker && m_board[5] == checkedMarker && m_board[8] == checkedMarker) // Third column is filled
		|| (m_board[0] == checkedMarker && m_board[4] == checkedMarker && m_board[8] == checkedMarker) // Left to right diagonal is filled
		|| (m_board[2] == checkedMarker && m_board[4] == checkedMarker && m_board[6] == checkedMarker) // Right to left diagonal is filled
	) {
		std::cout << checkedPlayer << " has won the game!\n\n";
		return true;
	}
	else if (m_currTurn == 9) { // The entire board has been filled
		std::cout << "The game has ended in a tie!\n\n";
		return true;
	}

	return false; // if we get here then nobody has satisfied a win condition yet, nor has a tie occured
}

void TicTacToe::TakeTurn() {
	int newMarkerLocation = -1;

	// Allow the current player to take a turn (ensuring the spot is in-range and free)
	std::cout << "Player " << m_currPlayer + 1 << " it's your turn!\n\n";
	std::cout << "Enter a spot (1-9) where you'd like to place your marker: ";
	std::cin >> newMarkerLocation;
	while (newMarkerLocation < 1 || newMarkerLocation > 9 || m_board[newMarkerLocation - 1] == m_player0Marker || m_board[newMarkerLocation - 1] == m_player1Marker) {
		std::cout << "\nSorry! Your input was invalid. Please try another space.\n";
		std::cout << "Enter a spot (1-9) where you'd like to place your marker: ";
		std::cin >> newMarkerLocation;
	}

	// Update the board
	if (m_currPlayer == 0) { // player 1 placed the marker
		m_board[newMarkerLocation - 1] = m_player0Marker;
	}
	else {					// player 2 placed the marker
		m_board[newMarkerLocation - 1] = m_player1Marker;
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
	std::string boardOffset = "     "; // how many spaces to shift the board to the right

	// Display the board
	std::cout << "\n\nBoard State:\n\n";
	std::cout << boardOffset << " " << m_board[0] << " |  " << m_board[1] << "  | " << m_board[2] << " \n";	// row 1
	std::cout << boardOffset << "-------------\n";
	std::cout << boardOffset << " " << m_board[3] << " |  " << m_board[4] << "  | " << m_board[5] << " \n";	// row 2
	std::cout << boardOffset << "-------------\n";
	std::cout << boardOffset << " " << m_board[6] << " |  " << m_board[7] << "  | " << m_board[8] << " \n";	// row 3
	std::cout << "\n";
}