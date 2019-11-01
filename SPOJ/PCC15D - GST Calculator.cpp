#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int ile;
    cin >> ile;

    for(int i = 0; i < ile; i++)
    {
        int pozycje, ilosc;
        double cena, pieniadze = 0, tax = 0;
        string nazwa, podatek;
        cin >> pozycje;

        for(int k = 0; k < pozycje; k++)
        {
            cin >> nazwa >> ilosc >> cena >> podatek;
            if(podatek == "SR")
            {
                pieniadze = pieniadze + ilosc*cena*(1+0.06);
                tax = tax + ilosc*cena*0.06;
            }

            else
                pieniadze = pieniadze + ilosc*cena;
        }

        std::cout << std::fixed << std::showpoint;
        cout << "Case #" << i+1 << ":" << endl;
        cout << "Total Amount Include GST: " << setprecision(2) << pieniadze << endl;
        cout << "Total Amount GST Paid: " << setprecision(2) << tax << endl;
    }
}
