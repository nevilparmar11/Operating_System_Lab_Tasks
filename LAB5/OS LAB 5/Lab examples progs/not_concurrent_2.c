#include<stdio.h>
#include<pthread.h>

int count = 0 ;

void * f1()
{
	count++;
	printf("Count = %d\n", count);
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
