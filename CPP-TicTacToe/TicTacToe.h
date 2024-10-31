#pragma once

#include "Game.h"

class TicTacToe : public Game {
private:
	char m_board[9] = { ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '};		// The board holds a single whitespace (" ") if a space is free, or each respective player's mark.
	int m_currPlayer = 0;													// The current player (0 or 1)
	int m_currTurn = 0;														// Every time a mark is placed on the board, 1 turn has been taken
	int m_winner = -1;														// The winner can be player 0 or 1. The winner is 2 in the case of a tie. While the winner is -1, the game is on-going an a winner has yet to be resolved.
	char m_player0Marker = 'X';												// This represents player 0's markers on the board
	char m_player1Marker = 'O';												// This represents player 1's markers on the board
public:
	// Return true if the game is over, and false otherwise
	virtual bool IsGameOver() const;

	// Allow the current player to take their turn
	virtual void TakeTurn();

	// Display the current state of the game to the console window
	virtual void Display() const;
};