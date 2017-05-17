// This will let the function know about the somethingElse function
// via the somethingElse header file which contains the prototype.
// and then when the program is put through the linker it links
// the prototype with the function itself.
#include "somethingElse.h"



// The function
void doSomething()
{
	int i = 9;

	doSomethingElse();


}