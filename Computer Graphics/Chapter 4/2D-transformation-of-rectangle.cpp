#include<iostream>
#include<stdio.h>
#include<graphics.h>
using namespace std;
int main()
{
    initwindow(800, 600, "The transformation Window");

    int tx, ty; //tx = 100, ty=70
    int x1=200, y1=50, x2=400, y2=150;

    cout<<"Enter the translation coordinates(tx and ty): ";
    cin>>tx>>ty;
    rectangle(x1,y1, x2, y2);
    outtextxy(x1, y2+10, "Rectangle before translation");

    //translation
    x1 = x1+tx;
    y1 = y1+ty;
    x2 = x2+tx;
    y2 = y2+ty;

    delay(1000);
    rectangle(x1,y1, x2, y2);
    outtextxy(x1, y2+10, "Rectangle after translation");

    getch();
    closegraph();
}


