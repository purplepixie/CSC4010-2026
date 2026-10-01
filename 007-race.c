#include <stdio.h>
#include <omp.h>

int main() 
{
    int counter = 0;
    #pragma omp parallel
    {
        int tc = counter;
        //printf("Hello from thread %d my tc is %d\n", omp_get_thread_num(), tc);
        tc++;
        counter = tc;
    }

    printf("The final counter value is %d\n", counter);
    
    return 0;
}