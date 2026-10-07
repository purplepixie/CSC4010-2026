#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    omp_set_num_threads(6);
    #pragma omp parallel 
    {
        printf("Hello from thread %d in main region\n",omp_get_thread_num());
        #pragma omp single 
        {
            printf("Hello from thread %d in single, sleeping for 2 seconds\n",omp_get_thread_num());
            sleep(2);
            printf("Thread %d in single has finished sleeping\n",omp_get_thread_num());
        }
      printf("Thread %d at end of first single region\n",omp_get_thread_num());

      #pragma omp single nowait
        {
            printf("Hello from thread %d in second single, sleeping for 2 seconds\n",omp_get_thread_num());
            sleep(2);
            printf("Thread %d in single has finished sleeping\n",omp_get_thread_num());
        }
      printf("Thread %d at end of second single region\n",omp_get_thread_num());
    }

    printf("Parallel region finished\n");

    
    return 0;
}