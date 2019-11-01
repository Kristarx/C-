#include <iostream>
using namespace std;

struct Element{
    int val;
    Element *next;

};

    Element *head = NULL;
    Element *tail = NULL;


void enqueue(int a)
{
    Element *element = new Element;
    element -> val = a;
    element -> next = NULL;
    if(head == NULL)
    {
        head = element;
        tail = element;
    }

    else
    {
        tail->next = element;
        tail = element;
    }

    Element *pom = head;
    while(pom != NULL)
    {
        cout << pom -> val  << " ";
        pom = pom->next;
    }

    cout << endl;


}

void dequeue()
{
    if(head == NULL)
    {
        cout << "Pusta";
    }

    else
    {
        Element *pom = head;
        head = head ->next;
        delete pom;
    }


     Element *pom = head;
    while(pom != NULL)
    {
        cout << pom -> val  << " ";
        pom = pom->next;
    }

    cout << endl;
}

bool isEmpty()
{
    if(head == NULL)
    {
        cout << "Pusta";
        return 1;
    }

    else
    {
        cout << "Nie jest pusta";
        return 0;
    }

}


int main()
{
    int liczba = 10;
    enqueue(10);
    liczba = 20;
    enqueue(liczba);
    liczba = 54;
    enqueue(liczba);
    dequeue();
    dequeue();
    isEmpty();
    dequeue();
    isEmpty();
}
