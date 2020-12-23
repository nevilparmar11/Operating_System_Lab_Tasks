#include<stdio.h>
#include<pthread.h>


void * f1()
{
	printf("Hello from thread\n");
}

int main()
{
	pthread_t t1;
	pthread_create(&t1, NULL , f1, NULL);
	pthread_join(t1, NULL);
	printf("Parent (Here main thread, i.e main method) Thread joins\n");
	// pthread_join(t1, NULL);
	
	return 0 ;
}

/*

Output:
Hello from thread
Thread joins


it waits for child thread t1 to complete, and then the main thread will be executed. 


*/