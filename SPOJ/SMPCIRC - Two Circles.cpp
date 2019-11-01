#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int ile;
    cin >> ile;

    for(int i = 0; i < ile; i++)
    {
        double x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double AB = sqrt(pow(x1-x2, 2) + pow(y1 - y2, 2));

        if(AB < abs(r1 - r2))
            cout << "I" << endl;
        else if(AB == abs(r1 - r2))
            cout << "E" << endl;
        else
            cout << "O" << endl;
    }
}
