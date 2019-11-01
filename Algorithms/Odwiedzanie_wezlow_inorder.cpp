//ODWIEDZANIE DRZEWA SPOSOB INORDER


#include <iostream>

using namespace std;

// Typ wêz³ów drzewa

struct BTNode
{
  BTNode * left;
  BTNode * right;
  char data;
};

// Tworzenie struktury drzewa rozpoczynamy od liœci

BTNode G = {NULL,NULL,'G'};
BTNode H = {NULL,NULL,'H'};
BTNode I = {NULL,NULL,'I'};
BTNode J = {NULL,NULL,'J'};
BTNode K = {NULL,NULL,'K'};

// Tworzymy kolejnych ojców

BTNode D = { &H,  &I,'D'};
BTNode E = { &J,NULL,'E'};
BTNode F = { &K,NULL,'F'};
BTNode B = { &D,  &E,'B'};
BTNode C = { &F,  &G,'C'};

// Tworzymy korzeñ drzewa

BTNode A = { &B,  &C,'A'};

// Rekurencyjna funkcja inorder

void inorder(BTNode * v)
{
  if(v)
  {
    inorder(v->left);       // przechodzimy lewe poddrzewo
    cout << v->data << " "; // odwiedzamy wêze³
    inorder(v->right);      // przechodzimy prawe poddrzewo
  }
}

int main()
{
  inorder(&A);  // przejœcie rozpoczynamy od korzenia
  cout << endl;
  return 0;
}
