#include<stdio.h>
#include<pthread.h>

int count = 0 ;

// Global mutex param shared by all the threads of this program
pthread_mutex_t m1  = PTHREAD_MUTEX_INITIALIZER;

void * f1()
{
	// put mutex lock at the start of critical section
	pthread_mutex_lock(&m1);
	count++;
	printf("Count = %d\n", count);
	pthread_mutex_unlock(&m1);
	// put mutex unlock at the end of critical section

}

int main()
{
	pthread_t t[5];
	for (int i = 0; i < 5; ++i)
	{
		pthread_create(&t[i], NULL , f1, NULL);
	}

	for (int i = 0; i < 5; ++i)
	{
		pthread_join(t[i], NULL);
	}

	printf("Parent (Here main thread, i.e main method) Thread joins\n");
	
	return 0 ;
}
