#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    
    #pragma omp parallel 
    {
        printf("Hello from thread %d in main region\n",omp_get_thread_num());
        #pragma omp master 
        {
            printf("Hello from thread %d in master\n",omp_get_thread_num());
        }

        printf("All threads finished\n");
    }

    printf("Parallel region finished\n");

    
    return 0;
}