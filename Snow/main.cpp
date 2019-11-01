#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>

#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif
#include <math.h>
#define pi 3.14
#include <time.h>
#include <windows.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

SDL_Surface *screen;
int width = 900;
int height = 600;
char const* title = "Snow";

/*Description of snowflake*/

struct platek{

    int x = rand()%width;
    int y = rand()%height-height;
    int degrees = rand()%360;
    int wspolczynnik_sinus = rand()%40+5;
    int sinus = wspolczynnik_sinus*sin(degrees * M_PI/180);
    int odcien = rand()%240+15;
    int szybkosc = rand()%3;
};



void Funkcja2();
void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B);
SDL_Color getPixel (int x, int y);



/*Function drawing the shade of grey - minimal value RGB = 15, 15, 15*/

int odcienBialego()
{
    int odcien = rand()%240+15;
    return odcien;
}


void Funkcja2() {

platek platek[200];

    while(1)
    {

        SDL_FillRect(screen, NULL, 0x000000);       //clean the display after every for loop
        for(int i = 0; i < 200; i++)                //max 200 snowflakes
        {
            platek[i].y = platek[i].y + platek[i].szybkosc + 1;
            platek[i].sinus = platek[i].wspolczynnik_sinus*sin(platek[i].degrees * M_PI/180);

            /*snowflake drawing*/
            for(int k = 0; k < 9; k++)
            {
                if(k == 0 || k == 8)
                {
                    setPixel(platek[i].x+platek[i].sinus, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
                    setPixel(platek[i].x+platek[i].sinus+4, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
                    setPixel(platek[i].x+platek[i].sinus+8, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
                }

                if(k == 1 || k == 7)
                {
                    setPixel(platek[i].x+platek[i].sinus+1, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
                    setPixel(platek[i].x+platek[i].sinus+4, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
                    setPixel(platek[i].x+platek[i].sinus+7, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
                }

                if(k == 2 || k == 6)
                {
                    setPixel(platek[i].x+platek[i].sinus+2, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
                    setPixel(platek[i].x+platek[i].sinus+4, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
                    setPixel(platek[i].x+platek[i].sinus+6, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
                }

                if(k == 3 || k == 5)
                {
                    setPixel(platek[i].x+platek[i].sinus+3, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
                    setPixel(platek[i].x+platek[i].sinus+4, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
                    setPixel(platek[i].x+platek[i].sinus+5, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
                }

                if(k == 4)
                    for(int j = 0; j < 9; j++)
                        setPixel(platek[i].x+platek[i].sinus+j, platek[i].y+k, platek[i].odcien, platek[i].odcien, platek[i].odcien);
            }


            platek[i].degrees += 2;

            /*if snowflake disappear under the display the new one is creating*/

            if(platek[i].y >= height)
            {
                platek[i].y = 0;
                platek[i].x = rand()%width;
                platek[i].degrees = rand()%360;
                platek[i].wspolczynnik_sinus = rand()%40+20;
                platek[i].sinus = platek[i].wspolczynnik_sinus*sin(platek[i].degrees * M_PI/180);
                platek[i].odcien = odcienBialego();
                platek[i].szybkosc = rand()%3;
            }

        }

        SDL_Flip(screen);
        Sleep(15);              //delay snowflake falling
    }

    SDL_Flip(screen);
}



void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B)
{
  if ((x>=0) && (x<width) && (y>=0) && (y<height))
  {
    /*Change every sinlge colour element on pixel colour's format*/
    Uint32 pixel = SDL_MapRGB(screen->format, R, G, B);

    /* Get info pixel size in bytes*/
    int bpp = screen->format->BytesPerPixel;

    /* we count pixel address*/
    Uint8 *p = (Uint8 *)screen->pixels + y * screen->pitch + x * bpp;

    /* Set pixel value in dependence on surface format*/
    switch(bpp)
    {
        case 1: //8-bit
            *p = pixel;
            break;

        case 2: //16-bit
            *(Uint16 *)p = pixel;
            break;

        case 3: //24-bit
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                p[0] = (pixel >> 16) & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = pixel & 0xff;
            } else {
                p[0] = pixel & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = (pixel >> 16) & 0xff;
            }
            break;

        case 4: //32-bit
            *(Uint32 *)p = pixel;
            break;

    }
         /* update the screen (aka double buffering) */
  }
}


int main ( int argc, char** argv )
{
    srand(time(NULL));
    // console output
    freopen( "CON", "wt", stdout );
    freopen( "CON", "wt", stderr );

    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    screen = SDL_SetVideoMode(width, height, 32,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set video: %s\n", SDL_GetError());
        return 1;
    }

    SDL_WM_SetCaption( tytul , NULL );
    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    if (event.key.keysym.sym == SDLK_2)
                        Funkcja2();
                        break;
                    }
            } // end switch
        } // end of message processing

    } // end main loop


    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
