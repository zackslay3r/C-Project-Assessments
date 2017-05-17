#include "Functions.h"

#include<iostream>
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