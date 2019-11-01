#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void Sortowanko(int liczby[], int ile)
{
    int przepisanie, j;

    for(int i = 1; i < ile; i++)
    {
        przepisanie = liczby[i];
        j = i - 1;
        while((j >= 0) && (liczby[j] > przepisanie))
        {
            liczby[j+1] = liczby[j];
            j--;
        }

        liczby[j + 1] = przepisanie;
    }

    for(int i = 0; i < ile; i++)
    {
        cout << liczby[i] << " ";
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
    }

    cout << endl;

    Sortowanko(liczby, ile);
}

