#include <stdio.h>
#include <stdlib.h>

int main ()
{
   FILE *plik = fopen("liczby.txt", "r");
   int n;
   double suma=0;
   const int  ilosc=10;
   for(int i=0,n;i<ilosc;i++)
   {
       fscanf(plik, "%d", &n);
       suma=suma+n;
       //printf("%d \n", n);
   }

   printf("suma : %f\n",suma);
   printf("srednia : %f",suma/ilosc);

   fclose(plik);
  return 0;
}
