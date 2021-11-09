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

void bresenham_circle(int xc, int yc, int r)
{
    int x=0, y=r;
    int d = 3-2*r;
    while(x <= y)
    {
        setPixel(xc, yc, x, y);
        if(d<0)
        {
            d = d+4*x+6;
        }
        else{
            d = d+4*(x-y)+10;
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
    bresenham_circle(xc, yc, r);
    getch();
    closegraph();
}

