#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


int main()
{
    int przypadki;
    cin >> przypadki;
    for(int a = 0; a < przypadki; a++)
    {
        int ile;
        cin >> ile;
        char dane_haslo[ile][6], ciag[64];

        for(int i = 0; i < ile; i++)
            for(int j = 0; j < 6; j++)
                cin >> dane_haslo[i][j];

        for(int i = 0; i < 64; i++)
           cin >> ciag[i];

        for(int i = 0; i < ile; i++)
        {
            vector <int> niebieski;
            vector <int> zielony;
            vector <int> binary[6];

            for(int j = 0; j < 6; j++)
            {
                int pom = 0, c = 0, liczba = 0;
                int dana_liczba = (int)dane_haslo[i][j];

                while(dana_liczba != 0)
                {
                    pom = dana_liczba%2;
                    binary[j].push_back(pom);
                    dana_liczba = dana_liczba/2;
                }

                while(binary[j].size() != 8)
                    binary[j].push_back(0);
            }

            for(int a = 0; a < 6; a++)
            {
                niebieski.push_back(binary[a][a]);
                if(a < 3)
                    zielony.push_back(binary[a][a+3]);
                else
                    zielony.push_back(binary[a][a-3]);
            }


            int odlicz_nieb = 0, odlicz_ziel = 0;
            for(int a = 5; a >= 0; a--)
            {
                if(niebieski[a] == 1)
                    odlicz_nieb = odlicz_nieb + pow(2,a);
                if(zielony[a] == 1)
                    odlicz_ziel = odlicz_ziel + pow(2,a);
            }

            cout << ciag[odlicz_nieb] << ciag[odlicz_ziel];
        }
            cout << endl;
    }
}
