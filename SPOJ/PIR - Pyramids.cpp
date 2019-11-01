#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int ile;
    cin >> ile;

    for(int i = 0; i < ile; i++)
    {
        long double AB, AC, AD, BC, BD, CD, cus;
        cin >> AB >> AC >> AD >> BC >> BD >> CD;
        long double ab = pow(AD,2) + pow(BD,2) - pow(AB,2);
        long double ac = pow(AD,2) + pow(CD,2) - pow(AC,2);
        long double bc = pow(BD,2) + pow(CD,2) - pow(BC,2);
        cus = sqrt(4*pow(AD,2)*pow(BD,2)*pow(CD,2) - pow(AD,2)*pow(bc,2) - pow(BD,2)*pow(ac,2) - pow(CD,2)*pow(ab,2) + ab*ac*bc)/12;

        cout << fixed << setprecision(4) << cus << endl;
    }
}
