#include <iostream>
using namespace std;

int main()
{
    int il_testow;
    cin >> il_testow;

    for(int i = 0 ; i < il_testow; i++)
    {
        int sum, suma = 0, liczba;
        cin >> sum;

        for(int j = 0; j < sum; j++)
        {
            cin >> liczba;
            suma += liczba;
        }

        cout << suma << endl;

    }
}
