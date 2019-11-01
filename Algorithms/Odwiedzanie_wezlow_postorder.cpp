
//ODWIEDZANIE WEZLOW SPOSOB POSTORDER

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

// Rekurencyjna funkcja postorder

void postorder(BTNode * v)
{
  if(v)
  {
    postorder(v->left);     // przechodzimy lewe poddrzewo
    postorder(v->right);    // przechodzimy prawe poddrzewo
    cout << v->data << " "; // odwiedzamy wêze³
  }
}

int main()
{
  postorder(&A);  // przejœcie rozpoczynamy od korzenia
  cout << endl;
  return 0;
}
