#include <iostream>
using namespace std;

int main()
{
    int ile;
    cin >> ile;

    for(int i = 0; i < ile; i++)
    {
        int l, c, linie_wzor, kropki;
        cin >> l >> c >> linie_wzor >> kropki;

        if(c == 1)
        {
            for(int a = 0; a <= (linie_wzor + 1) * l; a++)
            {
                if(a%(linie_wzor+1) == 0)
                    for(int b = 0; b < (kropki+2); b++)
                        cout << "*";
                else
                {
                    for(int b = 0; b < (kropki+2); b++)
                    {
                        if(b == kropki+1 || b == 0)
                            cout << "*";
                        else
                            cout << ".";
                    }
                }

                cout << endl;
            }
        }

        else
        {
            for(int a = 0; a <= (linie_wzor + 1) * l; a++)
                if(a%(linie_wzor+1) == 0)
                {
                    for(int b = 0; b < ((kropki + 2) + (kropki+1)*(c-1)); b++)
                        cout << "*";
                    cout << endl;
                }

                else
                {
                    cout << "*";

                    for(int b = 0; b < c; b++)
                        for(int e = 0; e < (kropki+1); e++)
                        {
                            if(e == kropki)
                                cout << "*";
                            else
                                cout <<".";
                        }

                    cout << endl;
                }

            cout << endl;
        }
    }
}
