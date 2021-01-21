#include <graphics.h>  // !
#include <fstream>
#include <iostream>
#include <conio.h>
#include <time.h>


using namespace std;

int x11=20,y11=20;  //+60
char ch;
int n=0;
int t[3][3];
int wspoli=0, wspolj=0;
int zmiennaczasowa1,zmiennaczasowa2;

void zerowanie()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            t[i][j]=0;
        }
    }
}

int czywygral()
{
    if(t[0][0]==t[1][0] && t[1][0]==t[2][0] && t[0][0]!=0) {line(50,10,50,250);    return 1; } // 1 kolumna
    if(t[0][1]==t[1][1] && t[1][1]==t[2][1] && t[1][1]!=0) {line(130,10,130,250);  return 1; } // 2 kolumna
    if(t[0][2]==t[1][2] && t[1][2]==t[2][2] && t[2][2]!=0) {line(210,10,210,250);  return 1; } // 3 kolumna
    if(t[0][0]==t[0][1] && t[0][1]==t[0][2] && t[0][0]!=0) {line(10,50,250,50);    return 1; } // 1 wiersz
    if(t[1][0]==t[1][1] && t[1][1]==t[1][2] && t[1][0]!=0) {line(10,130,250,130);  return 1; } // 2 wiersz
    if(t[2][0]==t[2][1] && t[2][1]==t[2][2] && t[2][0]!=0) {line(10,210,250,210);  return 1; } // 3 wiersz
    if(t[0][0]==t[1][1] && t[1][1]==t[2][2] && t[0][0]!=0) {line(10,10,250,250);   return 1; } // 1 ukos
    if(t[2][0]==t[1][1] && t[1][1]==t[0][2] && t[2][0]!=0) {line(10,250,250,10);   return 1; } // 2 ukos

    return 0;
}
void rysowanieplanszy()
{
   zmiennaczasowa1=clock();

   zerowanie();
   initwindow(700,400);
   rectangle(10,10,250,250);
   line(170,10,170,250);
   line(90,10,90,250);
   line(10,170,250,170);
   line(10,90,250,90);

    //rectangle(x22,y22,x22+60,y22+60);
    rectangle(x11,y11,x11+60,y11+60);
    //rectangle(x11,y11,x11+60,y11+60);
}


void tabela()
{
        initwindow(700,600);
        setcolor(WHITE);
        settextstyle(1,0,3);
        outtextxy(10,10,"TABELA WYNIKOW:");
        ifstream p1;
        ofstream p2;

        p2.open("wyniki.txt",ios::app);

        float czas=(zmiennaczasowa2-zmiennaczasowa1)/1000.0 ;


        p2<<czas<<endl;  // dodawanie wynikow
        p2.close();

        p1.open("wyniki.txt",ios::out|ios::app);
        string linia;
        int ruchtabeli=50;
        while(p1)
        {
            getline(p1,linia);
            if(linia=="") break;
            linia="wynik : "+linia + " sekund.";
            char* chr = const_cast<char*>(linia.c_str());  // konwersja string to char*

            settextstyle(1,0,1);
            outtextxy(10,ruchtabeli, chr);
            ruchtabeli=ruchtabeli+30;
        }
        settextstyle(1,0,1);
        outtextxy(280,ruchtabeli-30, "(obecny czas)");
        p1.close();
}

int czyremis()
{
    int suma1=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(t[i][j]==0) suma1++;
        }
    }
    if(suma1==0) return 1;
    else return 0;
}

int czytabela=0;
void kolkoikrzyzyk()
{
    rysowanieplanszy();
    while(1)
    {
        if(czywygral()==1 || czyremis()==1) {

                zmiennaczasowa2=clock();
                setcolor(WHITE);
                settextstyle(1,0,3);    //koncowe
                outtextxy(10,300,"Wcisnij N, zeby zagrac od nowa");
                outtextxy(10,330,"Wcisnij E, zeby zakonczyc");
                outtextxy(10,360,"Wcisnij T, zeby wpisac wynik do tabeli");
                    }

    if(czytabela==0)
        {
            if(n%2==0)
                {
                    setcolor(BLACK);
                    settextstyle(1,0,3);
                    outtextxy(270,10,"Gracz 2");
                    setcolor(WHITE);
                    settextstyle(1,0,3);
                    outtextxy(270,10,"Gracz 1");
                }
    else{
        setcolor(BLACK);
        settextstyle(1,0,3);
        outtextxy(270,10,"Gracz 1");
        setcolor(WHITE);
        settextstyle(1,0,3);
        outtextxy(270,10,"Gracz 2");
        }
}
        ch=getch();
        if(ch==13 && t[wspoli][wspolj]==0 && czytabela==0 )
        {

                        if(n%2==1 && (x11>10 && x11<250 && y11>10 && y11<250) )
                    {
                        //STAWIANIE krzyzykow
                        setcolor(LIGHTMAGENTA);
                        settextstyle(1,0,6);
                        outtextxy(x11,y11,"X");
                        rectangle(x11,y11,x11+60,y11+60);
                        setcolor(WHITE);
                        t[wspoli][wspolj]=1;
                    }
                    if (x11>10 && x11<250 && y11>10 && y11<250 && n%2==0 ){

                        //stawianie  kolek

                        setcolor(LIGHTCYAN);
                        settextstyle(1,0,6);
                        outtextxy(x11,y11,"O");
                        rectangle(x11,y11,x11+60,y11+60);
                        setcolor(WHITE);
                        t[wspoli][wspolj]=2;
                    }
            n++;
        }

        if(ch=='e' || ch=='E')
        {
            break;
        }
        if((ch=='N' || ch=='n')&& (czywygral()==1 || czyremis()==1))
        {
            rysowanieplanszy();
        }
        if((ch=='T' || ch=='t')&& (czywygral()==1 || czyremis()==1))
        {
            czytabela++;
            zerowanie();
            tabela();
        }

        if((ch=='d'|| ch=='D')&& czytabela==0)
        {
             setcolor(BLACK);
             rectangle(x11,y11,x11+60,y11+60);
             x11=x11+80;
             setcolor(WHITE);
             if(x11>10 && x11<250 && y11>10 && y11<250) rectangle(x11,y11,x11+60,y11+60);
             wspolj++;

        }

        if((ch=='a'|| ch=='A')&& czytabela==0)
        {
             setcolor(BLACK);
             rectangle(x11,y11,x11+60,y11+60);
             x11=x11-80;
             setcolor(WHITE);
             if(x11>10 && x11<250 && y11>10 && y11<250) rectangle(x11,y11,x11+60,y11+60);
             wspolj--;
        }
        if((ch=='s'|| ch=='S')&& czytabela==0)
        {
             setcolor(BLACK);
             rectangle(x11,y11,x11+60,y11+60);
             y11=y11+80;
             setcolor(WHITE);
             if(x11>10 && x11<250 && y11>10 && y11<250) rectangle(x11,y11,x11+60,y11+60);
             wspoli++;
        }
        if((ch=='w'|| ch=='W')&& czytabela==0)
        {
             setcolor(BLACK);
             rectangle(x11,y11,x11+60,y11+60);
             y11=y11-80;
             setcolor(WHITE);
             if(x11>10 && x11<250 && y11>10 && y11<250) rectangle(x11,y11,x11+60,y11+60);
             wspoli--;
        }
    }
    getch();
}


main()
{
    kolkoikrzyzyk();
}
