#include <iostream>
using namespace std;

int main()
{
    int m, n, liczba;
    cin >> m >> n;
    int tab[m][n];
    int nowa[n][m];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> liczba;
            tab[i][j] = liczba;
        }
    }

    cout << endl;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            nowa[j][i] = tab[i][j];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
           cout << nowa[i][j] << " ";

        cout << endl;
    }
}
