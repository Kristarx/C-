#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
using namespace std;

void  Sortowanie_Szybkie(int tab[], int lewy, int prawy)
{
        int pivot=tab[(lewy+prawy)/2];
        int i,j,x;
        i=lewy;
        j=prawy;
        while(i<=j)
        {
            while(tab[i]<pivot) i++;
            while(tab[j]>pivot) j--;
                if(i<=j)
                {
                    x=tab[i];
                    tab[i]=tab[j];
                    tab[j]=x;
                    i++;
                    j--;
                }
        }

    if(j>lewy) Sortowanie_Szybkie(tab,lewy, j);
    if(i<prawy) Sortowanie_Szybkie(tab, i, prawy);
}


int main()
{
    int ile;
    cin >> ile;
    int tab[ile];
    srand(time(NULL));

    for(int i = 0 ; i < ile; i++)
    {
        tab[i] = rand()%50;
        cout << tab[i] << " ";
    }

    Sortowanie_Szybkie(tab, 0, ile-1);
    cout << endl;

    for(int i = 0; i < ile; i++)
        cout << tab[i] << " ";
}
