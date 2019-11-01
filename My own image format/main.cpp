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
#include <iostream>

using namespace std;

bool compare(SDL_Color x1, SDL_Color x2)
{
    if(x1.r==x2.r && x1.b==x2.b && x1.g==x2.g)
        return true;
    else false;
}

SDL_Surface *screen;
int width = 900;
int height = 600;
char const* tytul = "Obraz.mnl";

void ladujBMP(char const* nazwa, int x, int y);
void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B);
SDL_Color getPixel (int x, int y);

void czyscEkran(Uint8 R, Uint8 G, Uint8 B);

SDL_Color paleta[8]={{255, 0, 0}, {0, 255, 0}, {0, 0, 255},
{0, 0, 0}, {255, 255, 255}, {51, 0, 102},
{255, 102, 178}, {51, 25, 0}
};

void ladujBMP(char const* nazwa, int x, int y);


void Funkcja1();
void Funkcja2();
void Funkcja3();



void Funkcja1() {
//8 kolorow narzucone

for(int x=0;x<width/2;x++)
    {
        int rr,gg,bb;
        for(int y=0;y<height/2;y++){
            SDL_Color color = getPixel(x,y);
            int s=127;
            if(color.r<127)
                rr=0;
            else
                rr=255;

            if(color.g<127)
                gg=0;
            else
                gg=255;

            if(color.b<127)
                bb=0;
            else
                bb=255;

            setPixel(x,y,rr,gg,bb);

        }
    }



    SDL_Flip(screen);

}


void Funkcja2() {


for(int x=0;x<width/2;x++)
    {
        int BW;
        int rr,gg,bb;
        for(int y=0;y<height/2;y++){
            SDL_Color kolor = getPixel(x,y);

            BW=0.299*kolor.r +0.587*kolor.g+0.114*kolor.b;

            if(BW<36)
            {
                rr=gg=bb=0;
            }
            else
            if(BW<72)
            {
                rr=gg=bb=36;
            }
            else
            if(BW<109)
            {
                rr=gg=bb=72;
            }
            else
            if(BW<145)
            {
                rr=gg=bb=109;
            }
            else
            if(BW<182)
            {
                rr=gg=bb=145;
            }
            else
            if(BW<218)
            {
                rr=gg=bb=182;
            }
            else
            if(BW<255)
            {
                rr=gg=bb=218;
            }
            else
            {
                rr=gg=bb=255;
            }

            setPixel(x,y,rr,gg,bb);
        }
    }



    SDL_Flip(screen);

}


void Funkcja3() {
    int min=0,id=0,min2=0;
    float BW;
    SDL_Color kolor;

    for(int y=0; y<height/2; y++)
    {
        for(int x=0; x<width/2; x++)
        {
            kolor=getPixel(x,y);
            min=abs(paleta[0].r-kolor.r) +abs(paleta[0].g-kolor.g)+abs(paleta[0].b-kolor.b);
            if(min<0)
                min*=-1;

            id=0;
            for(int i=1;i<8;i++){
                min2=abs(paleta[i].r-kolor.r) +abs(paleta[i].g-kolor.g)+abs(paleta[i].b-kolor.b);
                if(min2<0)
                    min2*=-1;

                if(min2<min){
                    min=min2;
                    id=i;
                }

            }

            setPixel(x, y, paleta[id].r, paleta[id].g, paleta[id].b);
        }
    }

    SDL_Flip(screen);

}




void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B)
{
  if ((x>=0) && (x<width) && (y>=0) && (y<height))
  {

    Uint32 pixel = SDL_MapRGB(screen->format, R, G, B);

    int bpp = screen->format->BytesPerPixel;


    Uint8 *p = (Uint8 *)screen->pixels + y * screen->pitch + x * bpp;


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


void ladujBMP(char const* nazwa, int x, int y)
{
    SDL_Surface* bmp = SDL_LoadBMP(nazwa);
    if (!bmp)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
    }
    else
    {
        SDL_Rect dstrect;
        dstrect.x = x;
        dstrect.y = y;
        SDL_BlitSurface(bmp, 0, screen, &dstrect);
        SDL_Flip(screen);
        SDL_FreeSurface(bmp);
    }
}


void czyscEkran(Uint8 R, Uint8 G, Uint8 B)
{
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, R, G, B));
    SDL_Flip(screen);

}




SDL_Color getPixel (int x, int y) {
    SDL_Color color ;
    Uint32 col = 0 ;
    if ((x>=0) && (x<width) && (y>=0) && (y<height)) {
        //determine position
        char* pPosition=(char*)screen->pixels ;
        //offset by y
        pPosition+=(screen->pitch*y) ;
        //offset by x
        pPosition+=(screen->format->BytesPerPixel*x);
        //copy pixel data
        memcpy(&col, pPosition, screen->format->BytesPerPixel);
        //convert color
        SDL_GetRGB(col, screen->format, &color.r, &color.g, &color.b);
    }
    return ( color ) ;
}







int main ( int argc, char** argv )
{
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
                        if (event.key.keysym.sym == SDLK_1)
                            Funkcja1();
                        if (event.key.keysym.sym == SDLK_2)
                            Funkcja2();
                        if (event.key.keysym.sym == SDLK_3)
                            Funkcja3();
                        if (event.key.keysym.sym == SDLK_a)
                            ladujBMP("obrazek1a.bmp", 0, 0);
                        if (event.key.keysym.sym == SDLK_s)
                            ladujBMP("obrazek2a.bmp", 0, 0);
                        if (event.key.keysym.sym == SDLK_d)
                            ladujBMP("obrazek3a.bmp", 0, 0);
                        if (event.key.keysym.sym == SDLK_f)
                            ladujBMP("waterfall.bmp", 0, 0);
                        if (event.key.keysym.sym == SDLK_g)
                            ladujBMP("COLORFUL.bmp", 0, 0);
                        if (event.key.keysym.sym == SDLK_b)
                            czyscEkran(0, 0, 10);          break;

                }
            }
        }

    }



    printf("Exited cleanly\n");
    return 0;
}
