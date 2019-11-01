/* Dla listy jednokierunkowej zaimplementuj:
    - algorytm dodawania elementu z zachowaniem porz¹dku
    -algorytm usuwania pierwszego elementu o podanej wartosci
*/

#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

struct Element{
    int val;
    Element *next;
    };

    Element *head = NULL;

void addOrder(int liczba)
{
    Element *element = new Element;
    element -> val = liczba;

    if(head == NULL)
    {
        element -> next = head;
        head = element;
    }

    else
    {
        if((head -> val) > liczba)
        {
            element -> next = head;
            head = element;
        }

        else
        {
            Element *pom = head;
            Element *pomnext = head -> next;

            while((pomnext != NULL) && (pomnext -> val) <= liczba)
            {
                pom = pomnext;
                pomnext = pomnext -> next;
            }

            element -> next = pomnext;
            pom -> next = element;
        }
    }

    Element *pomc = head;
    while(pomc)
    {
        cout << pomc -> val << " ";
        pomc = pomc -> next;

    }
    cout << endl;
}

bool removeOne(int liczbab)
{
    Element *pom = head;
    Element *pomnext = head -> next;

    if((head -> val) == liczbab)
    {
        delete head;
        head = pomnext;
    }

    else
    {
        Element *p = head;

        while(p->next->val != liczbab)
            p = p->next;

        p->next = p->next->next;
        delete p->next;
    }

    Element *pomc = head;
    while(pomc)
    {
        cout << pomc -> val << " ";
        pomc = pomc -> next;

    }
    cout << endl;
    return 1;
}

int main()
{
    srand(time(NULL));
    int liczba[10], liczbab;

    for(int i = 0; i < 10; i++)
    {
        liczba[i] = rand()%10;
        cout << liczba[i] << " ";
    }

    cout << endl << endl;

    for(int i = 0; i < 10; i++)
        addOrder(liczba[i]);

    while(head != NULL)
    {
        cin >> liczbab;
        removeOne(liczbab);
    }

}
