#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL));
    omp_set_num_threads(10);
    #pragma omp parallel 
    {
        int s = rand() % 5;
        printf("Thread %d sleeping for %d seconds\n", omp_get_thread_num(), s);
        //sleep(s);
        //printf("Thread %d finished sleeping\n", omp_get_thread_num());

        #pragma omp for schedule(dynamic)
        for(int i=0; i<200; ++i)
        {
            printf("Thread %d sleeping for %d seconds\n", omp_get_thread_num(), s);
            sleep(s);
            //printf("i=%d in thread %d\n",i,omp_get_thread_num());
        }

        printf("All threads finished\n");
    }

    printf("Parallel region finished\n");

    
    return 0;
}