#include <iostream>
using namespace std;

int main()
{
    int ile;
    cin >> ile;
    int n, x, y;

    for(int i = 0; i < ile; i++)
    {
        cin >> n >> x >> y;
        int pom = x;
        while(pom < n)
        {
            if((pom%x == 0) && (pom%y != 0))
                cout << pom << " ";
            pom += x;
        }

        cout << endl;
    }
}
