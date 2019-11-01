#include <iostream>
using namespace std;

int main()
{
    int ile;
    cin >> ile;
    int lc[ile][2];

    for(int i = 0; i < ile; i++)
        cin >> lc[i][0] >> lc[i][1];

    for(int i = 0; i < ile; i++)
    {
        for(int lines = 0; lines < lc[i][0]; lines++)
        {
            for(int columns = 0; columns < lc[i][1]; columns++)
            {
                if(lines == 0 || lines == lc[i][0] - 1)
                    cout << "*";
                else if(columns == 0 || columns == lc[i][1] - 1)
                    cout << "*";
                else
                    cout << ".";
            }

            cout << endl;
        }

        cout << endl;
    }
}
