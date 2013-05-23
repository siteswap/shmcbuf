#include <sys/shm.h>
#include <sys/stat.h>

class Ring
{	

	// At initialization, ring is given:
	// 4 bytes for SIZE
	// 4 bytes for aptr
	// At instantiation, we create an array on the heap, and repoint aptr.
	// If we knew the size of the array at initialization, it could be go on the stack but since we want it to be dynamic it must go on the heap.
	// If we created the array in the constructor, it gets lost when we exit the function.

	int SIZE; 
	// need to make static
	int i, segment_id;
	int *aptr;      // need to make static
	int IPC_PRIV;

public:
	Ring(int size) 
	{	
		SIZE = size;
		IPC_PRIV = 17268752;
		// get shared memory region for this
		segment_id = shmget(IPC_PRIV, 4*SIZE, IPC_CREAT | IPC_CREAT | S_IRUSR | S_IWUSR );
		std::cout << "Got, segment_id: " << segment_id << std::endl;
		aptr = (int*) shmat(segment_id, 0, 0);
		
		//aptr = new int[SIZE];
		// get shared memory region for this
		i = -1;
	}
	int getNext();
	void setNext(int v);
};
