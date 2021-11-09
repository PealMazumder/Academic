#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void textAnimation(int f){
    int counter=0;
    int x=150+f,y=150+f;
    while(counter<4){
        setcolor(YELLOW);
        if(x==150+f){
            moveto(x,y);
            setcolor(RED);
            outtext("P");
            counter++;
            delay(1000);
        }
        else if(x==160+f){
            moveto(x,y);
            outtext("E");
            delay(1000);
            counter++;
        }
        else if(x==170+f){
            moveto(x,y);
            setcolor(GREEN);
            outtext("A");
            delay(100);
            counter++;
        }
        else if(x==180+f){
            moveto(x,y);
            outtext("L");
            delay(1000);
            counter++;
        }
        x++;
    }
}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm," ");
    for(int i = 10, j = 0; j<50; i+=10, j++)
    {
        cleardevice();
        if(j % 2 == 0)
            textAnimation(i+100);
        else if(j % 3 == 0) textAnimation(i-100);
        else textAnimation(i);
        delay(1000);
    }
    getch();
    closegraph();
    return 0;
}
