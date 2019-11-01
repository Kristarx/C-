#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

double pom=0, c = 0, liczba = 0;
int funkcja(int m)
{
    pom = m%2;
    if(pom == 1)
    {
        liczba = liczba + pow(10, c);
    }

    c++;
    m = m/2;
    if(m == 0)
        return liczba;
    else
        funkcja(m);
}


int main()
{
    int n;
    cin >> n;
    int licz = funkcja(n);
    cout << licz;
}
