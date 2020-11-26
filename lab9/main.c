#include <stdio.h>
#include <stdlib.h>


char* tablica[25][33];
int czyjruch=0, punktybialy=0, punktyczarny=0;

void czyszczenietab()
{
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<33;j++)
        {
            tablica[i][j]=' ';
        }
    }
}

void plansza()
{
    for(int i=0;i<25;i++)
    {
        for(int j=0; j<33; j++)
        {
            if((j==0&&i!=0) || (j==32&&i!=0) ) tablica[i][j]='|';
            else if((i==0 || i==24)&&j!=0&&j!=32)tablica[i][j]='_';
            else if(j%4==0 && i!=0 ) tablica[i][j]='|';
            else if(i%3==0) tablica[i][j]='_';
            if(i==24 && j%4==0 ) tablica[i][j]='|';
        }
    }// ZROBIENIE PLANSZY 8X8 z okienkami itp
}
void wyswietlanie()
{
    int zmienna=65;
    printf(" ");
    for(int i=0;i<33;i++)
    {
        if(i==2 || i==6 || i==10 || i==14 || i==18 || i==22 || i==26 || i==30)
        {
            printf("%c",zmienna);
            zmienna++;
        }
        else printf(" ");
    }
    printf("\n");
    int polepion=1;
    for(int i=0;i<25;i++)
    {
        if(i==2 || i==5 || i==8 || i==11 || i==14 || i==17 || i==20 || i==23)
        {
            printf("%d",polepion);
            polepion++;
        }
        else printf(" ");

        for(int j=0;j<33;j++)
        {
            printf("%c",tablica[i][j]);
        }
        printf("\n");
    }
}// wyswietlanie pionkow
void ustawieniepionkow()
{
    tablica[23][2]='B';
    tablica[23][10]='B';
    tablica[23][18]='B';
    tablica[23][26]='B';

    tablica[20][6]='B';
    tablica[20][14]='B';
    tablica[20][22]='B';
    tablica[20][30]='B';

    tablica[17][2]='B';
    tablica[17][10]='B';
    tablica[17][18]='B';
    tablica[17][26]='B';

    tablica[2][6]='C';
    tablica[2][14]='C';
    tablica[2][22]='C';
    tablica[2][30]='C';

    tablica[5][2]='C';
    tablica[5][10]='C';
    tablica[5][18]='C';
    tablica[5][26]='C';

    tablica[8][6]='C';
    tablica[8][14]='C';
    tablica[8][22]='C';
    tablica[8][30]='C';
}// standardowe ustawienie poczatkowe pionkow

int poczx, poczy;
void wspolzednewyboru(char *pionek)
{
    if(pionek[0]=='A') poczy=2;
    if(pionek[0]=='B') poczy=6;
    if(pionek[0]=='C') poczy=10;
    if(pionek[0]=='D') poczy=14;
    if(pionek[0]=='E') poczy=18;
    if(pionek[0]=='F') poczy=22;
    if(pionek[0]=='G') poczy=26;
    if(pionek[0]=='H') poczy=30;

    poczx = pionek[1]*1  -48;
    if(poczx==1) poczx=2;
    else if(poczx==2) poczx=5;
    else if(poczx==3) poczx=8;
    else if(poczx==4) poczx=11;
    else if(poczx==5) poczx=14;
    else if(poczx==6) poczx=17;
    else if(poczx==7) poczx=20;
    else if(poczx==8) poczx=23;

   // printf("%d %d",poczx,poczy);  // przerabianie symbolu np A2 na wpolzedne w tablicy
}

