#include <stdio.h>
#include <omp.h>

int main() 
{
    #pragma omp parallel
    {
        printf("Hello\n");
        
        #pragma omp parallel
        printf("World!\n");
    }
    printf("The middle\n");

    #pragma omp parallel
    printf("Goodbye cruel world!\n");
    return 0;
}