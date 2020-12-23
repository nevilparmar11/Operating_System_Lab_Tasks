#include<stdio.h>
#include<unistd.h>
extern char **environ;
int main()
{
	printf("before\n");
	execl("/bin/ls","~/Desktop/oslab6",NULL);

	// not reachable code
	printf("after");
	return 0;
}

/*
 here the after will not be printed , 
 because the original process image is vanished from the memory and hence the prog is not there
*/