#include <iostream>
using namespace std;

int odwrotna(int liczba)
{
    int nowa = 0, pom;
    while(liczba != 0)
    {
        pom = liczba % 10;
        liczba /= 10;
        nowa = nowa * 10 + pom;
    }

    return nowa;
}

int main()
{
    int il_testow;
    cin >> il_testow;
    int a[il_testow], b[il_testow], liczba1[il_testow], liczba2[il_testow];

    for(int i = 0; i < il_testow; i++)
        cin >> a[i] >> b[i];

    for(int i = 0; i < il_testow; i++)
    {
        liczba1[i] = odwrotna(a[i]);
        liczba2[i] = odwrotna(b[i]);
        if(liczba1[i] > liczba2[i])
            cout << liczba1[i] << endl;
        else
            cout << liczba2[i] << endl;
    }
}
