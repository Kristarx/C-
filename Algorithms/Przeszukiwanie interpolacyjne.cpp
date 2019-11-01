#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int tab[k];

    for(int i = 0; i < k; i++)
    {
        cin >> tab[i];
    }

    int x;
    cout << "Podaj szukana wartosc: ";
    cin >> x;

    int a = 0;
    int b = k-1;
    float c;
    int p;

    if(x > tab[b])
    {
        cout << "Nie ma pasujacej liczby w ciagu";
        exit(0);
    }

    while(a<=b)
    {
        c = (a + ((x-tab[a])*(b-a))/(tab[b] - tab[a]));
        //p = (int)ceil(c);

        if(tab[p] == x)
        {
            cout << "Liczba znajduje sie na pozycji " << p << " liczac od pierwszego indeksu tablicy czyli od 0." << endl;
            break;
        }
        else if(x > tab[p])
            a = p + 1;
        else if(x < tab[p])
            b = p - 1;
    }
}
