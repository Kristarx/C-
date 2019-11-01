#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Player1.h"
#include "Player2.h"
using namespace std;

const int TOTAL_SCREEN_WIDTH = 1200;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
int ShipTrue1[100];
int ShipTrue2[100];
int ShipHit1[100];
int ShipHit2[100];
int counter1 = 0;
int counter2 = 0;
bool init();
void close();

SDL_Window* gWindow = NULL; //The window we'll be rendering to
SDL_Renderer* gRenderer = NULL; //The window renderer

class Values{

public:
    int x;
    int y;

    Values()
    {
        this->x = 0;
        this->y = 0;
    }
};

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Ships", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, TOTAL_SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

void close()
{
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void DrawGrid()
{
    for(int i = 0; i < SCREEN_HEIGHT; i += 60)
    {
        SDL_SetRenderDrawColor(gRenderer, 255, 255, 0, 255);
        SDL_RenderDrawLine(gRenderer, 0, i, SCREEN_WIDTH, i);
    }

    for(int i = 0; i <= SCREEN_WIDTH; i += 80)
    {
        SDL_SetRenderDrawColor(gRenderer, 255, 255, 0, 255);
        SDL_RenderDrawLine(gRenderer, i, 0, i, SCREEN_HEIGHT);
    }
}

int mysz(Values &val, int *ret)
{
     int X,Y;
     SDL_Event mouse;
     while(SDL_PollEvent(&mouse) != 0)
        {
            if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                X = ((mouse.button.x)/80)*80;
                Y = ((mouse.button.y)/60)*60;
                cout << X << " " << Y << endl;
                val.x = X;
                val.y = Y;
                *ret += 1;
                return 0;
            }
        }
}

void wybor_pola(Values &val, int *flag)
{
    int X,Y;
    SDL_Event mouse;
    while(SDL_PollEvent(&mouse) != 0)
    {
        if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            X = ((mouse.button.x)/80)*80;
            Y = ((mouse.button.y)/60)*60;
            val.x = X;
            val.y = Y;
            *flag +=1;
        }

        SDL_RenderPresent( gRenderer );
    }
}

void fill_rect(int X, int Y, int width, int height, int R, int G, int B)
{
    SDL_Rect fillRect = { X, Y, width, height };
    SDL_SetRenderDrawColor( gRenderer, R, G, B, 255);
    SDL_RenderFillRect( gRenderer, &fillRect );
    DrawGrid();
    SDL_RenderPresent( gRenderer );
}


