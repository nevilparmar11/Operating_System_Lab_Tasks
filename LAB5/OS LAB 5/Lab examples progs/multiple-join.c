#include<stdio.h>
#include<pthread.h>


void * f1()
{
	printf("Hello from thread 1\n");
}

void * f2()
{
	printf("Hello from thread 2\n");
}

int main()
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL , f1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL , f2, NULL);
	pthread_join(t2, NULL);
	printf("Parent (Here main thread, i.e main method) Thread joins\n");
	// pthread_join(t1, NULL);
	
	return 0 ;
}

/*

Output:
Hello from thread 1
Hello from thread 2
Thread joins


it waits child thread t1 to complete, and then the main thread will be executed. 




EXTRA:
	pthread_create(&t1, NULL , f1, NULL);
	pthread_create(&t2, NULL , f2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	In this case, 2 threads might dispatch in diff orders based on the created thread pool in the system.


*/