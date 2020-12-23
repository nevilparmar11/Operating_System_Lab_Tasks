#include<unistd.h>
#include<stdio.h>

int main()
{
	int pipefd[2];
	int secondpipefd[2];
	
	int err = pipe(pipefd);
	if(err!=0)
		printf("Error creating a file.\n");
	else
		printf("pipefd0 : %d\tpipefd1 : %d\n", pipefd[0],pipefd[1]);
	
	int err1 = pipe(secondpipefd);
	if(err1!=0)
		printf("Error creating a file.\n");
	else
		printf("secondpipefd0 : %d\tsecondpipefd1 : %d\n", secondpipefd[0],secondpipefd[1]);
	
	
	return 0;
}

/*

Output:
3 4
5 6

because 0 1 2 are stdin stdout stderr
so they are reserverd and other can be accessed by the process.
although, this values are not fixed for all the time. System might take appropriate action and can assign the avaialble resources.i.e pipes here.
*/