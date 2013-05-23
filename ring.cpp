#include <iostream>
#include "ring.h"

// If we initialise vars here, they become shared (static).

int Ring::getNext()
{
	i = (i + 1) % SIZE;
	return aptr[i];
}

void Ring::setNext(int v)
{
	i = (i + 1) % SIZE;
	aptr[i] = v;
	std::cout << "Set index " << i << " to " << v << std::endl;
}
