#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int ile;
    cin >> ile;
    int dodaj, liczba, flaga = 0, zliczenia = 0;
    string ciag;

    for(int i = 0; i < ile; i++)
    {
        cin >> ciag >> dodaj;
        for(int k = 0; k < ciag.size(); k++)
        {
            int j = 2;
            liczba = ciag[k];

            while((flaga == 0) && j < sqrt(liczba + dodaj + 1))
            {
                if(((liczba + dodaj)%j == 0))
                    flaga++;
                j++;
            }

            if(flaga == 0)
                zliczenia++;
            flaga = 0;
        }

        if(zliczenia == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        zliczenia = 0;
    }
}
