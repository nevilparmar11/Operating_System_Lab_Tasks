/// Prog 1 to mimic the behaviour of mkfifo in linux
// It reads input from the user and write it into the created pipe
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<stdio.h>

int main() 
{ 
	int fd; 

	// FIFO file path in the same directory of the program
	char * myfifo = "./customFifo"; 

	// Creating the named file(FIFO) 
	mkfifo(myfifo, 0666); 

	char  buffer[80]; 
	while (1) 
	{ 
		// Open FIFO for write only 
		fd = open(myfifo, O_WRONLY); 

		// Take an input buffering from user. 
		// 80 is maximum length 
		fgets(buffer, 80, stdin); 

		// Write the input buffering on FIFO 
		// and close it 
		write(fd, buffer, strlen(buffer)+1); 
		close(fd); 
	} 
	return 0; 
} 
