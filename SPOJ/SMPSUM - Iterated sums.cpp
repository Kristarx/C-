#include <iostream>
using namespace std;

int main()
{
    int a,b, liczba = 0;
    cin >> a >> b;

    for(int i = a; i <= b; i++)
        liczba = liczba + i*i;

    cout << liczba;
}
