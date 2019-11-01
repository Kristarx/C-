#include <iostream>

using namespace std;

int main()
{

    int n, ile=1;
    cin >> n;
    string* tab = new string[n];

    for(int i=0; i<n; i++)
        cin >> tab[i];

    for(int i=0; i < n; i++)
    {

        for(int j=1; j<=tab[i].length(); j++)
        {

            if(tab[i][j]==tab[i][j-1])
                ile++;
            else
            {
                if(ile>2)
                    cout << tab[i][j-1] << ile;
                else if(ile==2)
                    cout << tab[i][j-1] << tab[i][j-1];
                else
                    cout << tab[i][j-1];
                ile=1;
            }
        }
        cout << endl;
    }

    delete[] tab;
    return 0;
}
