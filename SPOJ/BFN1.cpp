#include <iostream>
#include <math.h>
using namespace std;

int odwrotna(int liczba)
{
    int palindrom = 0;
    int pom = 0;

    while(liczba != 0)
        {
            pom = liczba % 10;
            liczba = liczba/10;
            palindrom = 10 * palindrom + pom;
        }
        return palindrom;
}


int main()
{
    int testy;
    int pomoc;
    int flaga = 0;
    cin >> testy;
    int liczba, zliczanie = 0;



    for(int i = 0; i < testy; i++)
    {
        cin >> liczba;

        while(flaga != 1)
        {
            pomoc = odwrotna(liczba);
            if(pomoc == liczba)
            {
                cout << liczba << " " << zliczanie << endl;
                flaga++;
            }

            else
            {
                zliczanie++;
                liczba += pomoc;
            }
        }

        flaga = 0;
        zliczanie = 0;

    }
}
