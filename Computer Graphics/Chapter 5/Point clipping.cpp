#include<stdio.h>
#include<graphics.h>
#include<iostream>
using namespace std;
void point_clip(int left, int top, int right, int bottom, int x, int y)
{
    if(x>=left && x<=right)
        if(y>=top && y<=bottom)
            {
             putpixel(x, y, WHITE);
             circle(x, y, 2);
            }

    getch();
}
int main()
{
    int left, top, right, bottom, x, y;
    printf("Enter the window coordinate: ");
    cin>>left>>top>>right>>bottom;
    printf("\n Enter the point coordinate: ");
    cin>>x>>y;
    initwindow(800, 600, "The Window");

    rectangle(left, top, right, bottom);
    point_clip(left, top, right, bottom, x, y);
}

