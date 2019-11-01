#include <iostream>
#include "Player1.h"
using namespace std;

Player1::Player1()
{
    destroyer = new int[2];
    cruiser = new int[3];
    battleship = new int[4];
    carrier = new int[5];

    for(int i = 0; i < 2; i++)
        destroyer[i] = 0;
    for(int i = 0; i < 3; i++)
        cruiser[i] = 0;
    for(int i = 0; i < 4; i++)
        battleship[i] = 0;
    for(int i = 0; i < 5; i++)
        carrier[i] = 0;
}

Player1::~Player1()
{
    delete destroyer;
    delete cruiser;
    delete battleship;
    delete carrier;
}
