#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <list>
#include <math.h>
using namespace std;


void Kub_Poz(int tab[], int ile)
{
    list<int>lista[10];
    int modulo, pomocnicze;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < ile; j++)
        {
            pomocnicze = tab[j]/pow(10,i);
            modulo = pomocnicze%10;
            lista[modulo].push_front(tab[j]);
        }

        int pom = 0;

        for(int k = 0; k < 10; k++)
        while(!(lista[k].empty()))
        {
            tab[pom] = lista[k].back();
            lista[k].pop_back();
            pom++;
        }
    }
}

void Wypisz(int tab[], int ile)
{
    cout << endl;

    for(int i = 0; i < ile; i++)
        cout << tab[i] << " ";

}

double Czas(double stop, double start)
{
    cout << endl << (stop - start)/CLOCKS_PER_SEC << " s";
}


int main()
{
    int ile, zakres;
    cin >> ile >> zakres;
    int tab[ile];
    srand(time(NULL));

    for(int i = 0; i < ile; i++)
    {
        tab[i] = rand()%zakres+1000;
        cout << tab[i] << " ";
    }

    cout << endl;
    clock_t start = clock();
    Kub_Poz(tab, ile);
    clock_t stop = clock();
    Wypisz(tab, ile);
    Czas(stop, start);
}
