#include <iostream>
using namespace std;


int il_ciastek(int obz_czas[], int il_obz)
{
    int ciastka = 0;
    for(int i = 0; i < il_obz; i++)
        ciastka += 86400/obz_czas[i];

    return ciastka;
}


int main()
{
    int testy, il_obz, pudlo, ciastka;
    cin >> testy;

    for(int i = 0; i < testy; i++)
    {
        cin >> il_obz >> pudlo;
        int obz_czas[il_obz];
        for(int i = 0; i < il_obz; i++)
            cin >> obz_czas[i];

        ciastka = il_ciastek(obz_czas, il_obz);

        if(ciastka % pudlo == 0)
            cout << ciastka/pudlo << endl;
        else
            cout << ciastka/pudlo + 1 << endl;
    }
}
