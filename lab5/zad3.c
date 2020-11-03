#include <stdio.h>
#include <string.h>

int  podwojenie(int lic)
{
    return lic*2;
}
int main()
{
    printf("podaj liczbe: ");
    int liczba;

    scanf("%d",&liczba);
    printf("podwojona to:  %d\n",podwojenie(liczba));
    printf("oryginalna :  %d\n",liczba);
    return 0;
}
