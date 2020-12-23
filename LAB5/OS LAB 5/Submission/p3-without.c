// simple calc

#include<stdio.h>
#include<pthread.h>
#include<time.h>

struct nums
{
	int x;
	int y;
};

void add(struct nums numsref)
{
	printf("Add: %d\n", (numsref).x + (numsref).y);
}

void sub(struct nums numsref)
{
	printf("Sub: %d\n", (numsref).x - (numsref).y);
}

void mul(struct nums numsref)
{
	printf("Mul: %d\n", (numsref).x * (numsref).y);
}

void div(struct nums numsref)
{
	printf("Div: %d\n", (numsref).x / (numsref).y);
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
	
	
	add(n);
	sub(n);
	mul(n);
	div(n);

	printf("I am the last line in main.\n");


	t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Program took %f seconds to execute \n", time_taken);

	return 0;
}