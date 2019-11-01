#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;


void Sortowanko(int liczby[], int ile)
{
    int minimum_indeks;
    for(int i = 0; i < ile; i++)
    {
        minimum_indeks = i;

        for(int j = i+1; j < ile; j++)
        {
            if(liczby[j] < liczby[minimum_indeks])
            {
                minimum_indeks = j;
            }
        }

        swap(liczby[i], liczby[minimum_indeks]);
    }

    cout << endl;

    for(int i = 0; i < ile; i++)
        cout << liczby[i] << " ";

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
