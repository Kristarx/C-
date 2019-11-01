#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

struct Element{
    int val;
    Element *next;
};

Element *head = NULL;

void push(int liczba)
{
    Element *element = new Element;
    element -> val = liczba;
    element->next = head;
    head = element;
}

void pop()
{
    Element *pom = head;
    head = head -> next;
    delete pom;

}

void clearList()
{
    Element *pom = head;

    while(head != NULL)
    {
        pom = head;
        head = head -> next;
        delete pom;
    }
}


int main()
{
    srand(time(NULL));
    int liczba[10];

     Element *pom = head;

    for(int i = 0; i < 10; i++)
    {
        liczba[i] = rand()%30;
        push(liczba[i]);

        pom = head;
        while(pom)
        {
            cout << pom->val << " ";
            pom = pom -> next;
        }

        cout << endl;
    }

    for(int i = 0; i < 10; i++)
    {
        pop();
        pom = head;

        while(pom)
        {
            cout << pom->val << " ";
            pom = pom -> next;
        }

        cout << endl;
    }

    clearList();

    if(head == NULL)
        cout << "Pusta";
}
