#include <iostream>
#include <vector>
using namespace std;

struct punkty{

    int x_left;
    int y_left;
    int x_right;
    int y_right;
};


int main()
{
    int ile;
    cin >> ile;

    for(int i = 0; i < ile; i++)
    {
        punkty punkty[ile];
        int ile_figur, x1 = 0, y1 = 0, x2 = 0, y2 = 0, radius, flaga = 0;
        char jaka_figura;
        cin >> ile_figur;

        for(int j = 0; j < ile_figur; j++)
        {
            cin >> jaka_figura;

            if(jaka_figura == 'l')
            {
               cin >> x1 >> y1 >> x2 >> y2;

               if(flaga == 0)
               {
                   if(x1 < x2)
                   {
                        punkty[i].x_left = x1;
                        punkty[i].x_right = x2;
                   }

                   else
                   {
                        punkty[i].x_left = x2;
                        punkty[i].x_right = x1;
                   }

                   if(y1 < y2)
                   {
                       punkty[i].y_left = y1;
                       punkty[i].y_right = y2;
                   }

                   else
                   {
                       punkty[i].y_left = y2;
                       punkty[i].y_right = y1;
                   }

                   flaga++;
               }

               else
               {
                    if(x1 < x2)
                   {
                        if(x1 < punkty[i].x_left)
                            punkty[i].x_left = x1;
                        if(x2 > punkty[i].x_right)
                            punkty[i].x_right = x2;
                   }

                   else
                   {
                        if(x2 < punkty[i].x_left)
                            punkty[i].x_left = x1;
                        if(x1 > punkty[i].x_right)
                            punkty[i].x_right = x2;
                   }

                   if(y1 < y2)
                   {
                        if(y1 < punkty[i].y_left)
                            punkty[i].y_left = y1;
                        if(y2 > punkty[i].y_right)
                            punkty[i].y_right = y2;
                   }

                   else
                   {
                        if(y2 < punkty[i].y_left)
                            punkty[i].y_left = y2;
                        if(y1 > punkty[i].y_right)
                            punkty[i].y_right = y1;
                   }
               }

            }

            if(jaka_figura == 'c')
            {
                cin >> x1 >> y1 >> radius;
               if(flaga == 0)
               {
                   punkty[i].x_left = x1 - radius;
                   punkty[i].y_left = y1 - radius;
                   punkty[i].x_right = x1 + radius;
                   punkty[i].y_right = y1 + radius;
                   flaga++;
               }

               else
               {
                    if(x1 - radius< punkty[i].x_left)
                        punkty[i].x_left = x1 - radius;
                    if(y1 - radius < punkty[i].y_left)
                        punkty[i].y_left = y1 - radius;
                    if(x1 + radius> punkty[i].x_right)
                        punkty[i].x_right = x1 + radius;
                    if(y1 + radius > punkty[i].y_right)
                        punkty[i].y_right = y1 + radius;
               }
            }

            if(jaka_figura == 'p')
            {
                cin >> x1 >> y1;
               if(flaga == 0)
               {
                   punkty[i].x_left = x1;
                   punkty[i].y_left = y1;
                   punkty[i].x_right = x1;
                   punkty[i].y_right = y1;
                   flaga++;
               }

               else
               {
                    if(x1 < punkty[i].x_left)
                        punkty[i].x_left = x1;
                    if(y1 < punkty[i].y_left)
                        punkty[i].y_left = y1;
                    if(x1 > punkty[i].x_right)
                        punkty[i].x_right = x1;
                    if(y1 > punkty[i].y_right)
                        punkty[i].y_right = y1;
               }
            }
        }

        cout << punkty[i].x_left << " " << punkty[i].y_left << " " << punkty[i].x_right << " " << punkty[i].y_right << endl;
    }
}
