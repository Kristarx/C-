#include <iostream>
#include "Player2.h"
using namespace std;

Player2::Player2()
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

Player2::~Player2()
{
    delete destroyer;
    delete cruiser;
    delete battleship;
    delete carrier;
}
