#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int main()
{
    initwindow(800, 850, "The Window");
    srand(time(0));
    int pattern = rand() % 4;

    switch(pattern)
    {
    case 0:
        setcolor(LIGHTRED);
        line(100, 100, 100, 500);
        line(100, 100, 200, 100);
        line(200, 100, 200, 300);
        line(200, 300, 100, 300);
        setcolor(MAGENTA);
        line(300, 100, 300, 500);
        line(300, 100, 400, 100);
        line(300, 300, 400, 300);
        line(300, 500, 400, 500);
        setcolor(WHITE);
        line(500, 100, 400, 500);
        line(500, 100, 600, 500);
        line(450, 300, 550, 300);

        setcolor(LIGHTGREEN);
        line(600, 100, 600, 500);
        line(600, 500, 750, 500);

        break;
    case 1:
        setcolor(WHITE);
        circle(400, 250, 50);
        setfillstyle(LTBKSLASH_FILL, RED);
        floodfill(400, 250, WHITE);
        break;
    case 2:
        setcolor(LIGHTRED);
        rectangle(150, 500, 550, 750);
        setfillstyle(INTERLEAVE_FILL, RED);
        floodfill(300, 650, LIGHTRED);
        break;
    case 3:
        setcolor(LIGHTRED);
        line(400,100,200,350);
        line(200,350,600,350);
        line(600,350,400,100);
        setfillstyle(SLASH_FILL, RED);
        floodfill(400, 250, LIGHTRED);
        break;

    }
    getch();
    closegraph();

    return 0;
}
