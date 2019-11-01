#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;


void Sortuj(int tab[], int ile, int zakres)
{
    int pom[zakres], zmienna;
    for(int i = 0; i < zakres; i++)
        pom[i] = 0;

    cout << endl;

    for(int j = 0; j < ile; j++)
    {
        zmienna = tab[j];
        pom[zmienna]++;
    }

    for(int j = 0; j < zakres; j++)
    {
        if((j != 0) || (pom[j] != 0))
        {
            zmienna = pom[j];
            for(int k = 0; k < zmienna; k++)
                cout << j << " ";
        }
    }
}


int main()
{
    int ile, zakres;
    cin >> ile >> zakres;
    int tab[ile];
    srand(time(NULL));

    for(int i = 0; i < ile; i++)
    {
        tab[i] = rand()%zakres;
        cout << tab[i] << " ";
    }

    Sortuj(tab, ile, zakres);
}
