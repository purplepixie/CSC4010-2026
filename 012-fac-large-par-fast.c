#include <stdio.h>
#include <omp.h>

int main() 
{
    int length = 500000;
    unsigned long long n[length];
    unsigned long long fac[length];

    for(int i=0; i<length; ++i)
    {
        n[i] = 65;
        fac[i] = 1;
    }

    #pragma omp parallel for
    for(int x=0; x<length; ++x)
    {
        unsigned long long tmpfac = 1;
        for(unsigned long long i=n[x]; i>=2; --i)
        {
            tmpfac *= i;
        }
        fac[x] = tmpfac;
    }
    
    printf("The factorial of %llu is %llu\n", n[0], fac[0]);
    
    return 0;
}