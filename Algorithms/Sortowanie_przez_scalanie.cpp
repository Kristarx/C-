#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<time.h>
using namespace std;


void scal(int tab[], int lewy, int srodek, int prawy)
{
    int pom[prawy+1];
	int i = lewy, j = srodek + 1;

  for(int i = lewy; i <= prawy; i++)
    pom[i] = tab[i];

  for(int k = lewy; k <= prawy; k++)
  if(i <= srodek)
    if(j <= prawy)
         if(pom[j] < pom[i])
             tab[k] = pom[j++];

         else
             tab[k] = pom[i++];
    else
        tab[k] = pom[i++];
  else
      tab[k] = pom[j++];
}

void sortowanie_przez_scalanie(int tab[],int lewy, int prawy)
{

	if(prawy<=lewy)
        return;

	int srodek = (prawy+lewy)/2;

	sortowanie_przez_scalanie(tab, lewy, srodek);
	sortowanie_przez_scalanie(tab, srodek+1, prawy);

	scal(tab, lewy, srodek, prawy);
}

int main()
{
	int ile;
    cin >> ile;
    int tab[ile];

    srand(time(NULL));

    for(int i = 0 ; i < ile; i++)
    {
        tab[i] = rand()%50;
        cout << tab[i] << " ";
    }

    sortowanie_przez_scalanie(tab, 0, ile-1);
    cout << endl;

    for(int i = 0; i < ile; i++)
        cout << tab[i] << " ";

}
