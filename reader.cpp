#include <iostream>
#include <unistd.h>
#include "ring.h"

int main(){

	Ring ring (5);

	int next;
	while(true){
		usleep(500000);
		next = ring.getNext();
		std::cout << "Read " << next << std::endl;
	}
}

