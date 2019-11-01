#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int ile;
    cin >> ile;
    int liczby[ile];

    for(int i = 0; i < ile; i++)
    {
        cin >> liczby[i];
    }

    cout << "Podaj liczbe szukana ";
    int szukana;
    cin >> szukana;

    int a = 0;
    int b = ile - 1;
    int dzielenie;

    while(a <= b)
    {
        dzielenie = (ceil)(a+b)/2;
        if(liczby[dzielenie] == szukana)
        {
            cout << dzielenie << endl;
            exit(0);
        }

        if(szukana < liczby[dzielenie])
            b = dzielenie - 1;
        else
            a = dzielenie + 1;
    }

    cout << "Chuja tam, ni ma taki liczby";
}
