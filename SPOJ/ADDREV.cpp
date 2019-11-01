#include <iostream>
using namespace std;

int rewers(int liczba)
{
    int pom;
    int nowa = 0;
    while(liczba != 0)
    {
        pom = liczba % 10;
        liczba /= 10;
        nowa = 10*nowa + pom;
    }

    return nowa;
}


int main()
{
    int il_testow;
    cin >> il_testow;
    int a,b;

    for(int i = 0; i < il_testow; i++)
    {
        cin >> a >> b;
        a = rewers(a);
        b = rewers(b);
        int suma = a + b;
        suma = rewers(suma);
        cout << suma << endl;
    }
}
