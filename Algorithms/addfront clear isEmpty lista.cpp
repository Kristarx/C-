#include <iostream>
using namespace std;

struct Element{
    int val;
    Element *next;
    };

    Element *head = NULL;

bool isEmpty()
{
    if(head == NULL)
    {
        cout << "Pusta" << endl;
        return true;
    }

    else
    {
        cout << "Nie pusta" << endl;
        return false;
    }
}

void addFront(int v)
{
    Element *element = new Element;
    element -> val = v;
    element -> next = head;
    head = element;
}

void printlista()
{
    Element *pom = head;
    while(pom)
    {
        cout << pom -> val << " ";
        pom = pom -> next;
    }

    cout << "*";
}

void clearlista()
{
    Element *pom = head;

    while (pom != NULL)
    {
        pom = head -> next;
        delete head;
        head = pom;
    }
}

int main()
{
    isEmpty();
    for(int i = 0; i < 10; i++)
    addFront(i);
    isEmpty();
    printlista();
    clearlista();
    cout << endl;
    printlista();
    cout << endl;
    isEmpty();
}
