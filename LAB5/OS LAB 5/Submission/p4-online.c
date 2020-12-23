# include <stdio.h>
# include <pthread.h>
#include<stdlib.h>

int MAT1[10][10];
int MAT2[10][10];
int MAT3[10][10];

int r1,c1,r2,c2;

void *multiply(void *);

int main()
{
    pthread_t tid;    
    int i,j,kCount;
    
    printf("Enter Number of Rows For Matrix 1 :");
    scanf("%d",&r1);
    
    printf("Enter Number of Columns For Matrix 1 :");
    scanf("%d",&c1);
    
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            MAT1[i][j] = rand() %10;
    
    
    printf("Enter Numer of Rows For Matrix 2 :");
    scanf("%d",&r2);
    
    printf("Enter Number of Columns For Matrix 2 :");
    scanf("%d",&c2);
    
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            MAT2[i][j] = rand() %10;
    
    if(c1!=r2)
    {
        printf("Multipication of Matrix not Possible !!!");
    }
    else
    {
        for(i=0;i<r1;i=i+2)
        {
            for(j=0;j<c2;j=j+2)
            {
                MAT3[i][j]=0;
            }
        }
        
        pthread_create(&tid,NULL,multiply,NULL);
        
        for(i=0;i<r1;i=i+2)
        {
            for(j=0;j<c2;j++)
            {
                for(kCount=0;kCount<c1;kCount++)
                {
                    MAT3[i][j]+=MAT1[i][kCount] * MAT2[kCount][j];
                }
            }
        }
        
        pthread_join(tid,NULL);
    }
    
    printf("\nMatrix 1 \n");
    
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d \t",MAT1[i][j]);
        }
        printf("\n");
    }    
    
    printf("\nMatrix 2 \n");
    
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d \t",MAT2[i][j]);
        }
        printf("\n");
    }    
    
    printf("\nMultipication of Matrix ...\n");
    
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d \t",MAT3[i][j]);
        }
        printf("\n");
    }    
    return 0;
}

void *multiply(void *para)
{
    int i,j,kCount;
    for(i=1;i<r1;i=i+2)
        {
            for(j=0;j<c2;j++)
            {
                for(kCount=0;kCount<c1;kCount++)
                {                    
                    MAT3[i][j]+=MAT1[i][kCount] * MAT2[kCount][j];
                }
            }
        }
        
    pthread_exit(NULL);
}