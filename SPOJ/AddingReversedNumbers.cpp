#include <iostream>
using namespace std;

main()
{
    int numb;
    int NumA, NumB;
    int *tab1 = new int[10000];
    int *tab2 = new int[10000];
    cin >> numb;
    for(int i = 0; i < numb; i++)
    {
        cin >> NumA;
        cin >> NumB;
        tab1[i] = NumA;
        tab2[i] = NumB;
    }

    for(int i = 0; i < numb; i++)
    {
        int a = tab1[i], b = tab2[i], c = 0, d = 0, e = 0, f = 0;

        while((a%10 != 0) || (b%10 != 0))
        {
            e = a%10;
            f = b%10;
            if(a != 0)
            c = 10*c + e;
            if(b != 0)
            d = 10*d + f;
            a /=10;
            b /=10;
        }

        //cout << c << " " << d << endl;

        int sum = c + d;
        c = 0;

        while(sum%10 != 0)
        {
            e = sum%10;
            c = 10*c + e;
            sum /=10;
            //cout << "e = " << e << ", " << "c = " << c << ", " << "sum = " << sum << endl;
        }

        cout << c << endl;
    }

    delete [] tab1;
    delete [] tab2;
}
