#include <stdio.h>
#include <stdlib.h>

void centernumber(int liczba, int dlugosc)
{
    printf("|");
    for(int i=0;i<=dlugosc;i++)
    {
        if(i==(dlugosc/2)) printf("%d",liczba);
        else printf(" ");
    }
    printf("|");
}
int main()
{
    centernumber(6,77);  //example
    return 0;
}