int main( int argc, char* args[] )
{
    init();
    Player1 Ships1[10];
    Player2 Ships2[10];
    Values val;

    for(int i = 0; i < 100; i++)
    {
        ShipTrue1[i] = 0;
        ShipTrue2[i] = 0;
        ShipHit1[i] = 0;
        ShipHit2[i] = 0;
    }

    //Clear screen
    SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 );
    SDL_RenderClear(gRenderer);

    fill_rect(0,0,SCREEN_WIDTH, SCREEN_HEIGHT, 255, 0, 0);

    int X, Y, ret = 0;

    for(int i = 0; i < 7; i++)
    {
        bool czy = true;
        bool horiz = false;
        bool verti = false;
        bool FreePlace = false;


        if(i < 3)
        {
            while(!FreePlace)
            {
                mysz(val, &ret);
                X = val.x;
                Y = val.y;
                int kwadrat = Y*10/60 + X/80;
                if(ShipTrue1[kwadrat] == 0)
                if(ret == 1)
                {
                    FreePlace = true;
                    Ships1[i].destroyer[0] = kwadrat;
                    ShipTrue1[kwadrat] = 1;
                    fill_rect(X+1, Y+1, 79,59, 0, 100, 0);
                }

                ret = 0;
            }

            FreePlace = false;

            while(czy != false)
            {
                int kwadrat;
                while(!FreePlace)
                {
                    mysz(val, &ret);
                    X = val.x;
                    Y = val.y;
                    kwadrat = Y*10/60 + X/80;
                    if(ShipTrue1[kwadrat] == 0)
                    {
                        FreePlace = true;
                        ShipTrue1[kwadrat] = 1;

                    }
                }

                kwadrat = Y*10/60 + X/80;
                FreePlace = false;

                if((kwadrat == Ships1[i].destroyer[0]-1) || (kwadrat == Ships1[i].destroyer[0]+1) || (kwadrat == Ships1[i].destroyer[0] - 10) || (kwadrat == Ships1[i].destroyer[0] +10))
                {
                    if((kwadrat == Ships1[i].destroyer[0]-1) || (kwadrat == Ships1[i].destroyer[0]+1))
                        horiz = true;
                    else
                        verti = true;

                    Ships1[i].destroyer[1] = kwadrat;
                    czy = false;
                    fill_rect(X+1, Y+1, 79,59, 0, 100, 0);
                }
                else
                    ShipTrue1[kwadrat] = 0;
            }

            czy = true;
        }
        else if(i < 5)
        {
            while(!FreePlace)
            {
                mysz(val, &ret);
                X = val.x;
                Y = val.y;
                int kwadrat = Y*10/60 + X/80;
                if(ShipTrue1[kwadrat] == 0)
                if(ret == 1)
                {
                    FreePlace = true;
                    Ships1[i].cruiser[0] = kwadrat;
                    ShipTrue1[kwadrat] = 1;
                    fill_rect(X+1, Y+1, 79,59, 0, 200, 0);
                }

                ret = 0;
            }

            FreePlace = false;

            while(czy != false)
            {
                int kwadrat;
                while(!FreePlace)
                {
                    mysz(val, &ret);
                    X = val.x;
                    Y = val.y;
                    kwadrat = Y*10/60 + X/80;
                    if(ShipTrue1[kwadrat] == 0)
                    {
                        FreePlace = true;
                        ShipTrue1[kwadrat] = 1;

                    }
                }

                kwadrat = Y*10/60 + X/80;
                FreePlace = false;

                if((kwadrat == Ships1[i].cruiser[0]-1) || (kwadrat == Ships1[i].cruiser[0]+1) || (kwadrat == Ships1[i].cruiser[0] - 10) || (kwadrat == Ships1[i].cruiser[0] +10))
                {
                    if((kwadrat == Ships1[i].cruiser[0]-1) || (kwadrat == Ships1[i].cruiser[0]+1))
                        horiz = true;
                    else
                        verti = true;

                    Ships1[i].cruiser[1] = kwadrat;
                    czy = false;
                    fill_rect(X+1, Y+1, 79,59, 0, 200, 0);
                }
                else
                    ShipTrue1[kwadrat] = 0;
            }

            czy = true;

            while(czy == true)
            {
                int kwadrat;
                while(!FreePlace)
                {
                    mysz(val, &ret);
                    X = val.x;
                    Y = val.y;
                    kwadrat = Y*10/60 + X/80;
                    if(ShipTrue1[kwadrat] == 0)
                    {
                        FreePlace = true;
                        ShipTrue1[kwadrat] = 1;
                    }
                }

                FreePlace = false;

                if(horiz == true)
                {
                    if(Ships1[i].cruiser[0] > Ships1[i].cruiser[1])
                        swap(Ships1[i].cruiser[0], Ships1[i].cruiser[1]);

                    if(kwadrat == Ships1[i].cruiser[1] + 1)
                    {
                        Ships1[i].cruiser[2] = kwadrat;
                        czy = false;
                        fill_rect(X+1, Y+1, 79,59, 0, 200, 0);
                    }

                    if(kwadrat == Ships1[i].cruiser[0]-1)
                    {
                        Ships1[i].cruiser[2] = kwadrat;
                        czy = false;
                       fill_rect(X+1, Y+1, 79,59, 0, 200, 0);
                    }
                }

                else if(verti == true)
                {
                    if(Ships1[i].cruiser[0] > Ships1[i].cruiser[1])
                        swap(Ships1[i].cruiser[0], Ships1[i].cruiser[1]);

                    if(kwadrat == Ships1[i].cruiser[1] + 10)
                    {
                        Ships1[i].cruiser[2] = kwadrat;
                        czy = false;
                        fill_rect(X+1, Y+1, 79,59, 0, 200, 0);
                    }

                    if(kwadrat == Ships1[i].cruiser[0]-10)
                    {
                        Ships1[i].cruiser[2] = kwadrat;
                        czy = false;
                        fill_rect(X+1, Y+1, 79,59, 0, 200, 0);
                    }
                }
                else
                    ShipTrue1[kwadrat] = 0;

            }

        }
        else if(i < 6)
        {
            int j = 2;
            while(!FreePlace)
            {
                mysz(val, &ret);
                X = val.x;
                Y = val.y;
                int kwadrat = Y*10/60 + X/80;
                if(ShipTrue1[kwadrat] == 0)
                if(ret == 1)
                {
                    FreePlace = true;
                    Ships1[i].battleship[0] = kwadrat;
                    ShipTrue1[kwadrat] = 1;
                    fill_rect(X+1, Y+1, 79,59, 0, 100, 100);
                }

                ret = 0;
            }

            FreePlace = false;

            while(czy != false)
            {
                int kwadrat;
                while(!FreePlace)
                {
                    mysz(val, &ret);
                    X = val.x;
                    Y = val.y;
                    kwadrat = Y*10/60 + X/80;
                    if(ShipTrue1[kwadrat] == 0)
                    {
                        FreePlace = true;
                        ShipTrue1[kwadrat] = 1;

                    }
                }

                kwadrat = Y*10/60 + X/80;
                FreePlace = false;

                if((kwadrat == Ships1[i].battleship[0]-1) || (kwadrat == Ships1[i].battleship[0]+1) || (kwadrat == Ships1[i].battleship[0] - 10) || (kwadrat == Ships1[i].battleship[0] +10))
                {
                    if((kwadrat == Ships1[i].battleship[0]-1) || (kwadrat == Ships1[i].battleship[0]+1))
                        horiz = true;
                    else
                        verti = true;

                    Ships1[i].battleship[1] = kwadrat;
                    czy = false;
                    fill_rect(X+1, Y+1, 79,59, 0, 100, 100);
                }
                else
                    ShipTrue1[kwadrat] = 0;
            }

            czy = true;

            while(j < 4)
            {
                while(czy == true)
                {
                    int kwadrat;
                    while(!FreePlace)
                    {
                        mysz(val, &ret);
                        X = val.x;
                        Y = val.y;
                        kwadrat = Y*10/60 + X/80;
                        if(ShipTrue1[kwadrat] == 0)
                            FreePlace = true;
                    }

                    FreePlace = false;

                    if(horiz == true)
                    {
                        for(int k = 0; k < j; k++)
                        if(((kwadrat == Ships1[i].battleship[k] + 1) || (kwadrat == Ships1[i].battleship[k] - 1)) && ShipTrue1[kwadrat] == 0)
                        {
                            Ships1[i].battleship[k] = kwadrat;
                            czy = false;
                            Ships1[i].battleship[j] = kwadrat;
                            ShipTrue1[kwadrat] = 1;
                            fill_rect(X+1, Y+1, 79,59, 0, 100, 100);
                        }
                    }

                    else if(verti == true)
                    {
                        for(int k = 0; k < j; k++)
                        if(((kwadrat == Ships1[i].battleship[k] + 10) || (kwadrat == Ships1[i].battleship[k] - 10)) && ShipTrue1[kwadrat] == 0)
                        {
                            Ships1[i].battleship[k] = kwadrat;
                            czy = false;
                            Ships1[i].battleship[j] = kwadrat;
                            ShipTrue1[kwadrat] = 1;
                            fill_rect(X+1, Y+1, 79,59, 0, 100, 100);
                        }
                    }
                    else
                        ShipTrue1[kwadrat] = 0;

                }
                czy = true;
                j++;
            }

        }
        else if(i == 6)
        {
            int j = 2;
            while(!FreePlace)
            {
                mysz(val, &ret);
                X = val.x;
                Y = val.y;
                int kwadrat = Y*10/60 + X/80;
                if(ShipTrue1[kwadrat] == 0)
                if(ret == 1)
                {
                    FreePlace = true;
                    Ships1[i].carrier[0] = kwadrat;
                    ShipTrue1[kwadrat] = 1;
                    fill_rect(X+1, Y+1, 79,59, 0, 200, 100);
                }

                ret = 0;
            }

            FreePlace = false;

            while(czy != false)
            {
                int kwadrat;
                while(!FreePlace)
                {
                    mysz(val, &ret);
                    X = val.x;
                    Y = val.y;
                    kwadrat = Y*10/60 + X/80;
                    if(ShipTrue1[kwadrat] == 0)
                    {
                        FreePlace = true;
                        ShipTrue1[kwadrat] = 1;

                    }
                }

                kwadrat = Y*10/60 + X/80;
                FreePlace = false;

                if((kwadrat == Ships1[i].carrier[0]-1) || (kwadrat == Ships1[i].carrier[0]+1) || (kwadrat == Ships1[i].carrier[0] - 10) || (kwadrat == Ships1[i].carrier[0] +10))
                {
                    if((kwadrat == Ships1[i].carrier[0]-1) || (kwadrat == Ships1[i].carrier[0]+1))
                        horiz = true;
                    else
                        verti = true;

                    Ships1[i].carrier[1] = kwadrat;
                    czy = false;
                    fill_rect(X+1, Y+1, 79,59, 0, 200, 100);
                }
                else
                    ShipTrue1[kwadrat] = 0;
            }

            czy = true;

            while(j < 5)
            {
                while(czy == true)
                {
                    int kwadrat;
                    while(!FreePlace)
                    {
                        mysz(val, &ret);
                        X = val.x;
                        Y = val.y;
                        kwadrat = Y*10/60 + X/80;
                        if(ShipTrue1[kwadrat] == 0)
                            FreePlace = true;
                    }

                    FreePlace = false;

                    if(horiz == true)
                    {
                        for(int k = 0; k < j; k++)
                        if(((kwadrat == Ships1[i].carrier[k] + 1) || (kwadrat == Ships1[i].carrier[k] - 1)) && ShipTrue1[kwadrat] == 0)
                        {
                            Ships1[i].carrier[k] = kwadrat;
                            czy = false;
                            Ships1[i].carrier[j] = kwadrat;
                            ShipTrue1[kwadrat] = 1;
                            fill_rect(X+1, Y+1, 79,59, 0, 200, 100);
                        }
                    }

                    else if(verti == true)
                    {
                        for(int k = 0; k < j; k++)
                        if(((kwadrat == Ships1[i].carrier[k] + 10) || (kwadrat == Ships1[i].carrier[k] - 10)) && ShipTrue1[kwadrat] == 0)
                        {
                            Ships1[i].carrier[k] = kwadrat;
                            czy = false;
                            Ships1[i].carrier[j] = kwadrat;
                            ShipTrue1[kwadrat] = 1;
                            fill_rect(X+1, Y+1, 79,59, 0, 200, 100);
                        }
                    }
                    else
                        ShipTrue1[kwadrat] = 0;
                }
                czy = true;
                j++;
            }
        }
    }

    SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 255 );
    SDL_RenderClear(gRenderer);

    fill_rect(0,0,SCREEN_WIDTH, SCREEN_HEIGHT, 255, 0, 0);

    for(int i = 0; i < 7; i++)
    {
        bool czy = true;
        bool horiz = false;
        bool verti = false;
        bool FreePlace = false;

        if(i < 3)
        {
            while(!FreePlace)
            {
                mysz(val, &ret);
                X = val.x;
                Y = val.y;
                int kwadrat = Y*10/60 + X/80;
                if(ShipTrue2[kwadrat] == 0)
                if(ret == 1)
                {
                    FreePlace = true;
                    Ships2[i].destroyer[0] = kwadrat;
                    ShipTrue2[kwadrat] = 1;
                    fill_rect(X+1, Y+1, 79,59, 0, 100, 0);
                }

                ret = 0;
            }

            FreePlace = false;

            while(czy != false)
            {
                int kwadrat;
                while(!FreePlace)
                {
                    mysz(val, &ret);
                    X = val.x;
                    Y = val.y;
                    kwadrat = Y*10/60 + X/80;
                    if(ShipTrue2[kwadrat] == 0)
                    {
                        FreePlace = true;
                        ShipTrue2[kwadrat] = 1;

                    }
                }

                kwadrat = Y*10/60 + X/80;
                FreePlace = false;

                if((kwadrat == Ships2[i].destroyer[0]-1) || (kwadrat == Ships2[i].destroyer[0]+1) || (kwadrat == Ships2[i].destroyer[0] - 10) || (kwadrat == Ships2[i].destroyer[0] +10))
                {
                    if((kwadrat == Ships2[i].destroyer[0]-1) || (kwadrat == Ships2[i].destroyer[0]+1))
                        horiz = true;
                    else
                        verti = true;

                    Ships2[i].destroyer[1] = kwadrat;
                    czy = false;
                    fill_rect(X+1, Y+1, 79,59, 0, 100, 0);
                }
                else
                    ShipTrue2[kwadrat] = 0;
            }

            czy = true;
        }
        else if(i < 5)
        {
            while(!FreePlace)
            {
                mysz(val, &ret);
                X = val.x;
                Y = val.y;
                int kwadrat = Y*10/60 + X/80;
                if(ShipTrue2[kwadrat] == 0)
                if(ret == 1)
                {
                    FreePlace = true;
                    Ships2[i].cruiser[0] = kwadrat;
                    ShipTrue2[kwadrat] = 1;
                    fill_rect(X+1, Y+1, 79,59, 0, 200, 0);
                }

                ret = 0;
            }

            FreePlace = false;

            while(czy != false)
            {
                int kwadrat;
                while(!FreePlace)
                {
                    mysz(val, &ret);
                    X = val.x;
                    Y = val.y;
                    kwadrat = Y*10/60 + X/80;
                    if(ShipTrue2[kwadrat] == 0)
                    {
                        FreePlace = true;
                        ShipTrue2[kwadrat] = 1;

                    }
                }

                kwadrat = Y*10/60 + X/80;
                FreePlace = false;

                if((kwadrat == Ships2[i].cruiser[0]-1) || (kwadrat == Ships2[i].cruiser[0]+1) || (kwadrat == Ships2[i].cruiser[0] - 10) || (kwadrat == Ships2[i].cruiser[0] +10))
                {
                    if((kwadrat == Ships2[i].cruiser[0]-1) || (kwadrat == Ships2[i].cruiser[0]+1))
                        horiz = true;
                    else
                        verti = true;

                    Ships2[i].cruiser[1] = kwadrat;
                    czy = false;
                    fill_rect(X+1, Y+1, 79,59, 0, 200, 0);
                }
                else
                    ShipTrue2[kwadrat] = 0;
            }

            czy = true;

            while(czy == true)
            {
                int kwadrat;
                while(!FreePlace)
                {
                    mysz(val, &ret);
                    X = val.x;
                    Y = val.y;
                    kwadrat = Y*10/60 + X/80;
                    if(ShipTrue2[kwadrat] == 0)
                    {
                        FreePlace = true;
                        ShipTrue2[kwadrat] = 1;
                    }
                }

                FreePlace = false;

                if(horiz == true)
                {
                    if(Ships2[i].cruiser[0] > Ships2[i].cruiser[1])
                        swap(Ships2[i].cruiser[0], Ships2[i].cruiser[1]);

                    if(kwadrat == Ships2[i].cruiser[1] + 1)
                    {
                        Ships2[i].cruiser[2] = kwadrat;
                        czy = false;
                        fill_rect(X+1, Y+1, 79,59, 0, 200, 0);
                    }

                    if(kwadrat == Ships2[i].cruiser[0]-1)
                    {
                        Ships2[i].cruiser[2] = kwadrat;
                        czy = false;
                        fill_rect(X+1, Y+1, 79,59, 0, 200, 0);
                    }

                }

                else if(verti == true)
                {
                    if(Ships2[i].cruiser[0] > Ships2[i].cruiser[1])
                        swap(Ships2[i].cruiser[0], Ships2[i].cruiser[1]);

                    if(kwadrat == Ships2[i].cruiser[1] + 10)
                    {
                        Ships2[i].cruiser[2] = kwadrat;
                        czy = false;
                        fill_rect(X+1, Y+1, 79,59, 0, 200, 0);
                    }

                    if(kwadrat == Ships2[i].cruiser[0]-10)
                    {
                        Ships2[i].cruiser[2] = kwadrat;
                        czy = false;
                        fill_rect(X+1, Y+1, 79,59, 0, 200, 0);
                    }
                }
                else
                    ShipTrue2[kwadrat] = 0;
            }

        }
        else if(i < 6)
        {
            int j = 2;
            while(!FreePlace)
            {
                mysz(val, &ret);
                X = val.x;
                Y = val.y;
                int kwadrat = Y*10/60 + X/80;
                if(ShipTrue2[kwadrat] == 0)
                if(ret == 1)
                {
                    FreePlace = true;
                    Ships2[i].battleship[0] = kwadrat;
                    ShipTrue2[kwadrat] = 1;
                    fill_rect(X+1, Y+1, 79,59, 0, 100, 100);
                }

                ret = 0;
            }

            FreePlace = false;

            while(czy != false)
            {
                int kwadrat;
                while(!FreePlace)
                {
                    mysz(val, &ret);
                    X = val.x;
                    Y = val.y;
                    kwadrat = Y*10/60 + X/80;
                    if(ShipTrue2[kwadrat] == 0)
                    {
                        FreePlace = true;
                        ShipTrue2[kwadrat] = 1;

                    }
                }

                kwadrat = Y*10/60 + X/80;
                FreePlace = false;

                if((kwadrat == Ships2[i].battleship[0]-1) || (kwadrat == Ships2[i].battleship[0]+1) || (kwadrat == Ships2[i].battleship[0] - 10) || (kwadrat == Ships2[i].battleship[0] +10))
                {
                    if((kwadrat == Ships2[i].battleship[0]-1) || (kwadrat == Ships2[i].battleship[0]+1))
                        horiz = true;
                    else
                        verti = true;

                    Ships2[i].battleship[1] = kwadrat;
                    czy = false;
                    fill_rect(X+1, Y+1, 79,59, 0, 100, 100);
                }
                else
                    ShipTrue2[kwadrat] = 0;
            }

            czy = true;

            while(j < 4)
            {
                while(czy == true)
                {
                    int kwadrat;
                    while(!FreePlace)
                    {
                        mysz(val, &ret);
                        X = val.x;
                        Y = val.y;
                        kwadrat = Y*10/60 + X/80;
                        if(ShipTrue2[kwadrat] == 0)
                            FreePlace = true;
                    }

                    FreePlace = false;

                    if(horiz == true)
                    {
                        for(int k = 0; k < j; k++)
                        if(((kwadrat == Ships2[i].battleship[k] + 1) || (kwadrat == Ships2[i].battleship[k] - 1)) && ShipTrue2[kwadrat] == 0)
                        {
                            Ships2[i].battleship[k] = kwadrat;
                            czy = false;
                            Ships2[i].battleship[j] = kwadrat;
                            ShipTrue2[kwadrat] = 1;
                            fill_rect(X+1, Y+1, 79,59, 0, 100, 100);
                        }
                    }

                    else if(verti == true)
                    {
                        for(int k = 0; k < j; k++)
                        if(((kwadrat == Ships2[i].battleship[k] + 10) || (kwadrat == Ships2[i].battleship[k] - 10)) && ShipTrue2[kwadrat] == 0)
                        {
                            Ships2[i].battleship[k] = kwadrat;
                            czy = false;
                            Ships2[i].battleship[j] = kwadrat;
                            ShipTrue2[kwadrat] = 1;
                            fill_rect(X+1, Y+1, 79,59, 0, 100, 100);
                        }
                    }
                    else
                        ShipTrue2[kwadrat] = 0;

                }
                czy = true;
                j++;
            }

        }
        else if(i == 6)
        {
            int j = 2;
            while(!FreePlace)
            {
                mysz(val, &ret);
                X = val.x;
                Y = val.y;
                int kwadrat = Y*10/60 + X/80;
                if(ShipTrue2[kwadrat] == 0)
                if(ret == 1)
                {
                    FreePlace = true;
                    Ships2[i].carrier[0] = kwadrat;
                    ShipTrue2[kwadrat] = 1;
                    fill_rect(X+1, Y+1, 79,59, 0, 200, 100);
                }

                ret = 0;
            }

            FreePlace = false;

            while(czy != false)
            {
                int kwadrat;
                while(!FreePlace)
                {
                    mysz(val, &ret);
                    X = val.x;
                    Y = val.y;
                    kwadrat = Y*10/60 + X/80;
                    if(ShipTrue2[kwadrat] == 0)
                    {
                        FreePlace = true;
                        ShipTrue2[kwadrat] = 1;

                    }
                }

                kwadrat = Y*10/60 + X/80;
                FreePlace = false;

                if((kwadrat == Ships2[i].carrier[0]-1) || (kwadrat == Ships2[i].carrier[0]+1) || (kwadrat == Ships2[i].carrier[0] - 10) || (kwadrat == Ships2[i].carrier[0] +10))
                {
                    if((kwadrat == Ships2[i].carrier[0]-1) || (kwadrat == Ships2[i].carrier[0]+1))
                        horiz = true;
                    else
                        verti = true;

                    Ships2[i].carrier[1] = kwadrat;
                    czy = false;
                    fill_rect(X+1, Y+1, 79,59, 0, 200, 100);
                }
                else
                    ShipTrue2[kwadrat] = 0;
            }

            czy = true;

            while(j < 5)
            {
                while(czy == true)
                {
                    int kwadrat;
                    while(!FreePlace)
                    {
                        mysz(val, &ret);
                        X = val.x;
                        Y = val.y;
                        kwadrat = Y*10/60 + X/80;
                        if(ShipTrue2[kwadrat] == 0)
                            FreePlace = true;
                    }

                    FreePlace = false;

                    if(horiz == true)
                    {
                        for(int k = 0; k < j; k++)
                        if(((kwadrat == Ships2[i].carrier[k] + 1) || (kwadrat == Ships2[i].carrier[k] - 1)) && ShipTrue2[kwadrat] == 0)
                        {
                            Ships2[i].carrier[k] = kwadrat;
                            czy = false;
                            Ships2[i].carrier[j] = kwadrat;
                            ShipTrue2[kwadrat] = 1;
                            fill_rect(X+1, Y+1, 79,59, 0, 200, 100);
                        }
                    }

                    else if(verti == true)
                    {
                        for(int k = 0; k < j; k++)
                        if(((kwadrat == Ships2[i].carrier[k] + 10) || (kwadrat == Ships2[i].carrier[k] - 10)) && ShipTrue2[kwadrat] == 0)
                        {
                            Ships2[i].carrier[k] = kwadrat;
                            czy = false;
                            Ships2[i].carrier[j] = kwadrat;
                            ShipTrue2[kwadrat] = 1;
                            fill_rect(X+1, Y+1, 79,59, 0, 200, 100);
                        }
                    }
                    else
                        ShipTrue2[kwadrat] = 0;

                }
                czy = true;
                j++;
            }
        }
    }

    bool win = true;
    bool first_player_step = true;
    bool second_player_step = false;
    int flag = 0;
    cout << " Jestem przed while" << endl;

    SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 255 );
    SDL_RenderClear(gRenderer);

    fill_rect(0,0,SCREEN_WIDTH, SCREEN_HEIGHT, 255, 0, 0);

    while(win)
    {
        wybor_pola(val, &flag);

        if((flag != 0) && (first_player_step == true))
        {
            cout << "Gracz1" << endl;
            int kwadrat = val.y*10/60 + val.x/80;
            cout << kwadrat << endl;
            if(ShipTrue2[kwadrat] == 1)
            {
                if(ShipHit2[kwadrat] == 1)
                    cout << "Cel juz zajety" << endl;
                else
                {
                    ShipHit2[kwadrat] = 1;
                    counter1++;
                }

                for(int i = 0; i < 100; i++)
                {
                    if(i%10 == 0)
                        cout << endl;
                    cout << ShipHit2[i] << " ";
                }
                    int yolo = kwadrat/10;
                    if(ShipHit2[kwadrat] == 1)
                    {
                        if(ShipTrue2[kwadrat] == 1)
                            fill_rect(((kwadrat%10)*80)+1, (yolo*60)+1, 79,59, 0, 150, 150);
                        else
                            fill_rect(((kwadrat%10)*80)+1, (yolo*60)+1, 79,59, 0, 50, 50);
                    }
                    else
                        continue;
            }

            else
            {
                ShipHit2[kwadrat] = 1;
                first_player_step = false;
                second_player_step = true;
                cout << "Gracz1 zle XD" << endl;
                fill_rect(0,0,SCREEN_WIDTH, SCREEN_HEIGHT, 255, 0, 0);

                for(int i = 0; i < 100; i++)
                {
                    if(ShipHit1[i] == 1)
                    {
                        int yolo = i/10;
                        if(ShipTrue1[i] == 1)
                            fill_rect(((i%10)*80)+1, (yolo*60)+1, 79,59, 0, 150, 150);
                        else
                            fill_rect(((i%10)*80)+1, (yolo*60)+1, 79,59, 0, 50, 50);
                    }
                }
            }

            flag = 0;
        }

        if((flag != 0) && (second_player_step == true))
        {
            cout << "Gracz2" << endl;
            int kwadrat = val.y*10/60 + val.x/80;
            cout << kwadrat << endl;
            if(ShipTrue1[kwadrat] == 1)
            {
                if(ShipHit1[kwadrat] == 1)
                    cout << "Cel juz zajety" << endl;
                else
                {
                    ShipHit1[kwadrat] = 1;
                    counter2++;
                }

                if(ShipHit1[kwadrat] == 1)
                {
                    int yolo = kwadrat/10;
                    if(ShipTrue1[kwadrat] == 1)
                        fill_rect(((kwadrat%10)*80)+1, (yolo*60)+1, 79,59, 0, 150, 150);
                    else
                        fill_rect(((kwadrat%10)*80)+1, (yolo*60)+1, 79,59, 0, 50, 50);
                }
            }

            else
            {
                ShipHit1[kwadrat] = 1;
                first_player_step = true;
                second_player_step = false;
                cout << "Gracz2 zle XD" << endl;

                fill_rect(0,0,SCREEN_WIDTH, SCREEN_HEIGHT, 255, 0, 0);

                for(int i = 0; i < 100; i++)
                {
                    int yolo = i/10;
                    if(ShipHit2[i] == 1)
                    {
                        if(ShipTrue2[i] == 1)
                            fill_rect(((i%10)*80)+1, (yolo*60)+1, 79,59, 0, 150, 150);
                        else
                            fill_rect(((i%10)*80)+1, (yolo*60)+1, 79,59, 0, 50, 50);
                    }

                    else
                        continue;
                }
            }

            flag = 0;
        }

        if(counter1 == 21 || counter2 == 21)
        {
            if(counter1 == 21)
                cout << "Wygral gracz 1!" << endl;
            else
                cout << "Wygral gracz 2!" << endl;
            break;
        }
    }

	//Free resources and close SDL
	while(1)
    {
        int znak = getch();
        if(znak == 'a')
            close();
    }

	return 0;
}
