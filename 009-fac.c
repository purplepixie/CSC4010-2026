#include <stdio.h>


int main() 
{
    unsigned long long n = 65;
    unsigned long long fac = 1;

    for(unsigned long long i=n; i>=2; --i)
    {
        fac *= i;
    }
    
    printf("The factorial of %llu is %llu\n", n, fac);
    
    return 0;
}