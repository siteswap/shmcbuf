#-------------

CC=g++

#-------------


all: 
	$(CC) reader.cpp ring.cpp -o reader
	$(CC) writer.cpp ring.cpp -o writer

clean:
	rm -f reader writer ring.o
