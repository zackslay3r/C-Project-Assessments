//=================================================================
// Include <iostream> for input and output
// and Include header files to link cpps.
//=================================================================
#include <iostream>
#include "addByOne.h"
#include "multiplyByTwo.h"
#include "Divide.h"

int main()
{
	//=================================================================
	//Declaring an inital number that can be for an inputted number
	//=================================================================
		int number;
	//=================================================================
	// And this number is used for the final result
	//=================================================================
		int dummy;

		char divide;
	
	//=================================================================
	// This recieves the input for the inital number.
	//=================================================================
		std::cout << "Please insert a number";
		std::cin >> number;
	
	//=================================================================
	// This makes the final number by making it equal what the
	// inital number is plus 1 (via the first function) 
	// times 2 (by the function linked within the first function)
	//=================================================================
		dummy = addByOne(number);
	
	
	//=================================================================
	//Show the output to the user
	//=================================================================
	std::cout << "Your new number is now " << dummy;
	
	std::cout << "Do you want to divide this number? ";
	std::cin >> divide;
	if (divide == 'y')
	{
		int DivideBy;
		std::cout << "What number would you like to divide by? ";
		std::cin >> DivideBy;

		dummy = Divide(dummy, DivideBy);
		std::cout << "Your new number is now " << dummy;
	}
	
	
	
	return 0;
	
	
	
	
	
}
