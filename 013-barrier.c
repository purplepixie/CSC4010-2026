#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL));
    #pragma omp parallel
    {
        int s = rand() % 5;
        printf("Thread %d sleeping for %d seconds\n", omp_get_thread_num(), s);
        sleep(s);
        printf("Thread %d finished sleeping\n", omp_get_thread_num());

        #pragma omp barrier
        printf("I want this to happen after all the sleeping has finished\n");
    }

    printf("Parallel region finished\n");
    
    return 0;
}