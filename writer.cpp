#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "ring.h"

int main(){

	Ring ring (5);

	int rdm;
	while(true){
		usleep(3000000);
		rdm = rand() % 100;
		ring.setNext(rdm);
	}
}

