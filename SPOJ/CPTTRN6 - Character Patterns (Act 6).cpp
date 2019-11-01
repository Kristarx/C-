#include <iostream>
using namespace std;

int main()
{
    int ile;
    cin >> ile;
    for(int i = 0; i < ile; i++)
    {
        int l, c, wiersze_wzor, ilosc_kropek;
        cin >> l >> c >> wiersze_wzor >> ilosc_kropek;

        for(int a = 0; a < ((wiersze_wzor * (l+1)) + l); a++)
        {
            if(c == 1)
            {
                if((a+1)%(wiersze_wzor+1) == 0)
                {
                    for(int d = 0; d <= 2*ilosc_kropek; d++)
                    {
                        if(d == ilosc_kropek)
                            cout << "+";
                        else
                            cout << "-";
                    }

                    cout << endl;
                }

                else
                {
                    for(int d = 0; d <= 2*ilosc_kropek; d++)
                    {
                        if(d == ilosc_kropek)
                            cout << "|";
                        else
                            cout << ".";
                    }

                    cout << endl;
                }
            }

            else
            {
                if((a+1)%(wiersze_wzor+1) == 0)
                {
                    for(int b = 0; b < ((ilosc_kropek+1)*c + ilosc_kropek); b++)
                    {
                        if((b+1)%(ilosc_kropek+1) == 0)
                            cout << "+";
                        else
                            cout << "-";
                    }

                    cout << endl;
                }

                else
                {
                    for(int b = 0; b < ((ilosc_kropek+1)*c + ilosc_kropek); b++)
                    {
                        if((b+1)%(ilosc_kropek+1) == 0)
                            cout << "|";
                        else
                            cout << ".";
                    }

                    cout << endl;
                }
            }
        }
    }
}
