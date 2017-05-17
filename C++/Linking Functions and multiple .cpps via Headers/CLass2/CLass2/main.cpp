// these two declaration's tell main() what doSomething() and 
// doSomethingElse() functions are via linking the functions 
// though the headers 
#include "Something.h"
#include "somethingElse.h"

//------------------------------------------
// Prototypes
//-------------------------------------------

//void doSomethingElse();
//void doSomething();
//----------------------------------------------

//
// Function definitions
//



int main()
{
	doSomething();
	doSomethingElse();
}