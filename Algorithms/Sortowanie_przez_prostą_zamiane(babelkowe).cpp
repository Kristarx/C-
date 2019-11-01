#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
using namespace std;


void Sortowanko_Babelkowe(int liczba[], int ile)
{
    for(int i = 0; i < ile; i++)
        for(int j = 1; j < ile - i; j++)
        {
            if(liczba[j-1] > liczba[j])
                swap(liczba[j-1], liczba[j]);
        }

     for(int i = 0; i < ile; i++)
     {
         cout << liczba[i] << " ";
         Sleep(100);
     }

}


int main()
{
    cout << "Podaj ilosc elementow zbioru: ";
    int ile;
    cin >> ile;
    int liczby[ile];
    srand(time(NULL));

    for(int i = 0; i < ile; i++)
    {
        liczby[i] = rand()%20;
        cout << liczby[i] << " ";
        Sleep(100);
    }

    cout << endl;

    Sortowanko_Babelkowe(liczby, ile);
}
