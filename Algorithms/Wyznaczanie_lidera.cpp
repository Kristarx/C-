#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;


int Potencjalny_Lider(int liczby[], int ile_liczb)
{
    int lider = liczby[0];
    int wystapienia = 1;

    for(int i = 1; i < ile_liczb; i++)
    {
        if(wystapienia > 0)

            if(liczby[i] == lider)
                ++wystapienia;
            else
                --wystapienia;


        else
        {
            ++wystapienia;
            lider = liczby[i];
        }

    }

    if(wystapienia == 0)
    {
        cout << "Brak lidera";
        exit(0);
    }

    else
        return lider;

}

void Czy_Lider(int potencjalny, int liczby[], int ile)
{
    int zliczenie = 0;

    for(int i = 0; i < ile; i++)
    {
        if(potencjalny == liczby[i])
            zliczenie++;
    }

    if(zliczenie > (ile/2))
        cout << "Lider to " << potencjalny;
    else
        cout << "Brak lidera";
}



int main()
{
    int ile_liczb;
    cout << "Ile liczb: ";
    cin >> ile_liczb;

    srand(time(NULL));
    int liczby[ile_liczb];

    for(int i = 0; i < ile_liczb; i++)
    {
        liczby[i] = rand()%2;
        cout << liczby[i] << " ";
    }

    cout << endl;

    int potencjalny = Potencjalny_Lider(liczby, ile_liczb);
    Czy_Lider(potencjalny, liczby, ile_liczb);

}
