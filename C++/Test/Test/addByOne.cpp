
#include <iostream>
//=================================================================
// Linking the "multiplyByTwo.h" which in turn links the functions 
// within multiplyByTwo
//=================================================================
#include "multiplyByTwo.h"
//=================================================================
// This grabs the inital number from Main.cpp and adds by 1
// Then calls the function multiplyByTwo from the .cpp file 
// which it can be linked because of including the header file.
//=================================================================
int addByOne(int number)
	{
		number += 1;
	

		number = multiplyByTwo(number);
	
//=================================================================
// Return this number so that it can be used for the final number.
//=================================================================
		return number;

	}