#include <iostream>
#include<graphics.h>
#include<stdio.h>
using namespace std;

int main()
{
    initwindow(800, 800, "The Window");

    // variable to change the line styles
    int c;
    // initial coordinate to draw line
    int x = 200, y = 100;
    setcolor(GREEN);
    // To keep track of lines
    for ( c = 0 ; c < 5 ; c++ )
   {
       setlinestyle(c, 0, 1);  //params: linestyle, upattern, thikness
       line(x, y, x+300, y);
       y = y + 25;
   }
    getch();
    closegraph();
}
