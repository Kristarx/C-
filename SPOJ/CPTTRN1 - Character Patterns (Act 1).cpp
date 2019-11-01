#include <iostream>
using namespace std;

int main()
{
    int ile;
    cin >> ile;

    for(int i = 0; i < ile; i++)
    {
        int wiersze, kolumny;
        cin >> wiersze >> kolumny;
        int iloczyn = wiersze * kolumny;

        for(int j = 1; j <= iloczyn; j++)
        {
            if(j%2 != 0)
                cout << "*";
            else
                cout << ".";
            if(j%kolumny == 0)
                cout << endl;
        }

        cout << endl;
    }
}
