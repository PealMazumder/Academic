#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;
int main()
{
    initwindow(800, 800, "The Window");

    int x1,y1,x2,y2,dx,dy,steps,i;
    float x,y,xinc,yinc;

    printf("Enter the starting coordinates: ");
    scanf("%d %d",&x1,&y1);
    printf("Enter the ending coordinates: ");
    scanf("%d %d",&x2,&y2);

    dx=x2-x1;
    dy=y2-y1;

    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    xinc=dx/(float)steps;
    yinc=dy/(float)steps;

    x=x1;
    y=y1;
    int flag = 0;
    for(i=0;i<steps;i++)
    {
        if(flag > 0)
        {
            x += xinc;
            y += yinc;
            ++flag;
            if(flag > 3) flag = 0;
        }
        else
        {
            putpixel(x,y, WHITE);
            x += xinc;
            y += yinc;
            ++flag;
        }

        delay(10);
    }

    getch();
    closegraph();

    return 0;
}
