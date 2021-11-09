#include<iostream>
#include<stdio.h>
#include<graphics.h>
using namespace std;

void setPixel(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, WHITE);
    putpixel(xc-x, yc+y, WHITE);
    putpixel(xc+x, yc-y, WHITE);
    putpixel(xc-x, yc-y, WHITE);
}

void ellipse_midpoint(int xc, int yc, int a, int b){
    int x=0, y=b;
    int aa=a*a, bb=b*b, aa2=aa*2, bb2=bb*2;
    int fx=0, fy=aa2*b;
    int p = bb - aa*b + 0.25*aa;
    while (fx < fy){ //|slope| < 1
        setPixel(xc, yc, x, y);
        x++;
        fx = fx+bb2;
        if(p<0) p = p+fx+bb;
        else{
            y--;
            fy = fy-aa2;
            p = p+fx+bb-fy;
        }
        delay(5);
    }
    setPixel(xc, yc, x, y);
    p = bb*(x+0.5)*(x+0.5)+aa*(y-1)*(y-1)-aa*bb; //set q1
    while (y > 0){
        y--;
        fy = fy-aa2;
        if (p >= 0) p = p-fy+aa;
        else{
            x++;
            fx = fx+bb2;
            p = p+fx-fy+aa;
        }
        setPixel(xc, yc, x, y);
         delay(5);
    }

}

int main()
{
    initwindow(800, 600, "The ellipse Window");
    int xc=300, yc=200, a=100, b=70;
    ellipse_midpoint(xc, yc, a, b);
    getch();
    closegraph();
}
/*
a = length of major axis
b = length of minor axis
*/

