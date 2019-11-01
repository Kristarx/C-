#include <iostream>
#include <cmath>
using namespace std;

int counter = 0; int new_dec = 0; int pom;

int To_Dec(int binary, int counter)
{
    pom = binary%2;

    if(pom == 1)
        new_dec = new_dec + pow(2,counter);

    counter++;
    binary /= 10;

    if(binary == 0)
        return new_dec;
    To_Dec(binary, counter);
}

int main()
{
    int binary;
    cin >> binary;
    int dec = To_Dec(binary, counter);
    cout << dec;
}
