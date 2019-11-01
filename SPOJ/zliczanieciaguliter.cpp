    #include <iostream>
#include <string>
using namespace std;

int main()
{
    int ile;
    cin >> ile;
    string ciag;
    int dlugosc_ciagu, licznik = 1;

    for(int i = 0; i < ile; i++)
    {
        cin >> dlugosc_ciagu >> ciag;
        for(int j = 1; j <= ciag.size(); j++)
        {
            if(ciag[j-1] == ciag[j])
                licznik++;
            else
            {
                if(licznik == 1)
                    cout << ciag[j-1];
                else if(licznik == 2)
                    cout << ciag[j-1] << ciag[j-1];
                else
                    cout << licznik << ciag[j-1];

                licznik = 1;
            }
        }
    }
}
