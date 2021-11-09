#include<iostream>
#include<graphics.h>
#include<stdio.h>
void bresenham_line(int X1, int Y1, int X2, int Y2)
{

    int dx = X2 - X1;
    int dy = Y2 - Y1;

    int x = X1;
    int y = Y1;

    //when slope(m) < 1
    if(abs(dx) > abs(dy))
    {
        putpixel(x,y,GREEN);
        int pk = (2 * abs(dy)) - abs(dx);

        for(int i = 0; i < abs(dx) ; i++)
        {
            x++;
            if(pk < 0)
                pk = pk + (2 * abs(dy));
            else
            {
                y++;
                pk = pk + (2 * abs(dy)) - (2 * abs(dx));
            }
            putpixel(x,y,GREEN);
            delay(10);
        }
        delay(30);
    }
    else
    {
        //when m>=1
        putpixel(x,y,WHITE);
        int pk = (2 * abs(dx)) - abs(dy);

        for(int i = 0; i < abs(dy) ; i++)
        {
            y++;
            if(pk < 0)
                pk = pk + (2 * abs(dx));
            else
            {
                x++;
                pk = pk + (2 * abs(dx)) - (2 *abs(dy));
            }

            putpixel(x,y,WHITE);
            delay(10);
        }

        delay(30);
    }
}

int main()
{
    initwindow(1280, 720, "The graphics Window");
    int x1, y1, x2, y2;
    printf("Enter x1 y1 x2 y2: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    bresenham_line(x1, y1, x2, y2);
    getch();
}
