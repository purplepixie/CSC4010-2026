#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int i;

    printf("** ATOMIC **\n");
    i=10;
    #pragma omp parallel default(none) shared(i)
    {
        #pragma omp atomic
        i+=1;
        printf("i=%d in thread %d\n",i,omp_get_thread_num());
    }
    printf("After loop i=%d\n",i);

    printf("** REDUCTION **\n");
    i=10;
    #pragma omp parallel default(none) reduction(+:i)
    {
        i+=1;
        printf("i=%d in thread %d\n",i,omp_get_thread_num());
    }
    printf("After loop i=%d\n",i);

    printf("** MANUAL **\n");
    i=10;
    #pragma omp parallel default(none) shared(i) 
    {
        int tmpi = 0;
        tmpi+=1;
        printf("i=%d in thread %d\n",tmpi,omp_get_thread_num());
        #pragma omp atomic
        i += tmpi;
    }
    printf("After loop i=%d\n",i);
    
    return 0;
}