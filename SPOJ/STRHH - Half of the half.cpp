#include <iostream>
#include <string>
using namespace std;

int main()
{
    int ile;
    cin >> ile;
    for(int i = 0; i < ile; i++)
    {
        string wyraz;
        cin >> wyraz;
        for(int j = 0; j < wyraz.size()/2; j += 2)
            cout << wyraz[j];
        cout << endl;
    }
}
