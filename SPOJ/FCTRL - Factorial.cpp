#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int ile;
    cin >> ile;

    for(int i = 0; i < ile; i++)
    {
        int liczba, pom = 1, licznik = 0, potegowanie = 1;
        cin >> liczba;
        while(pom >= 1)
        {
            pom = liczba/pow(5,potegowanie);
            licznik += pom;
            potegowanie++;
        }

        cout << licznik << endl;
    }
}
