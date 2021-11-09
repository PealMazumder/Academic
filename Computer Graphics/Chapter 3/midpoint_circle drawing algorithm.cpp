#include <stdio.h>
#include <graphics.h>
#include<iostream>
using namespace std;

void setPixel(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, WHITE);
    putpixel(xc-x, yc+y, WHITE);
    putpixel(xc+x, yc-y, WHITE);
    putpixel(xc-x, yc-y, WHITE);
    putpixel(xc+y, yc+x, WHITE);
    putpixel(xc-y, yc+x, WHITE);
    putpixel(xc+y, yc-x, WHITE);
    putpixel(xc-y, yc-x, WHITE);
}

void midpoint_circle(int xc, int yc, int r)
{
    int x=0, y=r;
    int p = 1-r;
    while(x <= y)
    {
        setPixel(xc, yc, x, y);
        if(p<0) // midpoint is inside the circle
        {
            p = p+2*x+3;
        }
        else{
            p = p+2*(x-y)+5;
            y--;
        }
        x++;
        delay(50);
    }
}

int main()
{
    int xc=300, yc=300, r=60;
    initwindow(800, 600, "The Window");
    midpoint_circle(xc, yc, r);
    getch();
    closegraph();
}

