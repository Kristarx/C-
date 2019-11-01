#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    while(cin >> a >> b >> c)
    {
        double delta = b*b - 4*a*c;

        if(delta < 0)
            cout << 0;
        else if(delta == 0)
            cout << 1;
        else if(delta > 0)
            cout << 2;

        cout << endl;
    }
}
