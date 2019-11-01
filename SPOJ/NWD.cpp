#include <iostream>
#include <vector>
using namespace std;


void TeSameLiczby(vector <int> liczby1, vector <int> liczby2)
{
        int licznik2 = 0;
        int flaga = 0;
        vector <int> pom;

        while((!liczby1.empty()) && (!liczby2.empty()))
        {
            while((flaga != 1) && (licznik2 < liczby2.size()))
            {
                if(liczby1[0] == liczby2[licznik2])
                {
                    pom.push_back(liczby1[0]);
                    flaga = 1;
                    swap(liczby2[liczby2.size() - 1], liczby2[licznik2]);
                    liczby2.pop_back();
                }

                else
                    licznik2++;
            }

            flaga = 0;
            swap(liczby1[liczby1.size() - 1], liczby1[0]);
            liczby1.pop_back();
            licznik2 = 0;
        }

        int liczba = 1;
        while(!pom.empty())
        {
            liczba = liczba * pom.back();
            pom.pop_back();
        }

        cout << liczba << endl;

}



int main()
{
    int liczba[2];
    int test;
    cin >> test;

    int licznik = 2;
    for(int j = 0; j < test; j++)
    {
        vector <int> dzielenie[2];
        cin >> liczba[0] >> liczba[1];
        int pom = liczba[0];

        for(int i = 0; i < 2; i++)
        {
            while((liczba[i] != 1) && (liczba[i] != 0))
            {
                if(liczba[i] % licznik == 0)
                {
                    liczba[i] /= licznik;
                    dzielenie[i].push_back(licznik);
                    licznik = 2;
                }

                else
                    licznik++;
            }

            licznik = 2;
        }

        TeSameLiczby(dzielenie[0], dzielenie[1]);
    }
}
