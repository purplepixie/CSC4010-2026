#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int i=10, j=10;

    omp_set_num_threads(6);
    #pragma omp parallel default(none) shared(i) firstprivate(j)
    {
        #pragma omp atomic
        ++i;
        ++j;
        printf("In thread %d i=%d j=%d\n",omp_get_thread_num(),i,j);
    }

    printf("Finally i=%d and j=%d\n",i,j);

    
    return 0;
}