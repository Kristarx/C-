#include <iostream>
using namespace std;

int main()
{
    int ile;
    cin >> ile;

    for(int i = 0; i < ile; i++)
    {
        int l, c;
        cin >> l >> c;

        if(c == 1)
        {
            for(int a = 0; a <= l*3; a++)
            {
                if(a%3 == 0)
                    cout << "****" << endl;
                else
                    cout << "*..*" << endl;
            }
        }

        else
        {
            for(int a = 0; a <= l*3; a++)
            {
                if(a%3 == 0)
                {
                    cout << "****";
                    for(int b = 0; b < (c-1)*3; b++)
                        cout << "*";
                    cout << endl;
                }

                else
                {
                    cout << "*..*";
                    for(int b = 0; b < (c-1); b++)
                        cout << "..*";
                    cout << endl;
                }
            }
        }
    }
}
