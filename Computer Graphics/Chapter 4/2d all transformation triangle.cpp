
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;

void translation(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int tx, ty;
    cout<<"Enter the value of tx and ty: ";
    cin>>tx>>ty;
    x1 = x1+tx;
    y1 = y1+ty;
    x2 = x2+tx;
    y2 = y2+ty;
    x3 = x3+tx;
    y3 = y3+ty;

    delay(1000);
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);
    outtextxy(x2, y2+5, "Triangle after translation");
}



void scale(int x1, int y1, int x2, int y2, int x3, int y3)
{
    float sx, sy;
    int xc, yc;
    cout<<"Enter the value of scaling factors sx and sy: ";
    cin>>sx>>sy;

    xc = (x1+x2+x3)/3;
    yc = (y1+y2+y3)/3;
    circle(xc, yc, 1);
    //inverse translation
    x1 = x1 - xc;
    x2 = x2 - xc;
    x3 = x3 - xc;
    y1 = y1 - yc;
    y2 = y2 - yc;
    y3 = y3 - yc;


    x1 = x1*sx;
    y1 = y1*sy;
    x2 = x2*sx;
    y2 = y2*sy;
    x3 = x3*sx;
    y3 = y3*sy;

    x1 = x1 + xc;
    x2 = x2 + xc;
    x3 = x3 + xc;
    y1 = y1 + yc;
    y2 = y2 + yc;
    y3 = y3 + yc;

    delay(1000);
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);
    outtextxy(x3+10, y3-10, "scaled triangle");
}



void rotation(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int angle, xc, yc;
    int rx1, ry1, rx2, ry2, rx3, ry3;
    float theta;
    cout<<"Enter an angle in degree: ";
    cin>>angle;

    theta = ((float)angle*3.14)/180; //converting to radian
    xc = (x1+x2+x3)/3;
    yc = (y1+y2+y3)/3;
    //inverse translation
    x1 = x1 - xc;
    x2 = x2 - xc;
    x3 = x3 - xc;
    y1 = y1 - yc;
    y2 = y2 - yc;
    y3 = y3 - yc;

    //rotation
    rx1 =  (x1)*cos(theta) - (y1)*sin(theta);
    ry1 =  (x1)*sin(theta) + (y1)*cos(theta);
    rx2 =  (x2)*cos(theta) - (y2)*sin(theta);
    ry2 =  (x2)*sin(theta) + (y2)*cos(theta);
    rx3 =  (x3)*cos(theta) - (y3)*sin(theta);
    ry3 =  (x3)*sin(theta) + (y3)*cos(theta);

    //translation
    rx1 = rx1 + xc;
    rx2 = rx2 + xc;
    rx3 = rx3 + xc;
    ry1 = ry1 + yc;
    ry2 = ry2 + yc;
    ry3 = ry3 + yc;
    line(rx1, ry1, rx2, ry2);
    line(rx1, ry1, rx3, ry3);
    line(rx2, ry2, rx3, ry3);
    return;
}


void shearing(int x1, int y1, int x2, int y2, int x3, int y3)
{
    float a, b;
    cout<<"Enter shearing factors a and b (b=0 means shearing in x direction and a=0 means shearing in y direction): ";
    cin>>a>>b;
    int xc, yc, rx1, ry1, rx2, ry2, rx3, ry3;
    xc = (x1+x2+x3)/3;
    yc = (y1+y2+x3)/3;
    x1 = x1 - xc;
    x2 = x2 - xc;
    x3 = x3 - xc;
    y1 = y1 - yc;
    y2 = y2 - yc;
    y3 = y3 - yc;

    rx1 = x1+a*y1;
    ry1 = b*x1+y1;
    rx2 = x2+a*y2;
    ry2 = b*x2+y2;
    rx3 = x3+a*y3;
    ry3 = b*x3+y3;


    rx1 = rx1 + xc;
    rx2 = rx2 + xc;
    rx3 = rx3 + xc;
    ry1 = ry1 + yc;
    ry2 = ry2 + yc;
    ry3 = ry3 + yc;

    line(rx1, ry1, rx2, ry2);
    line(rx1, ry1, rx3, ry3);
    line(rx2, ry2, rx3, ry3);
    return;

}


void reflection(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int originx = getmaxx()/2;
    int originy = getmaxy()/2;
    line(originx, 0, originx, getmaxy());
    line(0, originy, getmaxx(), originy);

    int axis, rx1, rx2, ry1, ry2, rx3, ry3;
    cout<<"Enter your choice (1. reflection about x axis.  2. reflection about y axis): ";
    cin>>axis;
    if(axis == 1)
    {
        ry1 = y1+(originy-y1)+(originy-y1);
        ry2 = y2+(originy-y3)+(originy-y2);
        ry3 = y3+(originy-y3)+(originy-y2);
        rx1 = x1;
        rx2 = x2;
        rx3 = x3;
    }
    else if(axis == 2)
    {
        rx1 = x1+(originx-x1)+(originx-x1);
        rx2 = x2+(originx-x3)+(originx-x2);
        rx3 = x3+(originx-x3)+(originx-x2);
        ry1 = y1;
        ry2 = y2;
        ry3 = y3;
    }
    else cout<<"Error"<<endl;

    line(rx1, ry1, rx2, ry2);
    line(rx1, ry1, rx3, ry3);
    line(rx2, ry2, rx3, ry3);
}




int main()
{
    initwindow(800, 600, "The triangular transformation Window");
    int x1=200, y1=100, x2=150, y2=200, x3=250, y3=200, ch;

    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);
    cout<<"Enter Choice:\n1:Translation \n2:Scaling \n3:Rotation \n4:Shearing \n5:Reflection";
    cout<<"\nChoice :";
    cin>>ch;

    switch(ch)
        {
            case 1:
                translation(x1,y1,x2,y2,x3,y3);
                break;
            case 2:
                scale(x1,y1,x2,y2,x3,y3);
                break;
            case 3:
                rotation(x1,y1,x2,y2,x3,y3);
                break;
            case 4:
                shearing(x1,y1,x2,y2,x3,y3);
                break;
            case 5:
                reflection(x1,y1,x2,y2,x3,y3);
                break;
            default :
			    cout<<"Not a valid choice";
        }

    getch();
    closegraph();

}


