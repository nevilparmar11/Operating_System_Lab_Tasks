#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
	
	char *temp[] = {NULL,"I am ","a execv process",NULL};

	temp[0]="hello";
	execv("hello",temp);

	// This line will never get executed as the current process is replace by the newly created execv proces
	printf("error");
	return 0;

}