#include <iostream>
using namespace std;

int Wyszukaj(int tab[], int jaka, int ile)
{
    for(int i = 0; i < ile; i++)
    {
        if(tab[i] == jaka)
        {
            cout << "Jest na pozycji " << i;
            break;
        }

        else
            continue;


        if(i == (ile - 1))
        {
            cout << "-1";
            return -1;
        }
    }

}

void Dodaj(int tab[], int ile)
{
    for(int i = 0; i < ile; i++)
        cin >> tab[i];
}

int main()
{
    int ile;
    int jaka;

    cout << "Podaj ile liczb wpisac: " << endl;
    cin >> ile;
    int tab[ile];

    Dodaj(tab, ile);

    cout << "Jaka liczbe chcesz wyszukac: ";
    cin >> jaka;

    Wyszukaj(tab, jaka, ile);
}
