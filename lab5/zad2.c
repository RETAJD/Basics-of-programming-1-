#include <stdio.h>

int silnia (int n)
{
    if (n == 0) return 1;
    else return n*silnia(n-1);
}
int main()
{
    int liczba;
    printf("podaj liczbe: ");
    scanf("%d",&liczba);

    printf("silnia: %d\n",silnia(liczba));
    return 0;
}
