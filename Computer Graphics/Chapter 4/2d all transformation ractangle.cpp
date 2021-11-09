#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;

void translation(int x1, int y1, int x2, int y2)
{
    int tx, ty;
    cout<<"Enter the value of tx and ty: ";
    cin>>tx>>ty;
    x1 = x1+tx;
    y1 = y1+ty;
    x2 = x2+tx;
    y2 = y2+ty;

    delay(1000);
    rectangle(x1,y1, x2, y2);
    outtextxy(x1, y2+5, "Rectangle after translation");
}



void scale(int x1, int y1, int x2, int y2)
{
    float sx, sy;
    int xc, yc;
    cout<<"Enter the value of scaling factors sx and sy: ";
    cin>>sx>>sy;

    xc = (x1+x2)/2;
    yc = (y1+y2)/2;
    //inverse translation
    x1 = x1 - xc;
    x2 = x2 - xc;
    y1 = y1 - yc;
    y2 = y2 - yc;

    x1 = x1*sx;
    y1 = y1*sy;
    x2 = x2*sx;
    y2 = y2*sy;

    x1 = x1 + xc;
    x2 = x2 + xc;
    y1 = y1 + yc;
    y2 = y2 + yc;

    delay(1000);
    rectangle(x1,y1, x2, y2);
    outtextxy(x2+10, y2-10, "scaled rectangle");
}



void rotation(int x1, int y1, int x2, int y2)
{
    int angle, xc, yc, x3, y3, x4, y4;
    int rx1, ry1, rx2, ry2, rx3, ry3, rx4, ry4;
    float theta;
    cout<<"Enter an angle in degree: ";
    cin>>angle;

    theta = ((float)angle*3.14)/180; //converting to radian
    xc = (x1+x2)/2;
    yc = (y1+y2)/2;
    circle(xc, yc, 1);
    //inverse translation
    x1 = x1 - xc;
    x2 = x2 - xc;
    y1 = y1 - yc;
    y2 = y2 - yc;

    //rotation
    rx1 =  (x1)*cos(theta) - (y1)*sin(theta);
    ry1 =  (x1)*sin(theta) + (y1)*cos(theta);
    rx2 =  (x2)*cos(theta) - (y2)*sin(theta);
    ry2 =  (x2)*sin(theta) + (y2)*cos(theta);
    rx3 =  (x2)*cos(theta) - (y1)*sin(theta);
    ry3 =  (x2)*sin(theta) + (y1)*cos(theta);
    rx4 =  (x1)*cos(theta) - (y2)*sin(theta);
    ry4 =  (x1)*sin(theta) + (y2)*cos(theta);

    //translation
    rx1 = rx1 + xc;
    rx2 = rx2 + xc;
    rx3 = rx3 + xc;
    rx4 = rx4 + xc;
    ry1 = ry1 + yc;
    ry2 = ry2 + yc;
    ry3 = ry3 + yc;
    ry4 = ry4 + yc;
    line(rx1, ry1, rx3, ry3);
    line(rx2, ry2, rx4, ry4);
    line(rx3, ry3, rx2, ry2);
    line(rx4, ry4, rx1, ry1);
    return;
}


void shearing(int x1, int y1, int x2, int y2)
{
    float a, b;
    cout<<"Enter shearing factors a and b (b=0 means shearing in x direction and a=0 means shearing in y direction): ";
    cin>>a>>b;
    int xc, yc, rx1, ry1, rx2, ry2, rx3, ry3, rx4, ry4;
    xc = (x1+x2)/2;
    yc = (y1+y2)/2;

    x1 = x1 - xc;
    x2 = x2 - xc;
    y1 = y1 - yc;
    y2 = y2 - yc;

    rx1 = x1+a*y1;
    ry1 = b*x1+y1;
    rx2 = x2+a*y2;
    ry2 = b*x2+y2;
    rx3 = x2+a*y1;
    ry3 = b*x2+y1;
    rx4 = x1+a*y2;
    ry4 = b*x1+y2;

    rx1 = rx1 + xc;
    rx2 = rx2 + xc;
    rx3 = rx3 + xc;
    rx4 = rx4 + xc;
    ry1 = ry1 + yc;
    ry2 = ry2 + yc;
    ry3 = ry3 + yc;
    ry4 = ry4 + yc;

    line(rx1,ry1,rx3,ry3);
    line(rx2,ry2,rx4,ry4);
    line(rx3,ry3,rx2,ry2);
    line(rx4,ry4,rx1,ry1);
    return;

}


void reflection(int x1, int y1, int x2, int y2)
{
    int originx = getmaxx()/2;
    int originy = getmaxy()/2;
    line(originx, 0, originx, getmaxy());
    line(0, originy, getmaxx(), originy);

    int axis, rx1, rx2, ry1, ry2;
    cout<<"Enter your choice (1. reflection about x axis.  2. reflection about y axis): ";
    cin>>axis;
    if(axis == 1)
    {
        ry1 = y1+(originy-y1)+(originy-y2);
        ry2 = y2+(originy-y1)+(originy-y2);
        rx1 = x1;
        rx2 = x2;
    }
    else if(axis == 2)
    {
        rx1 = x1+(originx-x1)+(originx-x2);
        rx2 = x2+(originx-x1)+(originx-x2);
        ry1 = y1;
        ry2 = y2;
    }
    else cout<<"Error"<<endl;

    delay(1000);
    rectangle(rx1, ry1, rx2, ry2);
}




int main()
{

    int x1=200, y1=200, x2=300, y2=250, ch;
    initwindow(800, 600, "The rectangular transformation Window");
    rectangle(x1, y1, x2, y2);
    cout<<"Enter Choice:\n1:Translation \n2:Scaling \n3:Rotation \n4:Shearing \n5:Reflection";
    cout<<"\nChoice :";
    cin>>ch;

    switch(ch)
        {
            case 1:
                translation(x1,y1,x2,y2);
                break;
            case 2:
                scale(x1,y1,x2,y2);
                break;
            case 3:
                rotation(x1,y1,x2,y2);
                break;
            case 4:
                shearing(x1,y1,x2,y2);
                break;
            case 5:
                reflection(x1,y1,x2,y2);
                break;
            default :
			    cout<<"Not a valid choice";
        }

    getch();
    closegraph();
}
