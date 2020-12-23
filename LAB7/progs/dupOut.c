#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h> 
#include<fcntl.h> 

int main() 
{ 
	int file_desc = open("./test.txt",O_CREAT^O_WRONLY^S_IRWXU); 

	if(file_desc < 0){
		printf("File descriptor creation failed !\n");
		return 0;
	}


	printf("Before\n");	
	dup2(file_desc, 1) ; 
	printf("After\n");	
	return 0; 
} 
