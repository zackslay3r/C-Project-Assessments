// This will let the function know about the doSomething function
// via the something header file which contains the prototype.
#include "Something.h"

void doSomethingElse()
{
	int i = 0;

	doSomething();
}