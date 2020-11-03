#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool czypierwsze(int a)
{
    if(a<2) return false;
    if(a%2==0 && a!=2) return false;
    for(int i=3;i*i<=a;i=i+2)
    {
        if(a%i==0) return false;
    }
    return true;
}

int main()
{
    return 0;
}
