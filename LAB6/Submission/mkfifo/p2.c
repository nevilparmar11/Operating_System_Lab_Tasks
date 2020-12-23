// Prog 1 to mimic the behaviour of mkfifo in linux
// It reads from the created pipe by the first program and outputs on the terminal 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<stdio.h>

int main() 
{ 
	int fd; 

	// FIFO file path in the same directory of the prog
	char * myfifo = "./customFifo"; 

	// Creating the named file(FIFO) 
	mkfifo(myfifo, 0666); 

	char buffer[80]; 
	while (1) 
	{ 
		// First open in read only and read 
		fd = open(myfifo,O_RDONLY); 
		read(fd, buffer, 80); 

		// Print the read string and close 
		printf("%s", buffer); 
		close(fd); 

	} 
	return 0; 
} 
