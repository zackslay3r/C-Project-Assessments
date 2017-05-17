#include <iostream>
#include "Board.h"

//Prototypes
//void squareCheck();
//void winnerCheck();


/*
// Variables 
// These are using to create the board.

const int ROWS = 3;
const int COLUMMS = 3;
char playerOne = 'X';
char playerTwo = 'O';
char currPlayer;


// These are used for which position the player selects.
int rowSelected = 0;
int colummSelected = 0;
bool winner = false;

// the standard board
char board[ROWS][COLUMMS] = { {'A','A','A'}, {'A','A','A'},{'A','A','A'} };

// counter to determine the players turn and then PlayerTurn gets set based on counter.
int counter = 0;
int playerTurn = 0;

// This variable checks if a turn is valid. 
bool validTurn = false;

// stores the value of who the Winning player is.
int winningPlayer = 0;

// Functions
*/

// Variables
char board[ROWS][COLUMMS] = { { 'A','A','A' },{ 'A','A','A' },{ 'A','A','A' } };
void PlayerInput(int playerTurn)
{
	std::cout << "Please player " << playerTurn << " make your turn!";
	std::cout << std::endl;
	std::cout << "Please select which row you would like to pick. 1-3";
	std::cout << std::endl;
	std::cin >> rowSelected;
	std::cout << "Please select which columm you would like to pick. 1-3";
	std::cout << std::endl;
	std::cin >> colummSelected;



}

/*
void squareCheck()
{
	// while ValidTurn is false, give the user error messages unless they make a 
	//valid choice.
	while (validTurn == false)
	{
		// if they have selected a square that has already been selected
		if (board[rowSelected][colummSelected] != 'A')
		{
			std::cout << "Your choice of sqaure is invalid as a player has already selected a sqaure";
			std::cout << std::endl;
			std::cout << "please select another.";
			std::cout << std::endl;
			break;
		}





		// if the user pick is outside the game board
		// display this error
		if (rowSelected > ROWS || colummSelected > COLUMMS || rowSelected < 0 || colummSelected < 0)
		{
			std::cout << "Your choice is invalid as you have selected outside the board.";
			std::cout << std::endl;
			std::cout << "Please select a valid square.";
			break;


		}
		// if the square is empty, then fill it and confirm that a valid turn has been made.
		if (board[rowSelected][colummSelected] == 'A')
		{
			
			board[rowSelected][colummSelected] = currPlayer;
			
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLUMMS; j++)
				{
					std::cout << board[i][j];
				}
				std::cout << std::endl;
				validTurn = true;
				counter++;
			}

		}
	}
	

}
*/
void winnerCheck()
{
	// Testing rows
	
	for (int i = 0; i < ROWS; i++)
	{
	int total = 0;
		for (int j = 0; j < COLUMMS; j++)
		{
			total += board[i][j];
		}


		// Player 1 win condition
		if (total == 264)
		{
			winner = true;
			winningPlayer = 1;
			break;
		}

		// Player 2 Win Condition.
		if (total == 237)
		{
			winner = true;
			winningPlayer = 2;
			break;

		}

	}




	//Testing Columms
	
	for (int i = 0; i < COLUMMS; i++)
	{ 
	int total = 0;	
		for (int j = 0; j < ROWS; j++)
		{
			total += board[i][j];
		}


		// Player 1 win condition
		if (total == 264)
		{
			winner = true;
			winningPlayer = 1;
			break;
		}

		// Player 2 Win Condition.
		if (total == 237)
		{
			winner = true;
			winningPlayer = 2;
			break;

		}
	}

	// Testing for [0][0], [1][1], [2][2]
	int total = 0;
	for (int i = 0; i < COLUMMS; i++)
	{
		
		total += board[i][i];
	

		// Player 1 win condition
		if (total == 264)
		{
			winner = true;
			winningPlayer = 1;
			break;
		}

		// Player 2 Win Condition.
		if (total == 237)
		{
			winner = true;
			winningPlayer = 2;
			break;

		}

	}

	// Testing for [2][0], [1][1],[0][2]

	for (int i = 2; i >= 0; i--)
	{
		total = 0;
		for (int j = 0; j <= 2; j++)
		{
			total += board[i][j];
			i--;
		}


		// Player 1 win condition
		if (total == 264)
		{
			winner = true;
			winningPlayer = 1;
			break;
		}

		// Player 2 Win Condition.
		if (total == 237)
		{
			winner = true;
			winningPlayer = 2;
			break;

		}
	}





}



int main()
{
	// While there is no winner, set ValidTurn to false 
	// then determine which players turn it is
	// then ask the player for input.
	// followed by running the SquareCheck() function and
	// the WinnerCheck() function to determine who the winning player.
	while (winner != true)
	{
		validTurn = false;
		if (counter % 2 == 0)
		{
			playerTurn = 1;
			currPlayer = playerOne;
		}
		else
		{
			playerTurn = 2;
			currPlayer = playerTwo;
		}
		

		/*
		std::cout << "Please player " << playerTurn << " make your turn!";
		std::cout << std::endl;
		std::cout << "Please select which row you would like to pick. 1-3";
		std::cout << std::endl;
		std::cin >> rowSelected;
		std::cout << "Please select which columm you would like to pick. 1-3";
		std::cout << std::endl;
		std::cin >> colummSelected;
		*/
		PlayerInput(playerTurn);
		rowSelected--;
		colummSelected--;
		squareCheck();
		winnerCheck();
		
	}


	//
	
	// Show who has won or in the case that it is a draw, display it.
	if (winningPlayer == 1)
	{
		std::cout << "Player One Wins!";
	}
	if (winningPlayer == 2)
	{
		std::cout << "Player Two Wins!";
	}
	if (winningPlayer == 0)
	{
		std::cout << "The game is a draw.";
	}
}