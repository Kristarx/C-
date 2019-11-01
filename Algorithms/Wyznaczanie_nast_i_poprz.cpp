

//DRZEWO BST, WYZNACZANIE NASTEPNIKA I POPRZENIKA


#include <iostream>
#include <iomanip>

using namespace std;

// Typ wêz³ów drzewa BST

struct BSTNode
{
  BSTNode *up, *left, *right;
  int key;
};

// Funkcja wczytuje drzewo BST ze standardowego
// wejœcia i zwraca wskazanie korzenia.
//-----------------------------------------------
BSTNode * readBST()
{
  BSTNode ** vp;   // Tablica wskazañ wêz³ów
  int key,u,l,r,i,n;

  cin >> n;                 // Odczytujemy liczbê wêz³ów drzewa

  vp = new BSTNode * [n];   // Tworzymy dynamiczn¹ tablicê wskazañ wêz³ów

  // Tablicê dynamiczn¹ wype³niamy wskazaniami wêz³ów,
  // które równie¿ tworzymy dynamicznie

  for(i = 0; i < n; i++) vp[i] = new BSTNode;

  // Teraz wczytujemy definicjê drzewa i tworzymy jego strukturê
  // w pamiêci wype³niaj¹c odpowiednie pola wêz³ów.

  for(i = 0; i < n; i++)
  {
    cin >> key >> u >> l >> r; // Czytamy klucz, numery ojca, lewego i prawego syna

    vp[i]->key = key;       // Ustawiamy klucz

    vp[i]->up  = vp[u];     // Ustawiamy ojca

    vp[i]->left  = l ? vp[l]: NULL;  // Ustawiamy lewego syna

    vp[i]->right = r ? vp[r]: NULL;  // Ustawiamy prawego syna

  }

  vp[0]->up = NULL;         // Korzeñ nie posiada ojca

  BSTNode * p = vp[0];      // Zapamiêtujemy korzeñ

  delete [] vp;             // Usuwamy tablicê dynamiczn¹

  return p;
}

// Funkcja zwraca wskazanie wêz³a o najmniejszym kluczu.
// Parametrem jest wskazanie korzenia drzewa BST.
//------------------------------------------------------
BSTNode * minBST(BSTNode * p)
{
  if(p) while(p->left) p = p->left;

  return p;
}

// Funkcja zwraca wskazanie wêz³a o najwiêkszym kluczu.
// Parametrem jest wskazanie korzenia drzewa BST.
//------------------------------------------------------
BSTNode * maxBST(BSTNode * p)
{
  if(p) while(p->right) p = p->right;

  return p;
}

// Funkcja znajduje nastêpnik wêz³a p
//-----------------------------------
BSTNode * succBST(BSTNode * p)
{
  BSTNode * r;

  if(p)
  {
    if(p->right) return minBST(p->right);
    else
    {
      r = p->up;
      while(r && (p == r->right))
      {
        p = r;
        r = r->up;
      }
      return r;
    }
  }
  return p;
}

// Funkcja znajduje poprzednik wêz³a p
//------------------------------------
BSTNode * predBST(BSTNode * p)
{
  BSTNode * r;

  if(p)
  {
    if(p->left) return maxBST(p->left);
    else
    {
      r = p->up;
      while(r && (p == r->left))
      {
        p = r;
        r = r->up;
      }
      return r;
    }
  }
  return p;
}

// Procedura DFS:postorder usuwaj¹ca drzewo
//-----------------------------------------
void DFSRelease(BSTNode * v)
{
  if(v)
  {
    DFSRelease(v->left);   // usuwamy lewe poddrzewo
    DFSRelease(v->right);  // usuwamy prawe poddrzewo
    delete v;              // usuwamy sam wêze³
  }
}

// **********************
// *** PROGRAM G£ÓWNY ***
// **********************

int main()
{
  BSTNode * root, * p;

  root = readBST();     // Odczytujemy drzewo BST

  if(root)
  {

    cout << "SUCCESORS    :";

    for(p = root; p; p = succBST(p))cout << setw(3) << p->key;

    cout << endl << "PREDECCESORS :";

    for(p = root; p; p = predBST(p)) cout << setw(3) << p->key;

    cout << endl;

  }
  else cout << "BST is empty!!!" << endl;

  DFSRelease(root);    // usuwamy drzewo z pamiêci

  return 0;
}

