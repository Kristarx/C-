#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int ile;
    cin >> ile;

    for(int a = 0; a < ile; a++)
    {
        double liczba = 0;
        int z_jakiej, na_jaka;
        string number;

        cin >> number >> z_jakiej >> na_jaka;

        int pom, licznik = 0;
        vector <int> new_number;

        for(int i = number.size()-1; i >= 0; i--)
        {
            if((char)number[i] < 58)
                pom = (char)number[i] - 48;

            else
                pom = (char)number[i] - 55;

            liczba = liczba + pom*pow(z_jakiej, licznik);
            licznik++;
        }

        int liczbab = (int)liczba;

        while(liczbab != 0)
        {
            pom = liczbab%na_jaka;
            liczbab = liczbab/na_jaka;
            if(pom < 10)
                pom += 48;
            else
                pom += 55;

            new_number.push_back(pom);
        }

        for(int b = new_number.size() - 1; b >= 0; b--)
            cout << (char)new_number[b];

        cout << endl;
    }
}
