#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t[3];
    for(int i=0;i<3;i++)
    {
        scanf("%d",&t[i]);
    }
    for(int i=2;i>=0;i--)
    {
        printf("%d\n",t[i]);
    }
    return 0;
}
