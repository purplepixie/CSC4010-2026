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

        #pragma omp sections
        {

            #pragma omp section 
            {
                printf("Hello from thread %d in section, sleeping for 2 seconds\n",omp_get_thread_num());
                sleep(2);
                printf("Thread %d in single has finished sleeping\n",omp_get_thread_num());
            }
      

            #pragma omp section
            {
                printf("Hello from thread %d in second section\n",omp_get_thread_num());
                //sleep(2);
                //printf("Thread %d in single has finished sleeping\n",omp_get_thread_num());
            }
        }
        printf("Thread %d has reached end of sections\n",omp_get_thread_num());
    }

    printf("Parallel region finished\n");

    
    return 0;
}