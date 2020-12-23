// simple calc

#include<stdio.h>
#include<pthread.h>
#include<time.h>

struct nums
{
	int x;
	int y;
};

void *add(void *numsref)
{
	printf("Add: %d\n", ((struct nums*)numsref)->x + ((struct nums*)numsref)->y);
	return NULL;
}

void *sub(void *numsref)
{
	printf("Sub: %d\n", ((struct nums*)numsref)->x - ((struct nums*)numsref)->y);
	return NULL;
}

void *mul(void *numsref)
{
	printf("Mul: %d\n", ((struct nums*)numsref)->x * ((struct nums*)numsref)->y);
	return NULL;
}

void *div(void *numsref)
{
	printf("Div: %d\n", ((struct nums*)numsref)->x / ((struct nums*)numsref)->y);
	return NULL;
}

int main()
{	
	// Calculate the time taken by fun() 
    clock_t t; 
    t = clock(); 
    
	int i;	
		
	struct nums n;
	n.x = 10;
	n.y = 20;
	
	pthread_t threads[4];
	
	// array of function pointers
	void * f[4];
	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	
	for(i=0;i<4;i++)
	{
		pthread_create(&threads[i],NULL,f[i],&n);
	}
	
	for(i=0;i<4;i++)
	{	
		pthread_join(threads[i],NULL);
	}
	
	printf("I am the last line in main.\n");


	t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Program took %f seconds to execute \n", time_taken);

	return 0;
}