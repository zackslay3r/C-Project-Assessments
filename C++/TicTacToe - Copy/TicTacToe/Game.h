// This is the header file
// It contains all variables in a class and prototypes for functions.

#pragma once
class Game
{
	const int ROWS = 3;
	const int COLUMMS = 3;
	char playerOne = 'X';
	char playerTwo = 'O';
	char currPlayer;
	int rowSelected = 0;
	int colummSelected = 0;
	bool winner = false;
	// counter to determine the players turn and then PlayerTurn gets set based on counter.
	int counter = 0;
	int playerTurn = 0;

	// This variable checks if a turn is valid. 
	bool validTurn = false;

	// stores the value of who the Winning player is.
	int winningPlayer = 0;
	void squareCheck();
	void winnerCheck();

	
	//This is the destructor.
	~Game()
;}




;

