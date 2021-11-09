#include <iostream>
#include <graphics.h>
#include <stdio.h>
using namespace std;

int main()
{


    initwindow(800, 850, "The Window");
    setcolor(WHITE);
    circle(700, 150, 50);
    setfillstyle(LTBKSLASH_FILL, RED);
    floodfill(700, 150, WHITE); //params: initial seed coordinates, boundary color


    setcolor(LIGHTRED);
    rectangle(150, 500, 550, 750);
    setfillstyle(INTERLEAVE_FILL, RED);
    floodfill(300, 650, LIGHTRED);

    setcolor(LIGHTRED);
    line(400,100,200,350);
    line(200,350,600,350);
    line(600,350,400,100);
    setfillstyle(SLASH_FILL, RED);
    floodfill(400, 250, LIGHTRED);

    getch();

}
    /*
    Patterns:
    EMPTY_FILL, SOLID_FILL, LINE_FILL, LTSLASH_FILL,SLASH_FILL, BKSLASH_FILL,
    LTBKSLASH_FILL, HATCH_FILL, XHATCH_FILL, INTERLEAVE_FILL, WIDE_DOT_FILL, CLOSE_DOT_FILL, USER_FILL

    Colors:
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE
    LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
    */