void gdzieruszyc(int poczx,int poczy)
{
    char ruszenie[2];
    printf("podaj gdzie chcesz sie ruszyc: ");
    scanf("%s",&ruszenie);

    int ruchx,ruchy;
    if(ruszenie[0]=='A') ruchy=2;
    if(ruszenie[0]=='B') ruchy=6;
    if(ruszenie[0]=='C') ruchy=10;
    if(ruszenie[0]=='D') ruchy=14;
    if(ruszenie[0]=='E') ruchy=18;
    if(ruszenie[0]=='F') ruchy=22;
    if(ruszenie[0]=='G') ruchy=26;
    if(ruszenie[0]=='H') ruchy=30;

    ruchx= ruszenie[1]*1  -48;
    if(ruchx==1)      ruchx=2;
    else if(ruchx==2) ruchx=5;
    else if(ruchx==3) ruchx=8;
    else if(ruchx==4) ruchx=11;
    else if(ruchx==5) ruchx=14;
    else if(ruchx==6) ruchx=17;
    else if(ruchx==7) ruchx=20;
    else if(ruchx==8) ruchx=23;

   // printf("%d %d",ruchx,ruchy);

    if(czyjruch%2==0)
    {
        if(poczx-ruchx==3 && (poczy-ruchy==4 || poczy-ruchy == -4)  && (poczy>=2 && poczy<=30) && tablica[ruchx][ruchy]==' '  )
        {
            tablica[poczx][poczy]=' ';
            tablica[ruchx][ruchy]='B';
            system("cls");

        }
        // bicie zawodnik bialy
        else if( poczx-ruchx==6  && (poczy-ruchy==8 || poczy-ruchy == -8)    && (poczy>=2 && poczy<=30)  )
        {
            if(poczy>ruchy)
            {
                if(tablica[poczx-3][poczy-4]=='C')
                {
                    tablica[poczx][poczy]=' ';
                    tablica[ruchx][ruchy]='B';
                    tablica[poczx-3][poczy-4]=' ';
                    punktybialy++;
                    system("cls");
                }
            }
            else{
                 if(tablica[poczx-3][poczy+4]=='C')
                {
                    tablica[poczx][poczy]=' ';
                    tablica[ruchx][ruchy]='B';
                    tablica[poczx-3][poczy+4]=' ';
                    system("cls");
                    punktybialy++;
                }
            }
        }
        else gdzieruszyc(poczx,poczy);
    }
     if(czyjruch%2==1)
    {
        if(poczx-ruchx==-3 && (poczy-ruchy==4 || poczy-ruchy == -4)  && (poczy>=2 && poczy<=30) &&  tablica[ruchx][ruchy]==' '   )
        {
            tablica[poczx][poczy]=' ';
            tablica[ruchx][ruchy]='C';
            system("cls");
        }

        // bicie zawodnik czarny
        else if( poczx-ruchx==-6 && (poczy-ruchy==8 || poczy-ruchy == -8)    && (poczy>=2 && poczy<=30)  )
        {
            if(poczy>ruchy)
            {
                if(tablica[poczx+3][poczy-4]=='B') //lewo
                {
                    tablica[poczx][poczy]=' ';
                    tablica[ruchx][ruchy]='C';
                    tablica[poczx+3][poczy-4]=' ';
                    punktyczarny++;
                }
            }
            else{
                 if(tablica[poczx+3][poczy+4]=='B') // prawo
                {
                    tablica[poczx][poczy]=' ';
                    tablica[ruchx][ruchy]='C';
                    tablica[poczx+3][poczy+4]=' ';
                    punktyczarny++;
                }
            }
        }
        else gdzieruszyc(poczx,poczy);
    }
}  //sprawddzanie czy ruch jest dozwolony , oraz zbijanie

void ruchy()
{
    char pionek[2];
    if(czyjruch%2==0)
    {
        printf("Punkty bialy: %d\n",punktybialy);
        printf("Punkty czarny: %d\n",punktyczarny);
        printf("RUCH BIALEGO \n ");
        printf("podaj ktory pionek :  ");
        scanf("%s",&pionek);
        wspolzednewyboru(pionek);
        if(tablica[poczx][poczy]!='B')
        {
            while(tablica[poczx][poczy]!='B')
            {
                printf("podaj ktory pionek : ");
                scanf("%s",&pionek);
                wspolzednewyboru(pionek);
            }
        }
        gdzieruszyc(poczx,poczy);
    }
    if(czyjruch%2==1)
    {
        printf("Punkty bialy: %d\n",punktybialy);
        printf("Punkty czarny: %d\n",punktyczarny);
        printf("RUCH CZARNEGO \n ");
        printf("podaj ktory pionek : ");
        scanf("%s",&pionek);
        wspolzednewyboru(pionek);
        if(tablica[poczx][poczy]!='C')
        {
            while(tablica[poczx][poczy]!='C')
            {
                printf("podaj ktory pionek : ");
                scanf("%s",&pionek);
                wspolzednewyboru(pionek);
            }
        }
        gdzieruszyc(poczx,poczy);
    }
    czyjruch++;
} // sterowanie i przelaczanie urzytkownikow raz bialy raz czarny
void informacja()
{
    printf("DZIEN DOBRY, ZAPRASZAM DO ZAGRANIA W WARCABY! \n");
    printf("INSTRUKCJA: \n");
    printf("ZEBY WYBRAC PIONEK, KTORY CHCEMY PRZESUNAC NALEZY WPISAC NUMER : <A-H><1-8> (np. A2) \n");
    printf("NASTEPNIE WYBRAC MOZLIWOSC I EW. ZBICIE PRZECIWNIKA \n");
    printf("ZACZYNA KOLOR BIALY (B) \n");
    printf("POWODZENIA! \n");
}

int wygranaa=0;
void czywygrana()
{
    int iloscb=0;
    int iloscc=0;
    char *wygrany;
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<33;j++)
        {
            if(tablica[i][j]=='B') iloscb++;
            if(tablica[i][j]=='C') iloscc++;
        }
    }
            if(iloscb>0 &&iloscc==0)
            {
                wygrany="bialy";
                printf("KONIEC GRY !!! \n");
                printf("wygral: %s" ,wygrany);
                wygranaa++;

            }
                if(iloscc>0 &&iloscb==0)
            {
                wygrany="czarny";
                printf("KONIEC GRY !!! \n");
                printf("wygral: %s ",wygrany );
                wygranaa++;
            }
    }


int main()
{
    informacja();
    czyszczenietab();
    plansza();
    ustawieniepionkow();
    wyswietlanie();
    while(wygranaa==0)
    {
         ruchy();
         system("cls");
         wyswietlanie();
         czywygrana();

    }

    return 0;
}
