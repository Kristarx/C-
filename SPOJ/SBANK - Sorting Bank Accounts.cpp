#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int ile;
    cin >> ile;
    for(int i = 0; i < ile; i++)
    {
        int ile_numerow;
        cin >> ile_numerow;
        cin.ignore();
        int counter = 0;
        map<string,int> Licznik_Ciagow;
        string numery;

        while(counter != ile_numerow)
        {
            getline(cin, numery);
            Licznik_Ciagow[numery]++;
            counter++;
        }

        map<string, int>::iterator iter;

        for(iter = Licznik_Ciagow.begin(); iter != Licznik_Ciagow.end(); iter++)
             cout << iter->first << " " << iter->second << endl;
    }
}
