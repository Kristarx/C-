#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

struct Element{
    int val;
    Element *next;
    Element *prev;
};

     Element *tail = NULL;
     Element *head = NULL;


void Dodaj(int liczba)
{
    Element *element = new Element;
    element -> val = liczba;
    if(head == NULL)
    {
        element -> next = element -> prev = NULL;
        head = element;
        tail = element;
    }

    else
    {
        element -> next = NULL;
        tail -> next = element;
        element -> prev = tail;
        tail = element;
    }


    Element *pom = head;

    while(pom)
    {
        cout << pom -> val << " ";
        pom = pom -> next;
    }

    cout << endl;

}


void Zdejmij()
{
    Element *pom = new Element;
    pom = head; // ustawiamy pomoc na wierzcholek kolejki

    if (head == tail) // jezeli jest tylko jeden element w kolejce
        head = tail = NULL; // to teraz kolejka bedzie usta
    else // jezeli jest wiecej elementow
        head = head->next; // przestawiamy wierzcholek na drugi element (pierwszy musimy usunac)
    delete pom; // usuwamy element ze szczytu stosu

    pom = head;
    while(pom)
    {
        cout << pom -> val << " ";
        pom = pom -> next;
    }

    cout << endl;
}



int main()
{
    srand(time(NULL));
    int liczba[10];

    for(int i = 0; i < 10; i++)
    {
        liczba[i] = rand()%30;
        Dodaj(liczba[i]);
    }

    for(int i = 0; i < 10; i++)
        Zdejmij();
}
